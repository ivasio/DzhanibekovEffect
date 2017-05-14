#ifndef AXES_H
#define AXES_H
#include <vector>
#include <QQuaternion>
#include <QOpenGLShaderProgram>

class Body
{
public:
    Body(QOpenGLShaderProgram* program, int vertexAttr, int colorAttr);

    void setInertionTensor (QVector3D I_p);
    void draw ();

    QMatrix3x3 I;
    QMatrix3x3 IRev;

private:

    void initVerticles ();
    void initColors();

    std::vector<float> m_verticles;
    std::vector<float> m_colors;

    QOpenGLShaderProgram* program;

    int m_vertexAttr;
    int m_colorAttr;
};

#endif // AXES_H
