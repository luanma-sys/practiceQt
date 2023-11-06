/********************************************************************************
** Form generated from reading UI file 'page_login.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PAGE_LOGIN_H
#define UI_PAGE_LOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_page_login
{
public:
    QPushButton *btn_login;
    QPushButton *btn_exit;
    QLabel *label_3;
    QLineEdit *le_user;
    QLineEdit *le_password;
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QLabel *label_2;
    QLabel *label;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;

    void setupUi(QWidget *page_login)
    {
        if (page_login->objectName().isEmpty())
            page_login->setObjectName(QString::fromUtf8("page_login"));
        page_login->resize(400, 300);
        btn_login = new QPushButton(page_login);
        btn_login->setObjectName(QString::fromUtf8("btn_login"));
        btn_login->setGeometry(QRect(80, 220, 93, 28));
        btn_exit = new QPushButton(page_login);
        btn_exit->setObjectName(QString::fromUtf8("btn_exit"));
        btn_exit->setGeometry(QRect(210, 220, 93, 28));
        label_3 = new QLabel(page_login);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(150, 90, 72, 15));
        le_user = new QLineEdit(page_login);
        le_user->setObjectName(QString::fromUtf8("le_user"));
        le_user->setGeometry(QRect(180, 120, 113, 21));
        le_password = new QLineEdit(page_login);
        le_password->setObjectName(QString::fromUtf8("le_password"));
        le_password->setGeometry(QRect(180, 150, 113, 21));
        le_password->setEchoMode(QLineEdit::Password);
        layoutWidget = new QWidget(page_login);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(100, 110, 56, 71));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 0, 0, 1, 1);

        label = new QLabel(layoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 2, 0, 1, 1);

        label_4 = new QLabel(page_login);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(10, 7, 371, 16));
        label_5 = new QLabel(page_login);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(10, 30, 371, 20));
        label_6 = new QLabel(page_login);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(10, 60, 371, 18));

        retranslateUi(page_login);

        QMetaObject::connectSlotsByName(page_login);
    } // setupUi

    void retranslateUi(QWidget *page_login)
    {
        page_login->setWindowTitle(QCoreApplication::translate("page_login", "Form", nullptr));
        btn_login->setText(QCoreApplication::translate("page_login", "\347\231\273\345\275\225", nullptr));
        btn_exit->setText(QCoreApplication::translate("page_login", "\351\200\200\345\207\272", nullptr));
        label_3->setText(QCoreApplication::translate("page_login", "\347\231\273\351\231\206\347\225\214\351\235\242", nullptr));
        label_2->setText(QCoreApplication::translate("page_login", "\347\224\250\346\210\267\345\220\215", nullptr));
        label->setText(QCoreApplication::translate("page_login", "\345\257\206\347\240\201", nullptr));
        label_4->setText(QCoreApplication::translate("page_login", "\345\246\202\346\236\234python\347\210\254\350\231\253\344\270\215\350\203\275\347\224\250\357\274\214\345\205\210\347\234\213\347\234\213\347\275\221\347\253\231\346\234\211\346\262\241\346\234\211\345\217\230\343\200\202", nullptr));
        label_5->setText(QCoreApplication::translate("page_login", "\345\206\215\347\234\213\347\234\213\347\216\257\345\242\203\346\234\211\346\262\241\346\234\211\351\205\215\345\245\275\357\274\214\347\210\254\350\231\253\350\246\201\347\224\250\345\210\260debug\347\211\210", nullptr));
        label_6->setText(QCoreApplication::translate("page_login", "python\347\232\204lib\346\226\207\344\273\266\357\274\214\347\241\256\344\277\235\344\273\226\345\255\230\345\234\250\343\200\202", nullptr));
    } // retranslateUi

};

namespace Ui {
    class page_login: public Ui_page_login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PAGE_LOGIN_H
