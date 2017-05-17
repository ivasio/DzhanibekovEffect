#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QVector3D>


namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);


    ~Dialog();

private:
    Ui::Dialog *ui;
    void setDefaultValues();

private slots:
    void processParameters();
    void pause();
    void stop();


signals:
    void sendParameters (QVector3D w, QVector3D I);
    void sendPaused ();
    void sendStopped ();

};

#endif // DIALOG_H
