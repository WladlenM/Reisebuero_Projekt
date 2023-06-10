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
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionEinlesen;
    QAction *actionEinlesen_2;
    QAction *actionSuchen;
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout_8;
    QHBoxLayout *horizontalLayout_4;
    QGroupBox *groupBoxKunde;
    QVBoxLayout *verticalLayout_7;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEditId;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *lineEditName;
    QFormLayout *formLayout;
    QLabel *label_3;
    QTableWidget *tableWidgetReisen;
    QGroupBox *groupBoxReise;
    QVBoxLayout *verticalLayout_6;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_4;
    QLineEdit *lineEditReiseID;
    QFormLayout *formLayout_2;
    QLabel *label_5;
    QTableWidget *tableWidgetBuchungen;
    QGroupBox *groupBoxBuchungdetails;
    QVBoxLayout *verticalLayout_5;
    QVBoxLayout *verticalLayout_3;
    QFormLayout *formLayout_6;
    QLabel *label_17;
    QLineEdit *lineEditBuchungId;
    QLabel *label_18;
    QDateEdit *dateEditStartDatum;
    QLabel *label_19;
    QDateEdit *dateEditEndDatum;
    QLabel *label_20;
    QDoubleSpinBox *doubleSpinBoxPreis;
    QTabWidget *tabWidgetBuchungTyp;
    QWidget *tabFlugbuchung;
    QVBoxLayout *verticalLayout_4;
    QFormLayout *formLayout_3;
    QLabel *label_6;
    QLineEdit *lineEditFlugzeug;
    QLabel *label_7;
    QLineEdit *lineEditvonFlug;
    QLabel *label_8;
    QLineEdit *lineEditbisFlug;
    QLabel *label_9;
    QLineEdit *lineEditFlugsitz;
    QLabel *label_21;
    QLabel *labelKarteUrl;
    QWidget *tabHotelbuchung;
    QHBoxLayout *horizontalLayout_6;
    QFormLayout *formLayout_4;
    QLabel *label_10;
    QLineEdit *lineEditHotel;
    QLabel *label_11;
    QLineEdit *lineEditStadt;
    QLabel *label_12;
    QLineEdit *lineEditZimmertyp;
    QLabel *label_22;
    QLabel *labelKarteUrlHotel;
    QWidget *tabMietwagenreservierung;
    QHBoxLayout *horizontalLayout_7;
    QFormLayout *formLayout_5;
    QLabel *label_13;
    QLineEdit *lineEditFirma;
    QLabel *label_14;
    QLineEdit *lineEditAbholort;
    QLabel *label_15;
    QLineEdit *lineEditAbgabeort;
    QLabel *label_16;
    QLineEdit *lineEditFahrzeugKlasse;
    QLabel *label_23;
    QLabel *labelKarteUrlAuto;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *pushButtonSave;
    QPushButton *pushButtonCancel;
    QStatusBar *statusbar;
    QMenuBar *menubar;
    QMenu *menuDatei;
    QMenu *menuKunde;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(823, 579);
        actionEinlesen = new QAction(MainWindow);
        actionEinlesen->setObjectName("actionEinlesen");
        actionEinlesen_2 = new QAction(MainWindow);
        actionEinlesen_2->setObjectName("actionEinlesen_2");
        actionSuchen = new QAction(MainWindow);
        actionSuchen->setObjectName("actionSuchen");
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        horizontalLayout_8 = new QHBoxLayout(centralwidget);
        horizontalLayout_8->setObjectName("horizontalLayout_8");
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        groupBoxKunde = new QGroupBox(centralwidget);
        groupBoxKunde->setObjectName("groupBoxKunde");
        groupBoxKunde->setEnabled(true);
        verticalLayout_7 = new QVBoxLayout(groupBoxKunde);
        verticalLayout_7->setObjectName("verticalLayout_7");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        label = new QLabel(groupBoxKunde);
        label->setObjectName("label");

        horizontalLayout->addWidget(label);

        lineEditId = new QLineEdit(groupBoxKunde);
        lineEditId->setObjectName("lineEditId");
        lineEditId->setReadOnly(true);

        horizontalLayout->addWidget(lineEditId);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        label_2 = new QLabel(groupBoxKunde);
        label_2->setObjectName("label_2");

        horizontalLayout_2->addWidget(label_2);

        lineEditName = new QLineEdit(groupBoxKunde);
        lineEditName->setObjectName("lineEditName");
        lineEditName->setReadOnly(true);

        horizontalLayout_2->addWidget(lineEditName);


        verticalLayout->addLayout(horizontalLayout_2);

        formLayout = new QFormLayout();
        formLayout->setObjectName("formLayout");
        label_3 = new QLabel(groupBoxKunde);
        label_3->setObjectName("label_3");

        formLayout->setWidget(0, QFormLayout::LabelRole, label_3);

        tableWidgetReisen = new QTableWidget(groupBoxKunde);
        tableWidgetReisen->setObjectName("tableWidgetReisen");
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(tableWidgetReisen->sizePolicy().hasHeightForWidth());
        tableWidgetReisen->setSizePolicy(sizePolicy);
        tableWidgetReisen->setFrameShape(QFrame::StyledPanel);
        tableWidgetReisen->setFrameShadow(QFrame::Sunken);
        tableWidgetReisen->setSizeAdjustPolicy(QAbstractScrollArea::AdjustIgnored);
        tableWidgetReisen->setHorizontalScrollMode(QAbstractItemView::ScrollPerItem);
        tableWidgetReisen->setGridStyle(Qt::SolidLine);
        tableWidgetReisen->horizontalHeader()->setCascadingSectionResizes(false);

        formLayout->setWidget(0, QFormLayout::FieldRole, tableWidgetReisen);


        verticalLayout->addLayout(formLayout);


        verticalLayout_7->addLayout(verticalLayout);

        groupBoxReise = new QGroupBox(groupBoxKunde);
        groupBoxReise->setObjectName("groupBoxReise");
        verticalLayout_6 = new QVBoxLayout(groupBoxReise);
        verticalLayout_6->setObjectName("verticalLayout_6");
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        label_4 = new QLabel(groupBoxReise);
        label_4->setObjectName("label_4");

        horizontalLayout_3->addWidget(label_4);

        lineEditReiseID = new QLineEdit(groupBoxReise);
        lineEditReiseID->setObjectName("lineEditReiseID");
        lineEditReiseID->setReadOnly(true);

        horizontalLayout_3->addWidget(lineEditReiseID);


        verticalLayout_2->addLayout(horizontalLayout_3);

        formLayout_2 = new QFormLayout();
        formLayout_2->setObjectName("formLayout_2");
        label_5 = new QLabel(groupBoxReise);
        label_5->setObjectName("label_5");

        formLayout_2->setWidget(0, QFormLayout::LabelRole, label_5);

        tableWidgetBuchungen = new QTableWidget(groupBoxReise);
        tableWidgetBuchungen->setObjectName("tableWidgetBuchungen");
        tableWidgetBuchungen->horizontalHeader()->setStretchLastSection(true);
        tableWidgetBuchungen->verticalHeader()->setVisible(false);

        formLayout_2->setWidget(0, QFormLayout::FieldRole, tableWidgetBuchungen);


        verticalLayout_2->addLayout(formLayout_2);


        verticalLayout_6->addLayout(verticalLayout_2);


        verticalLayout_7->addWidget(groupBoxReise);


        horizontalLayout_4->addWidget(groupBoxKunde);

        groupBoxBuchungdetails = new QGroupBox(centralwidget);
        groupBoxBuchungdetails->setObjectName("groupBoxBuchungdetails");
        verticalLayout_5 = new QVBoxLayout(groupBoxBuchungdetails);
        verticalLayout_5->setObjectName("verticalLayout_5");
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName("verticalLayout_3");
        formLayout_6 = new QFormLayout();
        formLayout_6->setObjectName("formLayout_6");
        label_17 = new QLabel(groupBoxBuchungdetails);
        label_17->setObjectName("label_17");

        formLayout_6->setWidget(0, QFormLayout::LabelRole, label_17);

        lineEditBuchungId = new QLineEdit(groupBoxBuchungdetails);
        lineEditBuchungId->setObjectName("lineEditBuchungId");
        lineEditBuchungId->setEnabled(false);

        formLayout_6->setWidget(0, QFormLayout::FieldRole, lineEditBuchungId);

        label_18 = new QLabel(groupBoxBuchungdetails);
        label_18->setObjectName("label_18");

        formLayout_6->setWidget(1, QFormLayout::LabelRole, label_18);

        dateEditStartDatum = new QDateEdit(groupBoxBuchungdetails);
        dateEditStartDatum->setObjectName("dateEditStartDatum");

        formLayout_6->setWidget(1, QFormLayout::FieldRole, dateEditStartDatum);

        label_19 = new QLabel(groupBoxBuchungdetails);
        label_19->setObjectName("label_19");

        formLayout_6->setWidget(2, QFormLayout::LabelRole, label_19);

        dateEditEndDatum = new QDateEdit(groupBoxBuchungdetails);
        dateEditEndDatum->setObjectName("dateEditEndDatum");

        formLayout_6->setWidget(2, QFormLayout::FieldRole, dateEditEndDatum);

        label_20 = new QLabel(groupBoxBuchungdetails);
        label_20->setObjectName("label_20");

        formLayout_6->setWidget(3, QFormLayout::LabelRole, label_20);

        doubleSpinBoxPreis = new QDoubleSpinBox(groupBoxBuchungdetails);
        doubleSpinBoxPreis->setObjectName("doubleSpinBoxPreis");
        doubleSpinBoxPreis->setMaximum(99999.990000000005239);

        formLayout_6->setWidget(3, QFormLayout::FieldRole, doubleSpinBoxPreis);


        verticalLayout_3->addLayout(formLayout_6);

        tabWidgetBuchungTyp = new QTabWidget(groupBoxBuchungdetails);
        tabWidgetBuchungTyp->setObjectName("tabWidgetBuchungTyp");
        tabFlugbuchung = new QWidget();
        tabFlugbuchung->setObjectName("tabFlugbuchung");
        verticalLayout_4 = new QVBoxLayout(tabFlugbuchung);
        verticalLayout_4->setObjectName("verticalLayout_4");
        formLayout_3 = new QFormLayout();
        formLayout_3->setObjectName("formLayout_3");
        label_6 = new QLabel(tabFlugbuchung);
        label_6->setObjectName("label_6");

        formLayout_3->setWidget(0, QFormLayout::LabelRole, label_6);

        lineEditFlugzeug = new QLineEdit(tabFlugbuchung);
        lineEditFlugzeug->setObjectName("lineEditFlugzeug");

        formLayout_3->setWidget(0, QFormLayout::FieldRole, lineEditFlugzeug);

        label_7 = new QLabel(tabFlugbuchung);
        label_7->setObjectName("label_7");

        formLayout_3->setWidget(1, QFormLayout::LabelRole, label_7);

        lineEditvonFlug = new QLineEdit(tabFlugbuchung);
        lineEditvonFlug->setObjectName("lineEditvonFlug");

        formLayout_3->setWidget(1, QFormLayout::FieldRole, lineEditvonFlug);

        label_8 = new QLabel(tabFlugbuchung);
        label_8->setObjectName("label_8");

        formLayout_3->setWidget(2, QFormLayout::LabelRole, label_8);

        lineEditbisFlug = new QLineEdit(tabFlugbuchung);
        lineEditbisFlug->setObjectName("lineEditbisFlug");

        formLayout_3->setWidget(2, QFormLayout::FieldRole, lineEditbisFlug);

        label_9 = new QLabel(tabFlugbuchung);
        label_9->setObjectName("label_9");

        formLayout_3->setWidget(3, QFormLayout::LabelRole, label_9);

        lineEditFlugsitz = new QLineEdit(tabFlugbuchung);
        lineEditFlugsitz->setObjectName("lineEditFlugsitz");

        formLayout_3->setWidget(3, QFormLayout::FieldRole, lineEditFlugsitz);

        label_21 = new QLabel(tabFlugbuchung);
        label_21->setObjectName("label_21");

        formLayout_3->setWidget(4, QFormLayout::LabelRole, label_21);

        labelKarteUrl = new QLabel(tabFlugbuchung);
        labelKarteUrl->setObjectName("labelKarteUrl");

        formLayout_3->setWidget(4, QFormLayout::FieldRole, labelKarteUrl);


        verticalLayout_4->addLayout(formLayout_3);

        tabWidgetBuchungTyp->addTab(tabFlugbuchung, QString());
        tabHotelbuchung = new QWidget();
        tabHotelbuchung->setObjectName("tabHotelbuchung");
        horizontalLayout_6 = new QHBoxLayout(tabHotelbuchung);
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        formLayout_4 = new QFormLayout();
        formLayout_4->setObjectName("formLayout_4");
        label_10 = new QLabel(tabHotelbuchung);
        label_10->setObjectName("label_10");

        formLayout_4->setWidget(0, QFormLayout::LabelRole, label_10);

        lineEditHotel = new QLineEdit(tabHotelbuchung);
        lineEditHotel->setObjectName("lineEditHotel");

        formLayout_4->setWidget(0, QFormLayout::FieldRole, lineEditHotel);

        label_11 = new QLabel(tabHotelbuchung);
        label_11->setObjectName("label_11");

        formLayout_4->setWidget(1, QFormLayout::LabelRole, label_11);

        lineEditStadt = new QLineEdit(tabHotelbuchung);
        lineEditStadt->setObjectName("lineEditStadt");

        formLayout_4->setWidget(1, QFormLayout::FieldRole, lineEditStadt);

        label_12 = new QLabel(tabHotelbuchung);
        label_12->setObjectName("label_12");

        formLayout_4->setWidget(2, QFormLayout::LabelRole, label_12);

        lineEditZimmertyp = new QLineEdit(tabHotelbuchung);
        lineEditZimmertyp->setObjectName("lineEditZimmertyp");

        formLayout_4->setWidget(2, QFormLayout::FieldRole, lineEditZimmertyp);

        label_22 = new QLabel(tabHotelbuchung);
        label_22->setObjectName("label_22");

        formLayout_4->setWidget(3, QFormLayout::LabelRole, label_22);

        labelKarteUrlHotel = new QLabel(tabHotelbuchung);
        labelKarteUrlHotel->setObjectName("labelKarteUrlHotel");

        formLayout_4->setWidget(3, QFormLayout::FieldRole, labelKarteUrlHotel);


        horizontalLayout_6->addLayout(formLayout_4);

        tabWidgetBuchungTyp->addTab(tabHotelbuchung, QString());
        tabMietwagenreservierung = new QWidget();
        tabMietwagenreservierung->setObjectName("tabMietwagenreservierung");
        horizontalLayout_7 = new QHBoxLayout(tabMietwagenreservierung);
        horizontalLayout_7->setObjectName("horizontalLayout_7");
        formLayout_5 = new QFormLayout();
        formLayout_5->setObjectName("formLayout_5");
        label_13 = new QLabel(tabMietwagenreservierung);
        label_13->setObjectName("label_13");

        formLayout_5->setWidget(0, QFormLayout::LabelRole, label_13);

        lineEditFirma = new QLineEdit(tabMietwagenreservierung);
        lineEditFirma->setObjectName("lineEditFirma");

        formLayout_5->setWidget(0, QFormLayout::FieldRole, lineEditFirma);

        label_14 = new QLabel(tabMietwagenreservierung);
        label_14->setObjectName("label_14");

        formLayout_5->setWidget(1, QFormLayout::LabelRole, label_14);

        lineEditAbholort = new QLineEdit(tabMietwagenreservierung);
        lineEditAbholort->setObjectName("lineEditAbholort");

        formLayout_5->setWidget(1, QFormLayout::FieldRole, lineEditAbholort);

        label_15 = new QLabel(tabMietwagenreservierung);
        label_15->setObjectName("label_15");

        formLayout_5->setWidget(2, QFormLayout::LabelRole, label_15);

        lineEditAbgabeort = new QLineEdit(tabMietwagenreservierung);
        lineEditAbgabeort->setObjectName("lineEditAbgabeort");

        formLayout_5->setWidget(2, QFormLayout::FieldRole, lineEditAbgabeort);

        label_16 = new QLabel(tabMietwagenreservierung);
        label_16->setObjectName("label_16");

        formLayout_5->setWidget(3, QFormLayout::LabelRole, label_16);

        lineEditFahrzeugKlasse = new QLineEdit(tabMietwagenreservierung);
        lineEditFahrzeugKlasse->setObjectName("lineEditFahrzeugKlasse");

        formLayout_5->setWidget(3, QFormLayout::FieldRole, lineEditFahrzeugKlasse);

        label_23 = new QLabel(tabMietwagenreservierung);
        label_23->setObjectName("label_23");

        formLayout_5->setWidget(4, QFormLayout::LabelRole, label_23);

        labelKarteUrlAuto = new QLabel(tabMietwagenreservierung);
        labelKarteUrlAuto->setObjectName("labelKarteUrlAuto");

        formLayout_5->setWidget(4, QFormLayout::FieldRole, labelKarteUrlAuto);


        horizontalLayout_7->addLayout(formLayout_5);

        tabWidgetBuchungTyp->addTab(tabMietwagenreservierung, QString());

        verticalLayout_3->addWidget(tabWidgetBuchungTyp);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        pushButtonSave = new QPushButton(groupBoxBuchungdetails);
        pushButtonSave->setObjectName("pushButtonSave");
        pushButtonSave->setEnabled(false);

        horizontalLayout_5->addWidget(pushButtonSave);

        pushButtonCancel = new QPushButton(groupBoxBuchungdetails);
        pushButtonCancel->setObjectName("pushButtonCancel");
        pushButtonCancel->setEnabled(false);

        horizontalLayout_5->addWidget(pushButtonCancel);


        verticalLayout_3->addLayout(horizontalLayout_5);


        verticalLayout_5->addLayout(verticalLayout_3);


        horizontalLayout_4->addWidget(groupBoxBuchungdetails);


        horizontalLayout_8->addLayout(horizontalLayout_4);

        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 823, 17));
        menuDatei = new QMenu(menubar);
        menuDatei->setObjectName("menuDatei");
        menuKunde = new QMenu(menubar);
        menuKunde->setObjectName("menuKunde");
        MainWindow->setMenuBar(menubar);

        menubar->addAction(menuDatei->menuAction());
        menubar->addAction(menuKunde->menuAction());
        menuDatei->addAction(actionEinlesen_2);
        menuKunde->addAction(actionSuchen);

        retranslateUi(MainWindow);

        tabWidgetBuchungTyp->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionEinlesen->setText(QCoreApplication::translate("MainWindow", "Einlesen", nullptr));
        actionEinlesen_2->setText(QCoreApplication::translate("MainWindow", "Einlesen", nullptr));
        actionSuchen->setText(QCoreApplication::translate("MainWindow", "Suchen", nullptr));
        groupBoxKunde->setTitle(QCoreApplication::translate("MainWindow", "Kund*in", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "ID", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Name", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Reisen", nullptr));
        groupBoxReise->setTitle(QCoreApplication::translate("MainWindow", "Reise", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Reise-ID", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Buchungen", nullptr));
        groupBoxBuchungdetails->setTitle(QCoreApplication::translate("MainWindow", "Buchungsdetails", nullptr));
        label_17->setText(QCoreApplication::translate("MainWindow", "Buchungs-ID", nullptr));
        label_18->setText(QCoreApplication::translate("MainWindow", "Start Datum", nullptr));
        label_19->setText(QCoreApplication::translate("MainWindow", "End Datum", nullptr));
        label_20->setText(QCoreApplication::translate("MainWindow", "Preis", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "Fluggesellschaft", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "Von", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "Bis", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "Buchungs Klasse", nullptr));
        label_21->setText(QCoreApplication::translate("MainWindow", "Karte", nullptr));
        labelKarteUrl->setText(QString());
        tabWidgetBuchungTyp->setTabText(tabWidgetBuchungTyp->indexOf(tabFlugbuchung), QCoreApplication::translate("MainWindow", "Flugbuchung", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "Hotelname", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "Stadt", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", "Zimmertyp", nullptr));
        label_22->setText(QCoreApplication::translate("MainWindow", "Karte", nullptr));
        labelKarteUrlHotel->setText(QString());
        tabWidgetBuchungTyp->setTabText(tabWidgetBuchungTyp->indexOf(tabHotelbuchung), QCoreApplication::translate("MainWindow", "Hotelbuchung", nullptr));
        label_13->setText(QCoreApplication::translate("MainWindow", "Firma", nullptr));
        label_14->setText(QCoreApplication::translate("MainWindow", "Abholort", nullptr));
        label_15->setText(QCoreApplication::translate("MainWindow", "Abgabeort", nullptr));
        label_16->setText(QCoreApplication::translate("MainWindow", "Fahrzeug Klasse", nullptr));
        label_23->setText(QCoreApplication::translate("MainWindow", "Karte", nullptr));
        labelKarteUrlAuto->setText(QString());
        tabWidgetBuchungTyp->setTabText(tabWidgetBuchungTyp->indexOf(tabMietwagenreservierung), QCoreApplication::translate("MainWindow", "Mietwagenreservierung", nullptr));
        pushButtonSave->setText(QCoreApplication::translate("MainWindow", "Speichern", nullptr));
        pushButtonCancel->setText(QCoreApplication::translate("MainWindow", "Abbrechen", nullptr));
        menuDatei->setTitle(QCoreApplication::translate("MainWindow", "Datei", nullptr));
        menuKunde->setTitle(QCoreApplication::translate("MainWindow", "Kund*innen", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
