//#include <QMatrix4x4>
//#include <QMatrix3x3>
#include <QQuaternion>
#include <QDebug>

#include "scene.h"
#include "ServiceClasses/servicefunctions.cpp"
#include <cmath>

#define PI 3.14159265358979323846264338327950288419

Scene::Scene( QWidget *parent) :
    QOpenGLWidget (parent),
    timeStep (25),
    velocity (10)
{
    timer = new QTimer(parent);
    program = new QOpenGLShaderProgram (this);

    new(&fullRotation)(QQuaternion)(1, 0, 0, 0);
    setFocusPolicy(Qt::StrongFocus);
    connect (timer, SIGNAL (timeout()), this, SLOT (slotRotate()));

}

Scene::~Scene()
{
    delete body;
}


void Scene::initializeGL()
{
    glClearColor (0.1f, 0.1f, 0.2f, 1.0f);

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

    body = new Body(program, m_vertexAttr, m_colorAttr);
}


void Scene::paintGL()
{
    glClear (GL_COLOR_BUFFER_BIT);

    if (!program->bind()) {
        qWarning ("Error : Unable to bind a shader program.\n");
        return;
    }

    QMatrix4x4 matrix;
    matrix.ortho (-10, 10, -10, 10, 10, -10);
    matrix.translate(0, 0, 1);
    matrix.rotate (fullRotation);
    //QQuaternion
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
    QQuaternion rot = QQuaternion::fromAxisAndAngle(0, 0, 1, 90);
    QMatrix3x3 newMatr = rot.toRotationMatrix();
    QMatrix3x3 result = newMatr * matr;
    QMatrix3x3 newMatrT = rot.conjugate().toRotationMatrix();
    result = result * newMatrT;
    printMatrix (matr.data());printMatrix (result.data());
}


void Scene::keyPressEvent(QKeyEvent *event)
{
    switch (event->key())
    {
        case Qt::Key_Up :
            velocity += 1;
            qDebug() << "velocity " << velocity;
            break;
        case Qt::Key_Down :
            velocity -= 1;
            qDebug() << "velocity " << velocity;
            break;
        case Qt::Key_Right :
            velocity *= 2;
            qDebug() << "velocity " << velocity;
            break;
        case Qt::Key_Left :
            velocity *= 0.5;
            qDebug() << "velocity " << velocity;
            break;
        case Qt::Key_W :
            timeStep += 1;
            timer->start(this->timeStep);
            qDebug() << "timeStep " << timeStep;
            break;
        case Qt::Key_S :
            timeStep -= 1;
            timer->start(this->timeStep);
            qDebug() << "timeStep " << timeStep;
            break;
        case Qt::Key_D :
            timeStep *= 2;
            timer->start(this->timeStep);
            qDebug() << "timeStep " << timeStep;
            break;
        case Qt::Key_A :
            timeStep *= 0.5;
            timer->start(this->timeStep);
            qDebug() << "timeStep " << timeStep;
            break;
        case Qt::Key_Q :
            slotRotate();
            //testMul(body->I);
            break;
    }

}

void Scene::slotRotate()
{
    //qDebug() << (w->length())*9*velocity;//(50*PI);
    //QQuaternion rotation ((w->length())*9*velocity/(50*PI), *w);
//    QQuaternion rotation = QQuaternion::fromAxisAndAngle(*w, (w->length())*9*velocity/(50*PI));
    QQuaternion rotation = QQuaternion::fromAxisAndAngle(*w, velocity);
    fullRotation *= rotation;

    QMatrix3x3 S = rotation.toRotationMatrix();
    QMatrix3x3 SRev = rotation.conjugate().toRotationMatrix();
    S = S * body->IRev * SRev * body->I;

    float wVec[3];
    wVec[0] = w0->x(); wVec[1] = w0->y(); wVec[2] = w0->z();
    QGenericMatrix<1,3,float> wMat(wVec);
    wMat = S*wMat;

    wMat.copyDataTo (wVec);
    w = new QVector3D (wVec[0], wVec[1], wVec[2]);

    update();
}

void Scene::receiveParameters(QVector3D w_p, QVector3D I_p)
{

    w = new QVector3D (w_p.x(), w_p.y(), w_p.z());
    w0 = new QVector3D (w_p.x(), w_p.y(), w_p.z());

    body->setInertionTensor(I_p);

    timer->start(this->timeStep);
}
