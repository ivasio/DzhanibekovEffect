#include "body.h"
#include "ServiceClasses/servicefunctions.h"
#include <cmath>

Body::Body (QOpenGLShaderProgram* program_p, int vertexAttr_p, int colorAttr_p, QVector3D I_p) :
    program (program_p),
    vertexAttr (vertexAttr_p),
    colorAttr (colorAttr_p),
    parallels (100),//100
    meridians (180)//180
{
    arrSize = (parallels-1) * (meridians+1) * 2 + 2 * (meridians+2);
    colors = new QVector3D[arrSize];
    verticles = new QVector3D[arrSize];

    setInertionTensor(I_p);
    initVerticles(I_p.x(), I_p.y(), I_p.z());

}

void Body::draw()
{
    program->setAttributeArray(vertexAttr, verticles);
    program->setAttributeArray(colorAttr, colors);

    program->enableAttributeArray(vertexAttr);
    program->enableAttributeArray(colorAttr);

    glDrawArrays( GL_TRIANGLE_FAN, meridians + 2, meridians + 2);
    glDrawArrays( GL_TRIANGLE_FAN, 0, meridians + 2);

    int i0 = 2*meridians + 4;
    for (int i = 0; i < parallels - 1; i++) // номер параллели верхней границы полосы
        glDrawArrays(GL_QUAD_STRIP, i0 + i*(2*(meridians+1)), 2*(meridians+1));

    program->disableAttributeArray(vertexAttr);
    program->disableAttributeArray(colorAttr);
}

void Body::initVerticles (float a, float b, float c)
{

    ServiceFunctions s;
    float d_phi = 360.0 / meridians;
    float d_theta = 180.0 / (parallels + 1.0);
    float d_color = 1.0 / (parallels - 1.0);

    s.setDeg(&verticles[0], 0, 90);
    s.setCol(&colors[0], 1);

    s.setDeg(&verticles[meridians+2], 0, -90);
    s.setCol(&colors[meridians+2], 0);

    for (int i = 0; i<= meridians; i++)
    {
        s.setDeg (&verticles[i+1], i*d_phi, 90 - d_theta);
        s.setCol(&colors[i+1], 1);

        s.setDeg (&verticles[i+meridians+3], 360-i*d_phi, -90 + d_theta);
        s.setCol(&colors[i+meridians+3], 0);
    }

    int i0 = 2*meridians + 4;
    for (int i = 0; i < parallels - 1; i++) // номер параллели верхней границы полосы
    {
        for (int j = 0; j <= meridians; j++) // номер меридиана границы клетки
        {
            s.setDeg (&verticles[i0 + 2*((meridians+1)*i + j)], j*d_phi, 90-(i+1)*d_theta);
            s.setCol (&colors[i0 + 2*((meridians+1)*i + j)], 1.0 - i*d_color);
            s.setDeg (&verticles[i0 + 2*((meridians+1)*i + j) + 1], j*d_phi, 90-(i+2)*d_theta);
            s.setCol (&colors[i0 + 2*((meridians+1)*i + j) + 1], 1.0 - (i)*d_color);
        }

    }

    for (int i = 0; i < arrSize; i++)
    {
        verticles[i].setX (verticles[i].x() * a);
        verticles[i].setY (verticles[i].y() * b);
        verticles[i].setZ (verticles[i].z() * c);
    }

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
