#include "axes.h"

Axes::Axes (QOpenGLShaderProgram* program, int vertexAttr, int colorAttr) :
    m_program (program),
    m_vertexAttr (vertexAttr),
    m_colorAttr (colorAttr),
    m_x0 (0),
    m_y0 (0),
    m_z0 (0)

{
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

    m_verticles[0] = m_x0;
    m_verticles[1] = m_y0;
    m_verticles[2] = m_z0;

    m_verticles[3] = m_x0 + 3;
    m_verticles[4] = m_y0;
    m_verticles[5] = m_z0;

    m_verticles[6] = m_x0;
    m_verticles[7] = m_y0;
    m_verticles[8] = m_z0;

    m_verticles[9] = m_x0;
    m_verticles[10] = m_y0 + 3;
    m_verticles[11] = m_z0;

    m_verticles[12] = m_x0;
    m_verticles[13] = m_y0;
    m_verticles[14] = m_z0;

    m_verticles[15] = m_x0;
    m_verticles[16] = m_y0;
    m_verticles[17] = m_z0 + 3;



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
