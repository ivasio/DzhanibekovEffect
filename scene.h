#ifndef SCENE_H
#define SCENE_H

#include <QOpenGLWidget>
#include <QOpenGLShaderProgram>
#include <QTimer>
#include <QQuaternion>
#include <QKeyEvent>

#include "body.h"

class Scene : public QOpenGLWidget
{
    Q_OBJECT

public:
    Scene( QWidget *parent);
    ~Scene();

    bool timerPaused;

private slots:
    void rotate();
    void pause();
    void stop();
    void receiveParameters (QVector3D w, QVector3D I);

private:
    void initializeGL();
    void paintGL();
    void resizeGL(int w, int h);

    void keyPressEvent(QKeyEvent* event);
    Body* body;

    QOpenGLShaderProgram* program;
    int m_vertexAttr;
    int m_colorAttr;
    int m_matrixUniform;

    QTimer* timer;
    float timeStep;
    float velocity;

    QQuaternion fullRotation;
    QVector3D* w;
    QVector3D* w0;
    float projectionCubeSize;

};

#endif // SCENE_H
