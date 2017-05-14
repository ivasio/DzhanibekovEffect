#include "positivenumberinput.h"

PositiveNumberInput::PositiveNumberInput(QWidget *parent) :
    NumberInput (parent)
{

}

void PositiveNumberInput::validate(QString text)
{
    bool result = true;
    float value = text.toFloat(&result);
    if (value <= 0) result = false;
    emit validated(result);
}

