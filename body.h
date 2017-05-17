#ifndef AXES_H
#define AXES_H
#include <QVector3D>
#include <QQuaternion>
#include <QOpenGLShaderProgram>

class Body
{
public:
    Body(QOpenGLShaderProgram* program, int vertexAttr, int colorAttr, QVector3D I_p);

    void setInertionTensor (QVector3D I_p);
    void draw ();

    QMatrix3x3 I;
    QMatrix3x3 IRev;

private:

    void initVerticles (float a, float b, float c);

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
