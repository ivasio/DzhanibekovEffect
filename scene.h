#ifndef SCENE_H
#define SCENE_H

#include <QOpenGLWidget>
#include <QOpenGLShaderProgram>
#include <QTimer>
#include <QKeyEvent>

#include "axes.h"

class Scene : public QOpenGLWidget
{
    Q_OBJECT
public:
    Scene( QWidget *parent = 0);
    ~Scene();

private slots:
    void slotRotate();

private:
    void initializeGL();
    void paintGL();
    void resizeGL(int w, int h);

    void keyPressEvent(QKeyEvent* event);
    Axes* m_axes;
    QOpenGLShaderProgram m_program;

    int m_vertexAttr;
    int m_colorAttr;
    int m_matrixUniform;

    double m_step;
    double m_angle;
    QTimer m_timer;
};

#endif // SCENE_H
