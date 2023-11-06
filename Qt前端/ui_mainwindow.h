/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout_2;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *le_search_1;
    QPushButton *btn_finduser;
    QPushButton *btn_add;
    QPushButton *btn_mofidy;
    QPushButton *btn_del;
    QTableWidget *tableWidget;
    QWidget *page_2;
    QGridLayout *gridLayout_4;
    QGridLayout *gridLayout_3;
    QLineEdit *le_search_2;
    QPushButton *btn_findveget;
    QTableWidget *tableWidget_2;
    QPushButton *btn_local;
    QLabel *label_4;
    QLineEdit *le_veget;
    QPushButton *btn_veget;
    QLabel *label_5;
    QLineEdit *le_stock;
    QPushButton *btn_catch;
    QLabel *label_6;
    QLineEdit *le_place;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLabel *label_3;
    QLabel *label_2;
    QPushButton *btn_exit;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(916, 692);
        MainWindow->setMinimumSize(QSize(800, 600));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout_2 = new QGridLayout(centralwidget);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        gridLayout = new QGridLayout(page);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        le_search_1 = new QLineEdit(page);
        le_search_1->setObjectName(QString::fromUtf8("le_search_1"));
        le_search_1->setMaximumSize(QSize(2000, 16777215));

        horizontalLayout_2->addWidget(le_search_1);

        btn_finduser = new QPushButton(page);
        btn_finduser->setObjectName(QString::fromUtf8("btn_finduser"));

        horizontalLayout_2->addWidget(btn_finduser);

        btn_add = new QPushButton(page);
        btn_add->setObjectName(QString::fromUtf8("btn_add"));

        horizontalLayout_2->addWidget(btn_add);

        btn_mofidy = new QPushButton(page);
        btn_mofidy->setObjectName(QString::fromUtf8("btn_mofidy"));

        horizontalLayout_2->addWidget(btn_mofidy);

        btn_del = new QPushButton(page);
        btn_del->setObjectName(QString::fromUtf8("btn_del"));

        horizontalLayout_2->addWidget(btn_del);


        gridLayout->addLayout(horizontalLayout_2, 0, 0, 1, 1);

        tableWidget = new QTableWidget(page);
        if (tableWidget->columnCount() < 7)
            tableWidget->setColumnCount(7);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        if (tableWidget->rowCount() < 1)
            tableWidget->setRowCount(1);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(0, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tableWidget->setItem(0, 0, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        tableWidget->setItem(0, 2, __qtablewidgetitem9);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setMinimumSize(QSize(600, 500));
        tableWidget->horizontalHeader()->setStretchLastSection(true);

        gridLayout->addWidget(tableWidget, 1, 0, 1, 1);

        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        gridLayout_4 = new QGridLayout(page_2);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        le_search_2 = new QLineEdit(page_2);
        le_search_2->setObjectName(QString::fromUtf8("le_search_2"));

        gridLayout_3->addWidget(le_search_2, 0, 0, 1, 1);

        btn_findveget = new QPushButton(page_2);
        btn_findveget->setObjectName(QString::fromUtf8("btn_findveget"));

        gridLayout_3->addWidget(btn_findveget, 0, 1, 1, 1);


        gridLayout_4->addLayout(gridLayout_3, 0, 0, 1, 1);

        tableWidget_2 = new QTableWidget(page_2);
        if (tableWidget_2->columnCount() < 7)
            tableWidget_2->setColumnCount(7);
        if (tableWidget_2->rowCount() < 1)
            tableWidget_2->setRowCount(1);
        tableWidget_2->setObjectName(QString::fromUtf8("tableWidget_2"));
        tableWidget_2->setMinimumSize(QSize(600, 400));
        tableWidget_2->setMaximumSize(QSize(16777215, 16777214));
        tableWidget_2->setRowCount(1);
        tableWidget_2->setColumnCount(7);
        tableWidget_2->horizontalHeader()->setProperty("showSortIndicator", QVariant(true));
        tableWidget_2->horizontalHeader()->setStretchLastSection(true);

        gridLayout_4->addWidget(tableWidget_2, 1, 0, 1, 1);

        stackedWidget->addWidget(page_2);

        gridLayout_2->addWidget(stackedWidget, 1, 0, 1, 3);

        btn_local = new QPushButton(centralwidget);
        btn_local->setObjectName(QString::fromUtf8("btn_local"));

        gridLayout_2->addWidget(btn_local, 2, 0, 1, 1);

        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout_2->addWidget(label_4, 2, 1, 1, 1);

        le_veget = new QLineEdit(centralwidget);
        le_veget->setObjectName(QString::fromUtf8("le_veget"));

        gridLayout_2->addWidget(le_veget, 2, 2, 1, 1);

        btn_veget = new QPushButton(centralwidget);
        btn_veget->setObjectName(QString::fromUtf8("btn_veget"));

        gridLayout_2->addWidget(btn_veget, 3, 0, 1, 1);

        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout_2->addWidget(label_5, 3, 1, 1, 1);

        le_stock = new QLineEdit(centralwidget);
        le_stock->setObjectName(QString::fromUtf8("le_stock"));

        gridLayout_2->addWidget(le_stock, 3, 2, 1, 1);

        btn_catch = new QPushButton(centralwidget);
        btn_catch->setObjectName(QString::fromUtf8("btn_catch"));

        gridLayout_2->addWidget(btn_catch, 4, 0, 1, 1);

        label_6 = new QLabel(centralwidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout_2->addWidget(label_6, 4, 1, 1, 1);

        le_place = new QLineEdit(centralwidget);
        le_place->setObjectName(QString::fromUtf8("le_place"));

        gridLayout_2->addWidget(le_place, 4, 2, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMaximumSize(QSize(200, 30));

        horizontalLayout->addWidget(label);

        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setMaximumSize(QSize(80, 16777215));

        horizontalLayout->addWidget(label_3);

        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setMaximumSize(QSize(100, 30));

        horizontalLayout->addWidget(label_2);

        btn_exit = new QPushButton(centralwidget);
        btn_exit->setObjectName(QString::fromUtf8("btn_exit"));
        btn_exit->setMaximumSize(QSize(80, 30));
        btn_exit->setSizeIncrement(QSize(0, 40));

        horizontalLayout->addWidget(btn_exit);


        gridLayout_2->addLayout(horizontalLayout, 0, 2, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 916, 26));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "\350\217\234\344\273\267\344\277\241\346\201\257\345\272\223", nullptr));
#if QT_CONFIG(tooltip)
        MainWindow->setToolTip(QCoreApplication::translate("MainWindow", "\350\277\231\346\230\257\350\217\234\344\273\267\344\277\241\346\201\257\345\272\223", nullptr));
#endif // QT_CONFIG(tooltip)
        btn_finduser->setText(QCoreApplication::translate("MainWindow", "\346\237\245\350\257\242\350\217\234\345\220\215", nullptr));
        btn_add->setText(QCoreApplication::translate("MainWindow", "\345\242\236\345\212\240", nullptr));
        btn_mofidy->setText(QCoreApplication::translate("MainWindow", "\344\277\256\346\224\271", nullptr));
        btn_del->setText(QCoreApplication::translate("MainWindow", "\345\210\240\351\231\244", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MainWindow", "\350\217\234\345\220\215", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MainWindow", "\347\261\273\345\236\213", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("MainWindow", "\346\234\200\344\275\216\344\273\267", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("MainWindow", "\346\234\200\351\253\230\344\273\267", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("MainWindow", "\345\271\263\345\235\207\344\273\267", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("MainWindow", "\345\215\225\344\275\215", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("MainWindow", "\346\227\245\346\234\237", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidget->verticalHeaderItem(0);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("MainWindow", "\346\226\260\345\273\272\350\241\214", nullptr));

        const bool __sortingEnabled = tableWidget->isSortingEnabled();
        tableWidget->setSortingEnabled(false);
        QTableWidgetItem *___qtablewidgetitem8 = tableWidget->item(0, 0);
        ___qtablewidgetitem8->setText(QCoreApplication::translate("MainWindow", "1", nullptr));
        QTableWidgetItem *___qtablewidgetitem9 = tableWidget->item(0, 2);
        ___qtablewidgetitem9->setText(QCoreApplication::translate("MainWindow", "2", nullptr));
        tableWidget->setSortingEnabled(__sortingEnabled);

        btn_findveget->setText(QCoreApplication::translate("MainWindow", "\346\237\245\350\257\242\350\217\234\344\273\267", nullptr));
        btn_local->setText(QCoreApplication::translate("MainWindow", "\344\273\223\345\272\223", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "\350\217\234\345\220\215", nullptr));
        btn_veget->setText(QCoreApplication::translate("MainWindow", "\350\217\234\344\273\267", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "\345\272\223\345\255\230", nullptr));
        btn_catch->setText(QCoreApplication::translate("MainWindow", "\347\210\254\345\217\226\346\225\260\346\215\256", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "\344\273\223\345\272\223", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\350\217\234\344\273\267\344\277\241\346\201\257\345\272\223", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "\347\224\250\346\210\267\345\220\215", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "rnf ma bj", nullptr));
        btn_exit->setText(QCoreApplication::translate("MainWindow", "\351\200\200\345\207\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
