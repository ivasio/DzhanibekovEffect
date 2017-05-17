#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    setDefaultValues();

    connect (ui->input_Ix, SIGNAL(validated(bool)), ui->alert_Ix, SLOT(hide(bool)));
    connect (ui->input_Iy, SIGNAL(validated(bool)), ui->alert_Iy, SLOT(hide(bool)));
    connect (ui->input_Iz, SIGNAL(validated(bool)), ui->alert_Iz, SLOT(hide(bool)));
    connect (ui->input_wx, SIGNAL(validated(bool)), ui->alert_wx, SLOT(hide(bool)));
    connect (ui->input_wy, SIGNAL(validated(bool)), ui->alert_wz, SLOT(hide(bool)));
    connect (ui->input_wz, SIGNAL(validated(bool)), ui->alert_wz, SLOT(hide(bool)));

    connect (ui->submitButton, SIGNAL(clicked()), this, SLOT(processParameters()));
    connect (this, SIGNAL(sendParameters(QVector3D,QVector3D)),
             ui->SceneWidget, SLOT(receiveParameters(QVector3D,QVector3D)));

    connect (ui->pauseButton, SIGNAL(clicked()), this, SLOT(pause()));
    connect (this, SIGNAL(sendPaused()), ui->SceneWidget, SLOT(pause()));

    connect (ui->stopButton, SIGNAL(clicked()), this, SLOT(stop()));
    connect (this, SIGNAL(sendStopped()), ui->SceneWidget, SLOT(stop()));

}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::setDefaultValues()
{
    ui->input_Ix->setText("30");
    ui->input_Iy->setText("10");
    ui->input_Iz->setText("5");
    ui->input_wx->setText("10");
    ui->input_wy->setText("0");
    ui->input_wz->setText("0");
}

void Dialog::processParameters()
{
    Alert* labelsToCheck[6] = {
        ui->alert_Ix,
        ui->alert_Iy,
        ui->alert_Iz,
        ui->alert_wx,
        ui->alert_wy,
        ui->alert_wz
    };

    bool hidden = true;
    for (int i = 0; i < 6 && hidden == true; i++)
        hidden = hidden && labelsToCheck[i]->isHidden();

    if (!hidden) return;

    QVector3D w (ui->input_wx->text().toFloat(),
                 ui->input_wy->text().toFloat(),
                 ui->input_wz->text().toFloat());

    QVector3D I (ui->input_Ix->text().toFloat(),
                 ui->input_Iy->text().toFloat(),
                 ui->input_Iz->text().toFloat());

    ui->pauseButton->setEnabled(true);
    ui->stopButton->setEnabled(true);
    ui->submitButton->setEnabled(false);


    emit sendParameters(w, I);
}

void Dialog::pause()
{
    ui->SceneWidget->timerPaused ?
                ui->pauseButton->setText("Пауза") :
                ui->pauseButton->setText("Продолжить");

    emit sendPaused();
}

void Dialog::stop()
{
    ui->pauseButton->setText("Пауза");
    ui->pauseButton->setEnabled(false);
    ui->stopButton->setEnabled(false);
    ui->submitButton->setEnabled(true);

    emit sendStopped();
}
