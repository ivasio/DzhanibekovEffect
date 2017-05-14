#ifndef POSITIVENUMBERINPUT_H
#define POSITIVENUMBERINPUT_H

#include <QString>
#include "numberinput.h"

class PositiveNumberInput : public NumberInput
{
    Q_OBJECT

public:
    PositiveNumberInput(QWidget *parent = 0);

private slots:
    void validate(QString text);

};

#endif // POSITIVENUMBERINPUT_H
