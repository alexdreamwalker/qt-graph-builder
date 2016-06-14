/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Thu Dec 6 22:31:59 2012
**      by: Qt User Interface Compiler version 4.8.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QCommandLinkButton>
#include <QtGui/QGraphicsView>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QSpinBox>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *readmenu;
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout_4;
    QHBoxLayout *horizontalLayout_3;
    QGraphicsView *graphicsView;
    QVBoxLayout *verticalLayout;
    QCommandLinkButton *btn_newnode;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QSpinBox *sb_from;
    QLabel *label_2;
    QSpinBox *sb_to;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_3;
    QLineEdit *le_length;
    QCheckBox *chb_isFake;
    QCommandLinkButton *btn_addrelation;
    QHBoxLayout *horizontalLayout_5;
    QCommandLinkButton *btn_delete;
    QSpinBox *sb_delete;
    QCommandLinkButton *btn_findCritical;
    QLineEdit *le_minlength;
    QCommandLinkButton *btn_makeTable;
    QCommandLinkButton *btn_makePlot;
    QMenuBar *menuBar;
    QMenu *menu;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(591, 397);
        readmenu = new QAction(MainWindow);
        readmenu->setObjectName(QString::fromUtf8("readmenu"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        horizontalLayout_4 = new QHBoxLayout(centralWidget);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        graphicsView = new QGraphicsView(centralWidget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setViewportUpdateMode(QGraphicsView::FullViewportUpdate);

        horizontalLayout_3->addWidget(graphicsView);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        btn_newnode = new QCommandLinkButton(centralWidget);
        btn_newnode->setObjectName(QString::fromUtf8("btn_newnode"));

        verticalLayout->addWidget(btn_newnode);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        sb_from = new QSpinBox(centralWidget);
        sb_from->setObjectName(QString::fromUtf8("sb_from"));

        horizontalLayout->addWidget(sb_from);

        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout->addWidget(label_2);

        sb_to = new QSpinBox(centralWidget);
        sb_to->setObjectName(QString::fromUtf8("sb_to"));

        horizontalLayout->addWidget(sb_to);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_2->addWidget(label_3);

        le_length = new QLineEdit(centralWidget);
        le_length->setObjectName(QString::fromUtf8("le_length"));

        horizontalLayout_2->addWidget(le_length);


        verticalLayout->addLayout(horizontalLayout_2);

        chb_isFake = new QCheckBox(centralWidget);
        chb_isFake->setObjectName(QString::fromUtf8("chb_isFake"));

        verticalLayout->addWidget(chb_isFake);

        btn_addrelation = new QCommandLinkButton(centralWidget);
        btn_addrelation->setObjectName(QString::fromUtf8("btn_addrelation"));

        verticalLayout->addWidget(btn_addrelation);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        btn_delete = new QCommandLinkButton(centralWidget);
        btn_delete->setObjectName(QString::fromUtf8("btn_delete"));

        horizontalLayout_5->addWidget(btn_delete);

        sb_delete = new QSpinBox(centralWidget);
        sb_delete->setObjectName(QString::fromUtf8("sb_delete"));

        horizontalLayout_5->addWidget(sb_delete);


        verticalLayout->addLayout(horizontalLayout_5);

        btn_findCritical = new QCommandLinkButton(centralWidget);
        btn_findCritical->setObjectName(QString::fromUtf8("btn_findCritical"));

        verticalLayout->addWidget(btn_findCritical);

        le_minlength = new QLineEdit(centralWidget);
        le_minlength->setObjectName(QString::fromUtf8("le_minlength"));

        verticalLayout->addWidget(le_minlength);

        btn_makeTable = new QCommandLinkButton(centralWidget);
        btn_makeTable->setObjectName(QString::fromUtf8("btn_makeTable"));

        verticalLayout->addWidget(btn_makeTable);

        btn_makePlot = new QCommandLinkButton(centralWidget);
        btn_makePlot->setObjectName(QString::fromUtf8("btn_makePlot"));

        verticalLayout->addWidget(btn_makePlot);

        verticalLayout->setStretch(1, 1);
        verticalLayout->setStretch(2, 1);
        verticalLayout->setStretch(5, 1);

        horizontalLayout_3->addLayout(verticalLayout);

        horizontalLayout_3->setStretch(0, 3);

        horizontalLayout_4->addLayout(horizontalLayout_3);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 591, 22));
        menu = new QMenu(menuBar);
        menu->setObjectName(QString::fromUtf8("menu"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menu->menuAction());
        menu->addAction(readmenu);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        readmenu->setText(QApplication::translate("MainWindow", "\320\247\321\202\320\265\320\275\320\270\320\265 \320\270\320\267 \321\202\320\260\320\261\320\273\320\270\321\206\321\213...", 0, QApplication::UnicodeUTF8));
        btn_newnode->setText(QApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \321\203\320\267\320\265\320\273", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainWindow", "\320\276\321\202:", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MainWindow", "\320\264\320\276:", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("MainWindow", "\320\264\320\273\320\270\320\275\320\260:", 0, QApplication::UnicodeUTF8));
        chb_isFake->setText(QApplication::translate("MainWindow", "\320\244\320\270\320\272\321\202\320\270\320\262\320\275\320\260\321\217", 0, QApplication::UnicodeUTF8));
        btn_addrelation->setText(QApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \321\201\320\262\321\217\320\267\321\214", 0, QApplication::UnicodeUTF8));
        btn_delete->setText(QApplication::translate("MainWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214 \321\203\320\267\320\265\320\273", 0, QApplication::UnicodeUTF8));
        btn_findCritical->setText(QApplication::translate("MainWindow", "\320\235\320\260\320\271\321\202\320\270 \320\272\321\200\320\270\321\202\320\270\321\207\320\265\321\201\320\272\320\270\320\271 \320\277\321\203\321\202\321\214", 0, QApplication::UnicodeUTF8));
        btn_makeTable->setText(QApplication::translate("MainWindow", "\320\237\320\276\321\201\321\202\321\200\320\276\320\270\321\202\321\214 \321\202\320\260\320\261\320\273\320\270\321\206\321\203", 0, QApplication::UnicodeUTF8));
        btn_makePlot->setText(QApplication::translate("MainWindow", "\320\237\320\276\321\201\321\202\321\200\320\276\320\270\321\202\321\214 \320\272\320\260\320\273\320\265\320\275\320\264\320\260\321\200\320\275\321\213\320\271 \320\263\321\200\320\260\321\204\320\270\320\272", 0, QApplication::UnicodeUTF8));
        menu->setTitle(QApplication::translate("MainWindow", "\320\234\320\265\320\275\321\216", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
