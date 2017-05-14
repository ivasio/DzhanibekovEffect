#include "alert.h"
#include <QDebug>

Alert::Alert(QWidget* parent) : QLabel(parent)
{
    this->setHidden(true);
}

void Alert::hide(bool hidden)
{
    this->setHidden(hidden);
}

