#ifndef NUMBERINPUT_H
#define NUMBERINPUT_H

#include <QLineEdit>

class NumberInput : public QLineEdit
{
    Q_OBJECT

public:
    NumberInput(QWidget *parent = 0);

signals :
    void validated (bool result);

private slots:
    virtual void validate(QString text);

};

#endif // NUMBERINPUT_H
