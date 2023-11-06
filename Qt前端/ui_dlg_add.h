/********************************************************************************
** Form generated from reading UI file 'dlg_add.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DLG_ADD_H
#define UI_DLG_ADD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_dlg_add
{
public:
    QWidget *widget;
    QGridLayout *gridLayout;
    QPushButton *btn_save;
    QPushButton *btn_cancel;
    QWidget *widget_2;
    QGridLayout *gridLayout_2;
    QLineEdit *le_veg;
    QLineEdit *le_stock;
    QLineEdit *le_place;
    QWidget *widget_3;
    QGridLayout *gridLayout_3;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label;

    void setupUi(QDialog *dlg_add)
    {
        if (dlg_add->objectName().isEmpty())
            dlg_add->setObjectName(QString::fromUtf8("dlg_add"));
        dlg_add->resize(447, 352);
        widget = new QWidget(dlg_add);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(110, 290, 210, 46));
        gridLayout = new QGridLayout(widget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        btn_save = new QPushButton(widget);
        btn_save->setObjectName(QString::fromUtf8("btn_save"));

        gridLayout->addWidget(btn_save, 0, 0, 1, 1);

        btn_cancel = new QPushButton(widget);
        btn_cancel->setObjectName(QString::fromUtf8("btn_cancel"));

        gridLayout->addWidget(btn_cancel, 0, 1, 1, 1);

        widget_2 = new QWidget(dlg_add);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        widget_2->setGeometry(QRect(200, 90, 189, 111));
        gridLayout_2 = new QGridLayout(widget_2);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        le_veg = new QLineEdit(widget_2);
        le_veg->setObjectName(QString::fromUtf8("le_veg"));

        gridLayout_2->addWidget(le_veg, 0, 0, 1, 1);

        le_stock = new QLineEdit(widget_2);
        le_stock->setObjectName(QString::fromUtf8("le_stock"));

        gridLayout_2->addWidget(le_stock, 1, 0, 1, 1);

        le_place = new QLineEdit(widget_2);
        le_place->setObjectName(QString::fromUtf8("le_place"));

        gridLayout_2->addWidget(le_place, 2, 0, 1, 1);

        widget_3 = new QWidget(dlg_add);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        widget_3->setGeometry(QRect(100, 90, 78, 111));
        gridLayout_3 = new QGridLayout(widget_3);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        label_2 = new QLabel(widget_3);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_3->addWidget(label_2, 1, 0, 1, 1);

        label_3 = new QLabel(widget_3);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout_3->addWidget(label_3, 2, 0, 1, 1);

        label = new QLabel(widget_3);
        label->setObjectName(QString::fromUtf8("label"));
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_3->addWidget(label, 0, 0, 1, 1);


        retranslateUi(dlg_add);

        QMetaObject::connectSlotsByName(dlg_add);
    } // setupUi

    void retranslateUi(QDialog *dlg_add)
    {
        dlg_add->setWindowTitle(QCoreApplication::translate("dlg_add", "Dialog", nullptr));
        btn_save->setText(QCoreApplication::translate("dlg_add", "\344\277\235\345\255\230", nullptr));
        btn_cancel->setText(QCoreApplication::translate("dlg_add", "\345\217\226\346\266\210", nullptr));
        label_2->setText(QCoreApplication::translate("dlg_add", "\345\272\223\345\255\230", nullptr));
        label_3->setText(QCoreApplication::translate("dlg_add", "\344\273\223\345\272\223\345\234\260\345\235\200", nullptr));
        label->setText(QCoreApplication::translate("dlg_add", "\350\217\234\345\220\215", nullptr));
    } // retranslateUi

};

namespace Ui {
    class dlg_add: public Ui_dlg_add {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DLG_ADD_H
