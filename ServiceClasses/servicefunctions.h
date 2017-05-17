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
    void stabilize (QVector3D* vec);
    void stabilize (QQuaternion* quat);

    //Body
    void setDeg (QVector3D* vec, float phi, float theta);
    void setCol (QVector3D* vec, float color);
    float maxReversedMoment (QVector3D* vec);

private:
    float precision;
};

#endif // SERVICEFUNCTIONS_H
