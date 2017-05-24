#include <cmath>

#include <QQuaternion>
#include <QDebug>
#include <QGLFormat>

#include "scene.h"
#include "ServiceClasses/servicefunctions.h"
#include "ServiceClasses/maths.h"


Scene::Scene (QWidget *parent) :
	QOpenGLWidget (parent),
	timerPaused (false),
	timeStep (5),
	velocity (0.5)
{
	timer = new QTimer (parent);
	program = new QOpenGLShaderProgram (this);
	m = new Maths ();

	new (&fullRotation)(QQuaternion)(1, 0, 0, 0);
	connect (timer, SIGNAL (timeout ()), this, SLOT (rotate ()));
}

Scene::~Scene ()
{
	delete body;
}

void Scene::initializeI (QVector3D I_p)
{
	I = I_p;
	ServiceFunctions s;
	projectionCubeSize = 2 * s.maxReversedMoment (&I_p);
	update ();
}


void Scene::initializeGL()
{
	glClearColor (0.1f, 0.1f, 0.2f, 1.0f);
	glEnable (GL_DEPTH_TEST);

	QGLFormat fmt;
	fmt.setDoubleBuffer (true);
	QGLFormat::setDefaultFormat (fmt);

	QOpenGLShader vShader (QOpenGLShader::Vertex);
	vShader.compileSourceFile (":/Shaders/vShader.glsl");

	QOpenGLShader fShader (QOpenGLShader::Fragment);
	fShader.compileSourceFile (":/Shaders/fShader.glsl");

	program->addShader (&vShader);
	program->addShader (&fShader);

	if (!program->link ())
	{
		qWarning ("Error : Unable to link a shader program.\n");
		return;
	}

	m_vertexAttr = program->attributeLocation ("vertexAttr");
	m_colorAttr = program->attributeLocation ("colorAttr");
	m_matrixUniform = program->uniformLocation ("matrix");

	body = new Body (program, m_vertexAttr, m_colorAttr);
	body->initialize (I);

}


void Scene::paintGL()
{
	glClear (GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);

	if (!program->bind ()) {
		qWarning ("Error : Unable to bind a shader program.\n");
		return;
	}

	QMatrix4x4 matrix;
	matrix.ortho (-projectionCubeSize, projectionCubeSize,
				  -projectionCubeSize, projectionCubeSize,
				  projectionCubeSize, -projectionCubeSize);
	matrix.rotate (fullRotation);

	program->setUniformValue (m_matrixUniform, matrix);
	body->draw ();
	program->release ();
}

void Scene::resizeGL(int w, int h)
{
	glViewport (0, 0, w, h);
}

void Scene::keyPressEvent (QKeyEvent *event)
{
	switch (event->key ())
	{
		case Qt::Key_Up :
			velocity += 1;
			break;
		case Qt::Key_Down :
			velocity -= 1;
			break;
		case Qt::Key_Right :
			velocity *= 2;
			break;
		case Qt::Key_Left :
			velocity *= 0.5;
			break;
	}

}

void Scene::rotate ()
{

	QQuaternion rotation = QQuaternion::fromAxisAndAngle (w, velocity);
	fullRotation = rotation * fullRotation;

//    w = m->Euler (w, timeStep * 0.001 * velocity);
//    w = m->EulerModified (w, timeStep * 0.001 * velocity);
	w = m->RungeKutta (w, timeStep * 0.001 * velocity);
	w.normalize ();

	update ();
}

void Scene::pause ()
{

	if (timerPaused)
	{
		timerPaused = false;
		timer->start (timeStep);
	} else
	{
		timerPaused = true;
		timer->stop ();
	}
}

void Scene::stop ()
{
	timerPaused = false;
	timer->stop ();

	new (&fullRotation)(QQuaternion)(1, 0, 0, 0);
/*  QQuaternion temp;
	fullRotation = temp; */
	update ();

}

void Scene::receiveParameters (QVector3D w_p, QVector3D I_p)
{

	ServiceFunctions s;

	body->initialize (I_p);
	m->setI (I_p);
	projectionCubeSize = 2 * s.maxReversedMoment (&I_p);
	update ();

	w = w_p;
	velocity = 0.5 * w.length ();
	w.normalize ();

	timer->start (timeStep);
	setFocusPolicy (Qt::StrongFocus);
	setFocus ();
}
