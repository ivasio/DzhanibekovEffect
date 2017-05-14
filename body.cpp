#include "axes.h"
//#include "servicefunctions.cpp"

Axes::Axes (QOpenGLShaderProgram* program, int vertexAttr, int colorAttr,
            float A, float B, float C) :
    m_program (program),
    m_vertexAttr (vertexAttr),
    m_colorAttr (colorAttr)

{
    initInertionTensors (A, B, C);
    initVerticles();
    initColors();
}

void Axes::draw()
{
    m_program->setAttributeArray(m_vertexAttr, m_verticles.data(), 3);
    m_program->setAttributeArray(m_colorAttr, m_colors.data(), 3);

    m_program->enableAttributeArray(m_vertexAttr);
    m_program->enableAttributeArray(m_colorAttr);

    glDrawArrays( GL_LINES, 0, m_verticles.size() / 3);

    m_program->disableAttributeArray(m_vertexAttr);
    m_program->disableAttributeArray(m_colorAttr);
}

void Axes::initVerticles ()
{
    m_verticles.resize (18);

    m_verticles[0] = 0;
    m_verticles[1] = 0;
    m_verticles[2] = 0;

    m_verticles[3] = 3;
    m_verticles[4] = 0;
    m_verticles[5] = 0;

    m_verticles[6] = 0;
    m_verticles[7] = 0;
    m_verticles[8] = 0;

    m_verticles[9] = 0;
    m_verticles[10] = 3;
    m_verticles[11] = 0;

    m_verticles[12] = 0;
    m_verticles[13] = 0;
    m_verticles[14] = 0;

    m_verticles[15] = 0;
    m_verticles[16] = 0;
    m_verticles[17] = 3;



}

void Axes::initColors()
{
    m_colors.resize (18);

    m_colors[0] = 1;
    m_colors[1] = 0;
    m_colors[2] = 0;

    m_colors[3] = 1;
    m_colors[4] = 0;
    m_colors[5] = 0;

    m_colors[6] = 0;
    m_colors[7] = 1;
    m_colors[8] = 0;

    m_colors[9] = 0;
    m_colors[10] = 1;
    m_colors[11] = 0;

    m_colors[12] = 0;
    m_colors[13] = 0;
    m_colors[14] = 1;

    m_colors[15] = 0;
    m_colors[16] = 0;
    m_colors[17] = 1;
}

void Axes::initInertionTensors (float A, float B, float C)
{
    float moments[9] = {A, 0, 0, 0, B, 0, 0, 0, C};
    float momentsRev[9] = {1/A, 0, 0, 0, 1/B, 0, 0, 0, 1/C};

    //I = new QMatrix3x3 (moments);
    //IRev = new QMatrix3x3 (momentsRev);

    new(&I)(QMatrix3x3)(moments);
    new(&IRev)(QMatrix3x3)(momentsRev);

}
