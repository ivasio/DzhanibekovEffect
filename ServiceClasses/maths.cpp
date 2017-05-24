#include "maths.h"

Maths::Maths()
{

}

void Maths::setI(QVector3D I_p)
{
	I[0] = (I_p.y() - I_p.z()) / I_p.x();
	I[1] = (I_p.z() - I_p.x()) / I_p.y();
	I[2] = (I_p.x() - I_p.y()) / I_p.z();

	//new(&I)(QVector3D)(I1, I2, I3);

}

QVector3D Maths::Euler(QVector3D w_n, float h)
{
    QVector3D f1 = f (w_n);
    return w_n + h * f1;
}

QVector3D Maths::EulerModified(QVector3D w_n, float h)
{
    QVector3D f1 = f (w_n);
    QVector3D f2 = f (w_n + h/2 * f1);
    return w_n + h/2 * (f1 + f2);
}

QVector3D Maths::RungeKutta(QVector3D w_n, float h)
{
    QVector3D f1 = f (w_n);
    QVector3D f2 = f (w_n + h/2 * f1);
    QVector3D f3 = f (w_n + h/2 * f2);
    QVector3D f4 = f (w_n + h * f1);
    return w_n + h/6 * (f1 + 2 * f2 + 2 * f3 + f4);
}

QVector3D Maths::f(QVector3D w)
{
    QVector3D w1 (w.y(), w.z(), w.x());
    QVector3D w2 (w.z(), w.x(), w.y());
    return I * w1 * w2;
}


