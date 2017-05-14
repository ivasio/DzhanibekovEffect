#include "numberinput.h"

NumberInput::NumberInput(QWidget* parent) :
    QLineEdit (parent)
{
    connect (this, SIGNAL(textEdited(QString)), this, SLOT(validate(QString)));
}

void NumberInput::validate(QString text)
{
    bool result = true;
    text.toFloat(&result);
    if (text == "") result = true;
    emit validated(result);
}

