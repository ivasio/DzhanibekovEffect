#ifndef AXES_H
#define AXES_H
#include <QVector3D>
#include <QQuaternion>
#include <QOpenGLShaderProgram>

class Body
{
public:
	Body(QOpenGLShaderProgram* program, int vertexAttr, int colorAttr);

    void initialize (QVector3D I_p);
    void draw ();

    QVector3D I;

private:

    void initVerticles (QVector3D size);

    QVector3D* verticles;
    QVector3D* colors;

    QOpenGLShaderProgram* program;

    int vertexAttr;
    int colorAttr;

    int parallels;
    int meridians;
    int arrSize;
};

#endif // AXES_H
