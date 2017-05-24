#include "servicefunctions.h"
#include <QDebug>
#include <cmath>

ServiceFunctions::ServiceFunctions()
{

}

void ServiceFunctions::printMatrix3x3 (float* data)
{
    qDebug ("%.4g %.4g %.4g", *(data+0), *(data+1), *(data+2));
    qDebug ("%.4g %.4g %.4g", *(data+3), *(data+4), *(data+5));
    qDebug ("%.4g %.4g %.4g", *(data+6), *(data+7), *(data+8));
    qDebug ("\n");
}

void ServiceFunctions::printMatrix3x1 (float* data)
{
    qDebug ("%.4g %.4g %.4g", *(data+0), *(data+1), *(data+2));
    qDebug ("\n");
}

void ServiceFunctions::printVector(QVector3D vec)
{
    qDebug() << vec.x() << vec.y() << vec.z();
}


//----------------------------------------------------------

#define PI 3.14159265358979323846264338327950288419
#define Sin(x) sin(PI*x/180)
#define Cos(x) cos(PI*x/180)

void ServiceFunctions::setDeg (QVector3D* vec, float phi, float theta)
{
    vec->setX(Cos(theta) * Cos(phi));
    vec->setY(Cos(theta) * Sin(phi));
    vec->setZ(Sin(theta));
}

void ServiceFunctions::setCol (QVector3D* vec, float color)
{
    vec->setX(color);
    vec->setY(color);
    vec->setZ(color);
}

float ServiceFunctions::maxReversedMoment(QVector3D *vec_p)
{
    QVector3D vec = *vec_p;
    float max = 0;

	for (int i = 0; i < 3; i++)
		if (sqrt (1 / vec[i]) >= max) max = sqrt (1 / vec[i]);

    return max;
}
