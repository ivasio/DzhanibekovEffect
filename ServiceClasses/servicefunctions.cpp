#ifndef SERVICE_FUNCTIONS
#define SERVICE_FUNCTIONS

#include <QDebug>

void printMatrix (float* data)
{
    qDebug ("%.4g %.4g %.4g", *(data+0), *(data+1), *(data+2));
    qDebug ("%.4g %.4g %.4g", *(data+3), *(data+4), *(data+5));
    qDebug ("%.4g %.4g %.4g", *(data+6), *(data+7), *(data+8));
    qDebug ("\n");
}

#endif // SERVICE_FUNCTIONS
