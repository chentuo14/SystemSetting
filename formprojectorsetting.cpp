#include "formprojectorsetting.h"
#include "ui_formprojectorsetting.h"

FormProjectorSetting::FormProjectorSetting(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormProjectorSetting)
{
    ui->setupUi(this);
    InitProjectorSetting();
    InitControlsPosition();
}

FormProjectorSetting::~FormProjectorSetting()
{
    delete ui;
}

void FormProjectorSetting::InitProjectorSetting()
{
    m_proAName = new QLabel(this);
    m_proAName->setText("A");
    m_proBName = new QLabel(this);
    m_proBName->setText("B");
    m_proCName = new QLabel(this);
    m_proCName->setText("C");
    m_proDName = new QLabel(this);
    m_proDName->setText("D");
    m_proA = new QLineEdit(this);
    m_proA->setText("0");
    m_proB = new QLineEdit(this);
    m_proB->setText("0");
    m_proC = new QLineEdit(this);
    m_proC->setText("0");
    m_proD = new QLineEdit(this);
    m_proD->setText("0");
    m_proPrintStartName = new QLabel(this);
    m_proPrintStartName->setText("print start");
    m_proPrintStart = new QLineEdit(this);
    m_proPrintStart->setText("0");
    m_btnConfig = new QPushButton(this);
    m_btnConfig->setText("Config");
    m_btnSet = new QPushButton(this);
    m_btnSet->setText("Set");
    m_btnRead = new QPushButton(this);
    m_btnRead->setText("Read");

    m_proTAName = new QLabel(this);
    m_proTAName->setText("TA");
    m_proTBName = new QLabel(this);
    m_proTBName->setText("TB");
    m_proTCName = new QLabel(this);
    m_proTCName->setText("TC");
    m_proTDName = new QLabel(this);
    m_proTDName->setText("TD");
    m_proTA = new QLineEdit(this);
    m_proTA->setText("0");
    m_proTB = new QLineEdit(this);
    m_proTB->setText("0");
    m_proTC = new QLineEdit(this);
    m_proTC->setText("0");
    m_proTD = new QLineEdit(this);
    m_proTD->setText("0");

    m_proTName = new QLabel(this);
    m_proTName->setText("T");
    m_proMaxTName = new QLabel(this);
    m_proMaxTName->setText("MaxT");
    m_proT = new QLineEdit(this);
    m_proT->setText("0");
    m_proMaxT = new QLineEdit(this);
    m_proMaxT->setText("80");
}

void FormProjectorSetting::InitControlsPosition()
{
    int startX = 50;
    int startY = 100;
    int space = 10;
    int labelWidth = 50;
    int labelHeight = 30;
    int lineWidth = 150;
    int lineHeight = 30;
    m_proAName->setGeometry(startX, startY, labelWidth, labelHeight);
    m_proA->setGeometry(m_proAName->geometry().topRight().x()+space,
                        m_proAName->geometry().topRight().y(),
                        lineWidth, lineHeight);
    m_proBName->setGeometry(m_proAName->geometry().bottomLeft().x(),
                            m_proAName->geometry().bottomLeft().y()+space,
                            labelWidth, labelHeight);
    m_proB->setGeometry(m_proBName->geometry().topRight().x()+space,
                        m_proBName->geometry().topRight().y(),
                        lineWidth, lineHeight);
    m_proCName->setGeometry(m_proBName->geometry().bottomLeft().x(),
                            m_proBName->geometry().bottomLeft().y()+space,
                            labelWidth, labelHeight);
    m_proC->setGeometry(m_proCName->geometry().topRight().x()+space,
                        m_proCName->geometry().topRight().y(),
                        lineWidth, lineHeight);
    m_btnConfig->setGeometry(m_proC->geometry().topRight().x()+space,
                             m_proC->geometry().topRight().y(),
                             lineWidth/2, lineHeight);
    m_proDName->setGeometry(m_proCName->geometry().bottomLeft().x(),
                            m_proCName->geometry().bottomLeft().y()+space,
                            labelWidth, labelHeight);
    m_proD->setGeometry(m_proDName->geometry().topRight().x()+space,
                        m_proDName->geometry().topRight().y(),
                        lineWidth, lineHeight);
    m_btnSet->setGeometry(m_proD->geometry().topRight().x()+space,
                          m_proD->geometry().topRight().y(),
                          lineWidth/2, lineHeight);
    m_proPrintStartName->setGeometry(m_proDName->geometry().bottomLeft().x(),
                            m_proDName->geometry().bottomLeft().y()+space,
                            labelWidth*2, labelHeight);
    m_proPrintStart->setGeometry(m_proPrintStartName->geometry().topRight().x()+space,
                        m_proPrintStartName->geometry().topRight().y(),
                        lineWidth, lineHeight);
    m_btnRead->setGeometry(m_proPrintStartName->geometry().bottomRight().x()+space,
                           m_proPrintStartName->geometry().bottomRight().y()+space*3,
                           lineWidth-space*2, labelHeight+space*2);
    m_proTAName->setGeometry(m_btnConfig->geometry().topRight().x()+space,
                         m_proA->geometry().topRight().y(),
                         labelWidth, labelHeight);
    m_proTA->setGeometry(m_proTAName->geometry().topRight().x()+space,
                        m_proTAName->geometry().topRight().y(),
                        lineWidth, lineHeight);
    m_proTBName->setGeometry(m_proTAName->geometry().bottomLeft().x(),
                            m_proTAName->geometry().bottomLeft().y()+space,
                            labelWidth, labelHeight);
    m_proTB->setGeometry(m_proTBName->geometry().topRight().x()+space,
                        m_proTBName->geometry().topRight().y(),
                        lineWidth, lineHeight);
    m_proTCName->setGeometry(m_proTBName->geometry().bottomLeft().x(),
                            m_proTBName->geometry().bottomLeft().y()+space,
                            labelWidth, labelHeight);
    m_proTC->setGeometry(m_proTCName->geometry().topRight().x()+space,
                        m_proTCName->geometry().topRight().y(),
                        lineWidth, lineHeight);
    m_proTDName->setGeometry(m_proTCName->geometry().bottomLeft().x(),
                            m_proTCName->geometry().bottomLeft().y()+space,
                            labelWidth, labelHeight);
    m_proTD->setGeometry(m_proTDName->geometry().topRight().x()+space,
                        m_proTDName->geometry().topRight().y(),
                        lineWidth, lineHeight);
    m_proTName->setGeometry(m_proTA->geometry().topRight().x()+space,
                            m_proTA->geometry().topRight().y(),
                            labelWidth, labelHeight);
    m_proT->setGeometry(m_proTName->geometry().topRight().x()+space,
                        m_proTName->geometry().topRight().y(),
                        lineWidth, lineHeight);
    m_proMaxTName->setGeometry(m_proTName->geometry().bottomLeft().x(),
                            m_proTName->geometry().bottomLeft().y()+space,
                            labelWidth, labelHeight);
    m_proMaxT->setGeometry(m_proMaxTName->geometry().topRight().x()+space,
                        m_proMaxTName->geometry().topRight().y(),
                        lineWidth, lineHeight);
}
