#ifndef MATHS_H
#define MATHS_H

#include <QVector3D>

class Maths
{
public:
	Maths ();
	void setI (QVector3D I_p);

    QVector3D Euler (QVector3D w_n, float h);
    QVector3D EulerModified (QVector3D w_n, float h);
    QVector3D RungeKutta (QVector3D w_n, float h);
    QVector3D f (QVector3D w_n);

private :
    QVector3D I;
};

#endif // MATHS_H
