/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionEinlesen;
    QAction *actionEinlesen_2;
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_8;
    QSplitter *splitter;
    QGroupBox *groupBoxBuchungen;
    QHBoxLayout *horizontalLayout;
    QListWidget *listWidget;
    QTabWidget *tabWidget;
    QWidget *tabFlugbuchung;
    QFormLayout *formLayout;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_4;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_8;
    QLabel *label_7;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QVBoxLayout *verticalLayout;
    QLineEdit *lineEditIdFlug;
    QDateEdit *dateEditAbflugFlug;
    QDateEdit *dateEditAnkuftFlug;
    QLineEdit *lineEditFluglinieFlug;
    QLineEdit *lineEditKlasseFlug;
    QLineEdit *lineEditVonFlug;
    QLineEdit *lineEditNachFlug;
    QDoubleSpinBox *doubleSpinBoxPreisFlug;
    QWidget *tabMietwagenreservierung;
    QFormLayout *formLayout_3;
    QHBoxLayout *horizontalLayout_4;
    QVBoxLayout *verticalLayout_6;
    QLabel *label_16;
    QLabel *label_17;
    QLabel *label_18;
    QLabel *label_22;
    QLabel *label_19;
    QLabel *label_20;
    QLabel *label_23;
    QLabel *label_21;
    QVBoxLayout *verticalLayout_3;
    QLineEdit *lineEditIdMietwagen;
    QDateEdit *dateEditVonMietwagen;
    QDateEdit *dateEditBisMietwagen;
    QLineEdit *lineEditFirmaMietwageb;
    QLineEdit *lineEditAbholortMietwagen;
    QLineEdit *lineEditAbgabeortMietwagen;
    QLineEdit *lineEditKlasseMietwagen;
    QDoubleSpinBox *doubleSpinBoxPreisMietwagen;
    QWidget *tabHotelbuchung;
    QFormLayout *formLayout_2;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *label_12;
    QLabel *label_13;
    QLabel *label_15;
    QLabel *label_14;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *lineEditIdHotel;
    QDateEdit *dateAnkunftHotel;
    QDateEdit *dateEditAbreiseHotel;
    QLineEdit *lineEditHotelHotel;
    QLineEdit *lineEditSTadtHotel;
    QLineEdit *lineEditZimmerHotel;
    QDoubleSpinBox *doubleSpinBoxPreisHotel;
    QStatusBar *statusbar;
    QMenuBar *menubar;
    QMenu *menuDatei;
    QMenu *menuBuchung;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        actionEinlesen = new QAction(MainWindow);
        actionEinlesen->setObjectName("actionEinlesen");
        actionEinlesen_2 = new QAction(MainWindow);
        actionEinlesen_2->setObjectName("actionEinlesen_2");
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayout_8 = new QVBoxLayout(centralwidget);
        verticalLayout_8->setObjectName("verticalLayout_8");
        splitter = new QSplitter(centralwidget);
        splitter->setObjectName("splitter");
        splitter->setOrientation(Qt::Horizontal);
        groupBoxBuchungen = new QGroupBox(splitter);
        groupBoxBuchungen->setObjectName("groupBoxBuchungen");
        horizontalLayout = new QHBoxLayout(groupBoxBuchungen);
        horizontalLayout->setObjectName("horizontalLayout");
        listWidget = new QListWidget(groupBoxBuchungen);
        listWidget->setObjectName("listWidget");

        horizontalLayout->addWidget(listWidget);

        splitter->addWidget(groupBoxBuchungen);
        tabWidget = new QTabWidget(splitter);
        tabWidget->setObjectName("tabWidget");
        tabFlugbuchung = new QWidget();
        tabFlugbuchung->setObjectName("tabFlugbuchung");
        formLayout = new QFormLayout(tabFlugbuchung);
        formLayout->setObjectName("formLayout");
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName("verticalLayout_4");
        label = new QLabel(tabFlugbuchung);
        label->setObjectName("label");

        verticalLayout_4->addWidget(label);

        label_2 = new QLabel(tabFlugbuchung);
        label_2->setObjectName("label_2");

        verticalLayout_4->addWidget(label_2);

        label_3 = new QLabel(tabFlugbuchung);
        label_3->setObjectName("label_3");

        verticalLayout_4->addWidget(label_3);

        label_8 = new QLabel(tabFlugbuchung);
        label_8->setObjectName("label_8");

        verticalLayout_4->addWidget(label_8);

        label_7 = new QLabel(tabFlugbuchung);
        label_7->setObjectName("label_7");

        verticalLayout_4->addWidget(label_7);

        label_4 = new QLabel(tabFlugbuchung);
        label_4->setObjectName("label_4");

        verticalLayout_4->addWidget(label_4);

        label_5 = new QLabel(tabFlugbuchung);
        label_5->setObjectName("label_5");

        verticalLayout_4->addWidget(label_5);

        label_6 = new QLabel(tabFlugbuchung);
        label_6->setObjectName("label_6");

        verticalLayout_4->addWidget(label_6);


        horizontalLayout_2->addLayout(verticalLayout_4);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        lineEditIdFlug = new QLineEdit(tabFlugbuchung);
        lineEditIdFlug->setObjectName("lineEditIdFlug");

        verticalLayout->addWidget(lineEditIdFlug);

        dateEditAbflugFlug = new QDateEdit(tabFlugbuchung);
        dateEditAbflugFlug->setObjectName("dateEditAbflugFlug");
        dateEditAbflugFlug->setCalendarPopup(true);

        verticalLayout->addWidget(dateEditAbflugFlug);

        dateEditAnkuftFlug = new QDateEdit(tabFlugbuchung);
        dateEditAnkuftFlug->setObjectName("dateEditAnkuftFlug");

        verticalLayout->addWidget(dateEditAnkuftFlug);

        lineEditFluglinieFlug = new QLineEdit(tabFlugbuchung);
        lineEditFluglinieFlug->setObjectName("lineEditFluglinieFlug");

        verticalLayout->addWidget(lineEditFluglinieFlug);

        lineEditKlasseFlug = new QLineEdit(tabFlugbuchung);
        lineEditKlasseFlug->setObjectName("lineEditKlasseFlug");

        verticalLayout->addWidget(lineEditKlasseFlug);

        lineEditVonFlug = new QLineEdit(tabFlugbuchung);
        lineEditVonFlug->setObjectName("lineEditVonFlug");

        verticalLayout->addWidget(lineEditVonFlug);

        lineEditNachFlug = new QLineEdit(tabFlugbuchung);
        lineEditNachFlug->setObjectName("lineEditNachFlug");

        verticalLayout->addWidget(lineEditNachFlug);

        doubleSpinBoxPreisFlug = new QDoubleSpinBox(tabFlugbuchung);
        doubleSpinBoxPreisFlug->setObjectName("doubleSpinBoxPreisFlug");
        doubleSpinBoxPreisFlug->setMaximum(9999.989999999999782);

        verticalLayout->addWidget(doubleSpinBoxPreisFlug);


        horizontalLayout_2->addLayout(verticalLayout);


        formLayout->setLayout(0, QFormLayout::SpanningRole, horizontalLayout_2);

        tabWidget->addTab(tabFlugbuchung, QString());
        tabMietwagenreservierung = new QWidget();
        tabMietwagenreservierung->setObjectName("tabMietwagenreservierung");
        formLayout_3 = new QFormLayout(tabMietwagenreservierung);
        formLayout_3->setObjectName("formLayout_3");
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName("verticalLayout_6");
        label_16 = new QLabel(tabMietwagenreservierung);
        label_16->setObjectName("label_16");

        verticalLayout_6->addWidget(label_16);

        label_17 = new QLabel(tabMietwagenreservierung);
        label_17->setObjectName("label_17");

        verticalLayout_6->addWidget(label_17);

        label_18 = new QLabel(tabMietwagenreservierung);
        label_18->setObjectName("label_18");

        verticalLayout_6->addWidget(label_18);

        label_22 = new QLabel(tabMietwagenreservierung);
        label_22->setObjectName("label_22");

        verticalLayout_6->addWidget(label_22);

        label_19 = new QLabel(tabMietwagenreservierung);
        label_19->setObjectName("label_19");

        verticalLayout_6->addWidget(label_19);

        label_20 = new QLabel(tabMietwagenreservierung);
        label_20->setObjectName("label_20");

        verticalLayout_6->addWidget(label_20);

        label_23 = new QLabel(tabMietwagenreservierung);
        label_23->setObjectName("label_23");

        verticalLayout_6->addWidget(label_23);

        label_21 = new QLabel(tabMietwagenreservierung);
        label_21->setObjectName("label_21");

        verticalLayout_6->addWidget(label_21);


        horizontalLayout_4->addLayout(verticalLayout_6);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName("verticalLayout_3");
        lineEditIdMietwagen = new QLineEdit(tabMietwagenreservierung);
        lineEditIdMietwagen->setObjectName("lineEditIdMietwagen");

        verticalLayout_3->addWidget(lineEditIdMietwagen);

        dateEditVonMietwagen = new QDateEdit(tabMietwagenreservierung);
        dateEditVonMietwagen->setObjectName("dateEditVonMietwagen");

        verticalLayout_3->addWidget(dateEditVonMietwagen);

        dateEditBisMietwagen = new QDateEdit(tabMietwagenreservierung);
        dateEditBisMietwagen->setObjectName("dateEditBisMietwagen");

        verticalLayout_3->addWidget(dateEditBisMietwagen);

        lineEditFirmaMietwageb = new QLineEdit(tabMietwagenreservierung);
        lineEditFirmaMietwageb->setObjectName("lineEditFirmaMietwageb");

        verticalLayout_3->addWidget(lineEditFirmaMietwageb);

        lineEditAbholortMietwagen = new QLineEdit(tabMietwagenreservierung);
        lineEditAbholortMietwagen->setObjectName("lineEditAbholortMietwagen");

        verticalLayout_3->addWidget(lineEditAbholortMietwagen);

        lineEditAbgabeortMietwagen = new QLineEdit(tabMietwagenreservierung);
        lineEditAbgabeortMietwagen->setObjectName("lineEditAbgabeortMietwagen");

        verticalLayout_3->addWidget(lineEditAbgabeortMietwagen);

        lineEditKlasseMietwagen = new QLineEdit(tabMietwagenreservierung);
        lineEditKlasseMietwagen->setObjectName("lineEditKlasseMietwagen");

        verticalLayout_3->addWidget(lineEditKlasseMietwagen);

        doubleSpinBoxPreisMietwagen = new QDoubleSpinBox(tabMietwagenreservierung);
        doubleSpinBoxPreisMietwagen->setObjectName("doubleSpinBoxPreisMietwagen");
        doubleSpinBoxPreisMietwagen->setMaximum(9999.989999999999782);

        verticalLayout_3->addWidget(doubleSpinBoxPreisMietwagen);


        horizontalLayout_4->addLayout(verticalLayout_3);


        formLayout_3->setLayout(0, QFormLayout::SpanningRole, horizontalLayout_4);

        tabWidget->addTab(tabMietwagenreservierung, QString());
        tabHotelbuchung = new QWidget();
        tabHotelbuchung->setObjectName("tabHotelbuchung");
        formLayout_2 = new QFormLayout(tabHotelbuchung);
        formLayout_2->setObjectName("formLayout_2");
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName("verticalLayout_5");
        label_9 = new QLabel(tabHotelbuchung);
        label_9->setObjectName("label_9");

        verticalLayout_5->addWidget(label_9);

        label_10 = new QLabel(tabHotelbuchung);
        label_10->setObjectName("label_10");

        verticalLayout_5->addWidget(label_10);

        label_11 = new QLabel(tabHotelbuchung);
        label_11->setObjectName("label_11");

        verticalLayout_5->addWidget(label_11);

        label_12 = new QLabel(tabHotelbuchung);
        label_12->setObjectName("label_12");

        verticalLayout_5->addWidget(label_12);

        label_13 = new QLabel(tabHotelbuchung);
        label_13->setObjectName("label_13");

        verticalLayout_5->addWidget(label_13);

        label_15 = new QLabel(tabHotelbuchung);
        label_15->setObjectName("label_15");

        verticalLayout_5->addWidget(label_15);

        label_14 = new QLabel(tabHotelbuchung);
        label_14->setObjectName("label_14");

        verticalLayout_5->addWidget(label_14);


        horizontalLayout_3->addLayout(verticalLayout_5);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        lineEditIdHotel = new QLineEdit(tabHotelbuchung);
        lineEditIdHotel->setObjectName("lineEditIdHotel");

        verticalLayout_2->addWidget(lineEditIdHotel);

        dateAnkunftHotel = new QDateEdit(tabHotelbuchung);
        dateAnkunftHotel->setObjectName("dateAnkunftHotel");

        verticalLayout_2->addWidget(dateAnkunftHotel);

        dateEditAbreiseHotel = new QDateEdit(tabHotelbuchung);
        dateEditAbreiseHotel->setObjectName("dateEditAbreiseHotel");

        verticalLayout_2->addWidget(dateEditAbreiseHotel);

        lineEditHotelHotel = new QLineEdit(tabHotelbuchung);
        lineEditHotelHotel->setObjectName("lineEditHotelHotel");

        verticalLayout_2->addWidget(lineEditHotelHotel);

        lineEditSTadtHotel = new QLineEdit(tabHotelbuchung);
        lineEditSTadtHotel->setObjectName("lineEditSTadtHotel");

        verticalLayout_2->addWidget(lineEditSTadtHotel);

        lineEditZimmerHotel = new QLineEdit(tabHotelbuchung);
        lineEditZimmerHotel->setObjectName("lineEditZimmerHotel");

        verticalLayout_2->addWidget(lineEditZimmerHotel);

        doubleSpinBoxPreisHotel = new QDoubleSpinBox(tabHotelbuchung);
        doubleSpinBoxPreisHotel->setObjectName("doubleSpinBoxPreisHotel");
        doubleSpinBoxPreisHotel->setMaximum(9999.989999999999782);

        verticalLayout_2->addWidget(doubleSpinBoxPreisHotel);


        horizontalLayout_3->addLayout(verticalLayout_2);


        formLayout_2->setLayout(0, QFormLayout::SpanningRole, horizontalLayout_3);

        tabWidget->addTab(tabHotelbuchung, QString());
        splitter->addWidget(tabWidget);

        verticalLayout_8->addWidget(splitter);

        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 17));
        menuDatei = new QMenu(menubar);
        menuDatei->setObjectName("menuDatei");
        menuBuchung = new QMenu(menubar);
        menuBuchung->setObjectName("menuBuchung");
        MainWindow->setMenuBar(menubar);

        menubar->addAction(menuDatei->menuAction());
        menubar->addAction(menuBuchung->menuAction());
        menuDatei->addAction(actionEinlesen_2);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionEinlesen->setText(QCoreApplication::translate("MainWindow", "Einlesen", nullptr));
        actionEinlesen_2->setText(QCoreApplication::translate("MainWindow", "Einlesen", nullptr));
        groupBoxBuchungen->setTitle(QString());
        label->setText(QCoreApplication::translate("MainWindow", "Id", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Abflugdatum", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Ankuftsdatum", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "Fluglinie", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "Klasse", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Von", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Nach", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "Preis", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabFlugbuchung), QCoreApplication::translate("MainWindow", "Flugbuchung", nullptr));
        label_16->setText(QCoreApplication::translate("MainWindow", "Id", nullptr));
        label_17->setText(QCoreApplication::translate("MainWindow", "Von", nullptr));
        label_18->setText(QCoreApplication::translate("MainWindow", "Bis", nullptr));
        label_22->setText(QCoreApplication::translate("MainWindow", "Firma", nullptr));
        label_19->setText(QCoreApplication::translate("MainWindow", "Abholort", nullptr));
        label_20->setText(QCoreApplication::translate("MainWindow", "Abgabeort", nullptr));
        label_23->setText(QCoreApplication::translate("MainWindow", "Klasse", nullptr));
        label_21->setText(QCoreApplication::translate("MainWindow", "Preis", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabMietwagenreservierung), QCoreApplication::translate("MainWindow", "Mietwagenreservierung", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "Id", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "Ankunftsdatum", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "Abreisedatum", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", "Hotel", nullptr));
        label_13->setText(QCoreApplication::translate("MainWindow", "Stadt", nullptr));
        label_15->setText(QCoreApplication::translate("MainWindow", "Zimmer", nullptr));
        label_14->setText(QCoreApplication::translate("MainWindow", "Preis", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabHotelbuchung), QCoreApplication::translate("MainWindow", "Hotelbuchung", nullptr));
        menuDatei->setTitle(QCoreApplication::translate("MainWindow", "Datei", nullptr));
        menuBuchung->setTitle(QCoreApplication::translate("MainWindow", "Buchung", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
