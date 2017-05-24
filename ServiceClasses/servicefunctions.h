#ifndef SERVICEFUNCTIONS_H
#define SERVICEFUNCTIONS_H

#include <QVector3D>
#include <QQuaternion>

class ServiceFunctions
{
public:
    ServiceFunctions();

    //Scene
    void printMatrix3x3 (float* data);
    void printMatrix3x1 (float* data);
    void printVector (QVector3D vec);
    float maxReversedMoment (QVector3D* vec);

    //Body
    void setDeg (QVector3D* vec, float phi, float theta);
    void setCol (QVector3D* vec, float color);

private:

};

#endif // SERVICEFUNCTIONS_H
