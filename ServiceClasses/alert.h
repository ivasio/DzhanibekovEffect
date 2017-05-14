#ifndef ALERT_H
#define ALERT_H

#include <QLabel>

class Alert : public QLabel
{
    Q_OBJECT

public:
    Alert(QWidget *parent = 0);

public slots:
    void hide (bool hidden);

};

#endif // ALERT_H
