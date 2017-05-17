/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>
#include "ServiceClasses/alert.h"
#include "ServiceClasses/numberinput.h"
#include "ServiceClasses/positivenumberinput.h"
#include "scene.h"

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    Scene *SceneWidget;
    QLabel *label;
    QLabel *label_2;
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    PositiveNumberInput *input_Ix;
    QLabel *label_5;
    Alert *alert_Iz;
    PositiveNumberInput *input_Iy;
    QLabel *label_3;
    Alert *alert_Iy;
    QLabel *label_4;
    Alert *alert_Ix;
    PositiveNumberInput *input_Iz;
    QWidget *layoutWidget1;
    QGridLayout *gridLayout_2;
    Alert *alert_wy;
    QLabel *label_7;
    QLabel *label_8;
    Alert *alert_wx;
    Alert *alert_wz;
    NumberInput *input_wz;
    NumberInput *input_wy;
    QLabel *label_6;
    NumberInput *input_wx;
    QLabel *label_9;
    QWidget *layoutWidget2;
    QHBoxLayout *horizontalLayout;
    QPushButton *submitButton;
    QPushButton *pauseButton;
    QPushButton *stopButton;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QStringLiteral("Dialog"));
        Dialog->resize(885, 550);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Dialog->sizePolicy().hasHeightForWidth());
        Dialog->setSizePolicy(sizePolicy);
        SceneWidget = new Scene(Dialog);
        SceneWidget->setObjectName(QStringLiteral("SceneWidget"));
        SceneWidget->setGeometry(QRect(360, 10, 511, 501));
        SceneWidget->setSizeIncrement(QSize(5, 5));
        label = new QLabel(Dialog);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(11, 11, 155, 22));
        QFont font;
        font.setPointSize(12);
        label->setFont(font);
        label_2 = new QLabel(Dialog);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 180, 353, 41));
        label_2->setFont(font);
        label_2->setWordWrap(true);
        layoutWidget = new QWidget(Dialog);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(20, 40, 322, 116));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        input_Ix = new PositiveNumberInput(layoutWidget);
        input_Ix->setObjectName(QStringLiteral("input_Ix"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(input_Ix->sizePolicy().hasHeightForWidth());
        input_Ix->setSizePolicy(sizePolicy1);
        input_Ix->setAutoFillBackground(false);
        input_Ix->setClearButtonEnabled(false);

        gridLayout->addWidget(input_Ix, 0, 1, 1, 1);

        label_5 = new QLabel(layoutWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        QFont font1;
        font1.setPointSize(11);
        label_5->setFont(font1);

        gridLayout->addWidget(label_5, 2, 0, 1, 1);

        alert_Iz = new Alert(layoutWidget);
        alert_Iz->setObjectName(QStringLiteral("alert_Iz"));
        alert_Iz->setEnabled(true);
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(alert_Iz->sizePolicy().hasHeightForWidth());
        alert_Iz->setSizePolicy(sizePolicy2);
        alert_Iz->setMinimumSize(QSize(168, 34));

        gridLayout->addWidget(alert_Iz, 2, 2, 1, 1);

        input_Iy = new PositiveNumberInput(layoutWidget);
        input_Iy->setObjectName(QStringLiteral("input_Iy"));
        sizePolicy1.setHeightForWidth(input_Iy->sizePolicy().hasHeightForWidth());
        input_Iy->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(input_Iy, 1, 1, 1, 1);

        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setFont(font1);

        gridLayout->addWidget(label_3, 0, 0, 1, 1);

        alert_Iy = new Alert(layoutWidget);
        alert_Iy->setObjectName(QStringLiteral("alert_Iy"));
        alert_Iy->setEnabled(true);
        sizePolicy2.setHeightForWidth(alert_Iy->sizePolicy().hasHeightForWidth());
        alert_Iy->setSizePolicy(sizePolicy2);
        alert_Iy->setMinimumSize(QSize(168, 34));

        gridLayout->addWidget(alert_Iy, 1, 2, 1, 1);

        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setFont(font1);

        gridLayout->addWidget(label_4, 1, 0, 1, 1);

        alert_Ix = new Alert(layoutWidget);
        alert_Ix->setObjectName(QStringLiteral("alert_Ix"));
        alert_Ix->setEnabled(true);
        sizePolicy2.setHeightForWidth(alert_Ix->sizePolicy().hasHeightForWidth());
        alert_Ix->setSizePolicy(sizePolicy2);
        alert_Ix->setMinimumSize(QSize(168, 34));
        alert_Ix->setMouseTracking(true);
        alert_Ix->setStyleSheet(QStringLiteral(""));

        gridLayout->addWidget(alert_Ix, 0, 2, 1, 1);

        input_Iz = new PositiveNumberInput(layoutWidget);
        input_Iz->setObjectName(QStringLiteral("input_Iz"));
        sizePolicy1.setHeightForWidth(input_Iz->sizePolicy().hasHeightForWidth());
        input_Iz->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(input_Iz, 2, 1, 1, 1);

        layoutWidget1 = new QWidget(Dialog);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(20, 230, 239, 116));
        gridLayout_2 = new QGridLayout(layoutWidget1);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        alert_wy = new Alert(layoutWidget1);
        alert_wy->setObjectName(QStringLiteral("alert_wy"));
        alert_wy->setEnabled(true);

        gridLayout_2->addWidget(alert_wy, 1, 2, 1, 1);

        label_7 = new QLabel(layoutWidget1);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setFont(font1);

        gridLayout_2->addWidget(label_7, 1, 0, 1, 1);

        label_8 = new QLabel(layoutWidget1);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setFont(font1);

        gridLayout_2->addWidget(label_8, 2, 0, 1, 1);

        alert_wx = new Alert(layoutWidget1);
        alert_wx->setObjectName(QStringLiteral("alert_wx"));
        alert_wx->setEnabled(true);

        gridLayout_2->addWidget(alert_wx, 0, 2, 1, 1);

        alert_wz = new Alert(layoutWidget1);
        alert_wz->setObjectName(QStringLiteral("alert_wz"));
        alert_wz->setEnabled(true);

        gridLayout_2->addWidget(alert_wz, 2, 2, 1, 1);

        input_wz = new NumberInput(layoutWidget1);
        input_wz->setObjectName(QStringLiteral("input_wz"));

        gridLayout_2->addWidget(input_wz, 2, 1, 1, 1);

        input_wy = new NumberInput(layoutWidget1);
        input_wy->setObjectName(QStringLiteral("input_wy"));

        gridLayout_2->addWidget(input_wy, 1, 1, 1, 1);

        label_6 = new QLabel(layoutWidget1);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setFont(font1);

        gridLayout_2->addWidget(label_6, 0, 0, 1, 1);

        input_wx = new NumberInput(layoutWidget1);
        input_wx->setObjectName(QStringLiteral("input_wx"));

        gridLayout_2->addWidget(input_wx, 0, 1, 1, 1);

        label_9 = new QLabel(Dialog);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(21, 361, 311, 61));
        QFont font2;
        font2.setPointSize(10);
        label_9->setFont(font2);
        label_9->setWordWrap(true);
        layoutWidget2 = new QWidget(Dialog);
        layoutWidget2->setObjectName(QStringLiteral("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(21, 457, 287, 29));
        horizontalLayout = new QHBoxLayout(layoutWidget2);
        horizontalLayout->setSpacing(14);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        submitButton = new QPushButton(layoutWidget2);
        submitButton->setObjectName(QStringLiteral("submitButton"));

        horizontalLayout->addWidget(submitButton);

        pauseButton = new QPushButton(layoutWidget2);
        pauseButton->setObjectName(QStringLiteral("pauseButton"));
        pauseButton->setEnabled(false);

        horizontalLayout->addWidget(pauseButton);

        stopButton = new QPushButton(layoutWidget2);
        stopButton->setObjectName(QStringLiteral("stopButton"));
        stopButton->setEnabled(false);

        horizontalLayout->addWidget(stopButton);

        label_9->raise();
        layoutWidget->raise();
        layoutWidget->raise();
        SceneWidget->raise();
        label->raise();
        label_2->raise();
        layoutWidget->raise();
        QWidget::setTabOrder(submitButton, pauseButton);
        QWidget::setTabOrder(pauseButton, input_Ix);
        QWidget::setTabOrder(input_Ix, input_Iy);
        QWidget::setTabOrder(input_Iy, input_Iz);
        QWidget::setTabOrder(input_Iz, input_wx);
        QWidget::setTabOrder(input_wx, input_wy);
        QWidget::setTabOrder(input_wy, input_wz);

        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "\320\255\321\204\321\204\320\265\320\272\321\202 \320\224\320\266\320\260\320\275\320\270\320\261\320\265\320\272\320\276\320\262\320\260", 0));
        label->setText(QApplication::translate("Dialog", "\320\234\320\276\320\274\320\265\320\275\321\202\321\213 \320\270\320\275\320\265\321\200\321\206\320\270\320\270", 0));
        label_2->setText(QApplication::translate("Dialog", "\320\232\320\276\320\274\320\277\320\276\320\275\320\265\320\275\321\202\321\213 \320\275\320\260\321\207\320\260\320\273\321\214\320\275\320\276\320\271 <br> \321\203\320\263\320\273\320\276\320\262\320\276\320\271 \321\201\320\272\320\276\321\200\320\276\321\201\321\202\320\270", 0));
        input_Ix->setPlaceholderText(QString());
        label_5->setText(QApplication::translate("Dialog", "Z", 0));
        alert_Iz->setText(QApplication::translate("Dialog", "<html><head/><body><p><span style=\" color:#d10000;\">\320\224\320\276\320\273\320\266\320\275\320\276 \320\261\321\213\321\202\321\214 <br/>\320\275\320\265\320\276\321\202\321\200\320\270\321\206\320\260\321\202\320\265\320\273\321\214\320\275\321\213\320\274 \321\207\320\270\321\201\320\273\320\276\320\274!</span></p></body></html>", 0));
        label_3->setText(QApplication::translate("Dialog", "X", 0));
        alert_Iy->setText(QApplication::translate("Dialog", "<html><head/><body><p><span style=\" color:#d10000;\">\320\224\320\276\320\273\320\266\320\275\320\276 \320\261\321\213\321\202\321\214 <br/>\320\275\320\265\320\276\321\202\321\200\320\270\321\206\320\260\321\202\320\265\320\273\321\214\320\275\321\213\320\274 \321\207\320\270\321\201\320\273\320\276\320\274!</span></p></body></html>", 0));
        label_4->setText(QApplication::translate("Dialog", "Y", 0));
        alert_Ix->setText(QApplication::translate("Dialog", "<html><head/><body><p><span style=\" color:#d10000;\">\320\224\320\276\320\273\320\266\320\275\320\276 \320\261\321\213\321\202\321\214 <br/>\320\275\320\265\320\276\321\202\321\200\320\270\321\206\320\260\321\202\320\265\320\273\321\214\320\275\321\213\320\274 \321\207\320\270\321\201\320\273\320\276\320\274!</span></p></body></html>", 0));
        alert_wy->setText(QApplication::translate("Dialog", "<html><head/><body><p><span style=\" color:#d10000;\">\320\224\320\276\320\273\320\266\320\275\320\276 \320\261\321\213\321\202\321\214 <br/>\321\207\320\270\321\201\320\273\320\276\320\274!</span></p></body></html>", 0));
        label_7->setText(QApplication::translate("Dialog", "Y", 0));
        label_8->setText(QApplication::translate("Dialog", "Z", 0));
        alert_wx->setText(QApplication::translate("Dialog", "<html><head/><body><p><span style=\" color:#d10000;\">\320\224\320\276\320\273\320\266\320\275\320\276 \320\261\321\213\321\202\321\214 <br/>\321\207\320\270\321\201\320\273\320\276\320\274!</span></p></body></html>", 0));
        alert_wz->setText(QApplication::translate("Dialog", "<html><head/><body><p><span style=\" color:#d10000;\">\320\224\320\276\320\273\320\266\320\275\320\276 \320\261\321\213\321\202\321\214 <br/>\321\207\320\270\321\201\320\273\320\276\320\274!</span></p></body></html>", 0));
        label_6->setText(QApplication::translate("Dialog", "X", 0));
        label_9->setText(QApplication::translate("Dialog", "<html><head/><body><p>\320\241\320\272\320\276\321\200\320\276\321\201\321\202\321\214 \320\262\321\200\320\260\321\211\320\265\320\275\320\270\321\217 \321\203\320\262\320\265\320\273\320\270\321\207\320\270\320\262\320\260\320\265\321\202\321\201\321\217/\321\203\320\274\320\265\320\275\321\214\321\210\320\260\320\265\321\202\321\201\321\217 \320\275\320\260 1 \321\201\321\202\321\200\320\265\320\273\320\272\320\260\320\274\320\270 &quot;\320\222\320\262\320\265\321\200\321\205&quot;/&quot;\320\222\320\275\320\270\320\267&quot;, \320\262 2 \321\200\320\260\320\267\320\260 \321\201\321\202\321\200\320\265\320\273\320\272\320\260\320\274\320\270 &quot;\320\222\320\277\321\200\320\260\320\262\320\276&quot;/&quot;\320\222\320\273\320\265\320\262\320\276&quot;</p></body></html>", 0));
        submitButton->setText(QApplication::translate("Dialog", "\320\235\320\260\321\207\320\260\321\202\321\214", 0));
        pauseButton->setText(QApplication::translate("Dialog", "\320\237\320\260\321\203\320\267\320\260", 0));
        stopButton->setText(QApplication::translate("Dialog", "\320\241\321\202\320\276\320\277", 0));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
