#ifndef AXES_H
#define AXES_H
#include <vector>
#include <QQuaternion>
#include <QOpenGLShaderProgram>

class Axes
{
public:
    Axes(QOpenGLShaderProgram* program, int vertexAttr, int colorAttr,
         float A, float B, float C);

    void draw ();

    QMatrix3x3 I;
    QMatrix3x3 IRev;

private:

    void initVerticles ();
    void initColors();
    void initInertionTensors (float A, float B, float C);

    std::vector<float> m_verticles;
    std::vector<float> m_colors;

    QOpenGLShaderProgram* m_program;

    int m_vertexAttr;
    int m_colorAttr;
};

#endif // AXES_H
