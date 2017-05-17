#include <QQuaternion>
#include <QDebug>
#include "scene.h"
#include "ServiceClasses/servicefunctions.h"
#include <cmath>
#include <QGLFormat>

Scene::Scene( QWidget *parent) :
    QOpenGLWidget (parent),
    timerPaused (false),
    timeStep (5),
    velocity (0.5),
    projectionCubeSize (5)
{
    timer = new QTimer(parent);
    program = new QOpenGLShaderProgram (this);

    new(&fullRotation)(QQuaternion)(1, 0, 0, 0);
    setFocusPolicy(Qt::StrongFocus);
    connect (timer, SIGNAL (timeout()), this, SLOT (rotate()));

}

Scene::~Scene()
{
    delete body;
}


void Scene::initializeGL()
{
    glClearColor (0.1f, 0.1f, 0.2f, 1.0f);
    glEnable (GL_DEPTH_TEST);

    QGLFormat fmt;
    fmt.setDoubleBuffer(true);
    QGLFormat::setDefaultFormat(fmt);

    QOpenGLShader vShader (QOpenGLShader::Vertex);
    vShader.compileSourceFile(":/Shaders/vShader.glsl");

    QOpenGLShader fShader (QOpenGLShader::Fragment);
    fShader.compileSourceFile(":/Shaders/fShader.glsl");

    program->addShader (&vShader);
    program->addShader (&fShader);

    if (!program->link())
    {
        qWarning ("Error : Unable to link a shader program.\n");
        return;
    }

    m_vertexAttr = program->attributeLocation("vertexAttr");
    m_colorAttr = program->attributeLocation("colorAttr");
    m_matrixUniform = program->uniformLocation("matrix");

    QVector3D I(1, 1, 1);
    body = new Body(program, m_vertexAttr, m_colorAttr, I);

}


void Scene::paintGL()
{
    glClear (GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);

    if (!program->bind()) {
        qWarning ("Error : Unable to bind a shader program.\n");
        return;
    }

    QMatrix4x4 matrix;
    matrix.ortho (-projectionCubeSize, projectionCubeSize,
                  -projectionCubeSize, projectionCubeSize,
                  projectionCubeSize, -projectionCubeSize);
    matrix.translate(0, 0, 1);
    matrix.rotate (fullRotation);

    program->setUniformValue(m_matrixUniform, matrix);

    body->draw();

    program->release();
}

void Scene::resizeGL(int w, int h)
{
    glViewport (0, 0, w, h);
}

void testMul(QMatrix3x3 matr)
{
    ServiceFunctions s;
    QQuaternion rot = QQuaternion::fromAxisAndAngle(0, 0, 1, 90);
    QMatrix3x3 newMatr = rot.toRotationMatrix();
    QMatrix3x3 result = newMatr * matr;
    QMatrix3x3 newMatrT = rot.conjugate().toRotationMatrix();
    result = result * newMatrT;
    s.printMatrix3x3 (matr.data());s.printMatrix3x3 (result.data());
}


void Scene::keyPressEvent(QKeyEvent *event)
{
    switch (event->key())
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

void Scene::rotate()
{
    ServiceFunctions s;
    QQuaternion rotation = QQuaternion::fromAxisAndAngle(*w, w->length()*velocity);
    fullRotation *= rotation;

    QMatrix3x3 S = fullRotation.toRotationMatrix();
    QMatrix3x3 SRev = fullRotation.conjugate().toRotationMatrix();

    S = body->IRev * S * body->I * SRev;

    float wVec[3];
    wVec[0] = w0->x(); wVec[1] = w0->y(); wVec[2] = w0->z();
    QGenericMatrix<3,1,float> wMat(wVec);

    wMat = wMat*S;

    wMat.copyDataTo (wVec);
    w = new QVector3D (wVec[0], wVec[1], wVec[2]);
    w->normalize();
    s.stabilize(w);
    s.stabilize(&fullRotation);

    update();
}

void Scene::pause()
{

    if (timerPaused)
    {
        timerPaused = false;
        timer->start(timeStep);
    } else
    {
        timerPaused = true;
        timer->stop();
    }
}

void Scene::stop()
{
    timerPaused = false;
    timer->stop();

    new(&fullRotation)(QQuaternion)(1, 0, 0, 0);
    update();

}

void Scene::receiveParameters(QVector3D w_p, QVector3D I_p)
{

    ServiceFunctions s;
    body = new Body(program, m_vertexAttr, m_colorAttr, I_p);
    projectionCubeSize = 1.5 * s.maxReversedMoment(&I_p);
    update();

    w = new QVector3D (w_p.x(), w_p.y(), w_p.z());
    w0 = new QVector3D (w_p.x(), w_p.y(), w_p.z());

    velocity = 0.5 * w->length();
    timer->start(timeStep);
}
