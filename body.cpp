#include "body.h"
//#include "servicefunctions.cpp"

Body::Body (QOpenGLShaderProgram* program_p, int vertexAttr, int colorAttr) :
    program (program_p),
    m_vertexAttr (vertexAttr),
    m_colorAttr (colorAttr)

{
    initVerticles();
    initColors();
}

void Body::draw()
{
    program->setAttributeArray(m_vertexAttr, m_verticles.data(), 3);
    program->setAttributeArray(m_colorAttr, m_colors.data(), 3);

    program->enableAttributeArray(m_vertexAttr);
    program->enableAttributeArray(m_colorAttr);

    glDrawArrays( GL_LINES, 0, m_verticles.size() / 3);

    program->disableAttributeArray(m_vertexAttr);
    program->disableAttributeArray(m_colorAttr);
}

void Body::initVerticles ()
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

void Body::initColors()
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

void Body::setInertionTensor (QVector3D I_p)
{
    float moments[9] = {I_p.x(), 0, 0,
                        0, I_p.y(), 0,
                        0, 0, I_p.z()};

    float momentsRev[9] = {1/I_p.x(), 0, 0,
                           0, 1/I_p.y(), 0,
                           0, 0, 1/I_p.z()};

    new(&I)(QMatrix3x3)(moments);
    new(&IRev)(QMatrix3x3)(momentsRev);

}
