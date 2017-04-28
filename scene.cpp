#include <QMatrix4x4>
//#include <QDebug>

#include "scene.h"

Scene::Scene( QWidget *parent ) :
    QOpenGLWidget (parent),
    m_step (1),
    m_angle (0)
{
    this->setFocusPolicy(Qt::StrongFocus);

    connect (&m_timer, SIGNAL (timeout()), this, SLOT (slotRotate()));
    m_timer.start(5);
}

Scene::~Scene()
{
    delete m_axes;
}


void Scene::initializeGL()
{
    glClearColor (0.1f, 0.1f, 0.2f, 1.0f);

    QOpenGLShader vShader (QOpenGLShader::Vertex);
    vShader.compileSourceFile(":/Shaders/vShader.glsl");

    QOpenGLShader fShader (QOpenGLShader::Fragment);
    fShader.compileSourceFile(":/Shaders/fShader.glsl");

    m_program.addShader (&vShader);
    m_program.addShader (&fShader);

    if (!m_program.link())
    {
        qWarning ("Error : Unable to link a shader program.\n");
        return;
    }

    m_vertexAttr = m_program.attributeLocation("vertexAttr");
    m_colorAttr = m_program.attributeLocation("colorAttr");
    m_matrixUniform = m_program.uniformLocation("matrix");

    m_axes = new Axes(&m_program, m_vertexAttr, m_colorAttr);
}


void Scene::paintGL()
{
    glClear (GL_COLOR_BUFFER_BIT);

    if (!m_program.bind())
        return;

    QMatrix4x4 matrix;
    matrix.ortho (-10, 10, -10, 10, 10, -10);
    matrix.translate(0, 0, 1);
    matrix.rotate (m_angle, 1, 1, 1);
    //QQuaternion
    m_program.setUniformValue(m_matrixUniform, matrix);

    m_axes->draw();

    m_program.release();
}

void Scene::resizeGL(int w, int h)
{
    glViewport (0, 0, w, h);
}

void Scene::keyPressEvent(QKeyEvent *event)
{
    switch (event->key())
    {
        case Qt::Key_Up :
            m_step += 1;
            break;
        case Qt::Key_Down :
            m_step -= 1;
            break;
    }

}

void Scene::slotRotate()
{
    m_angle += m_step;

    if (m_angle > 360) m_angle -= 360;

    update();
}
