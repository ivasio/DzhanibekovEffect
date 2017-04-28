#ifndef AXES_H
#define AXES_H

#include <vector>
#include <QOpenGLShaderProgram>

class Axes
{
public:
    Axes(QOpenGLShaderProgram* program, int vertexAttr, int colorAttr);

    void draw ();

private:
    void initVerticles ();
    void initColors();

    std::vector<float> m_verticles;
    std::vector<float> m_colors;

    QOpenGLShaderProgram* m_program;

    int m_vertexAttr;
    int m_colorAttr;

    double m_x0;
    double m_y0;
    double m_z0;

};

#endif // AXES_H
