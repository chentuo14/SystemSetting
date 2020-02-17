#include "formserialportsetting.h"
#include "ui_formserialportsetting.h"

FormSerialPortSetting::FormSerialPortSetting(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormSerialPortSetting)
{
    ui->setupUi(this);
    InitGroupMotor();
    InitGroupProjector();
    InitGroupTray();
    int grpSpace = 10;
    int grpWidth = 300;
    int grpHeight = 400;
    m_grpMotor->setGeometry(grpSpace, grpSpace, grpWidth, grpHeight);
    m_grpProjector->setGeometry(m_grpMotor->geometry().topRight().x()+grpSpace,
                                m_grpMotor->geometry().topRight().y(),
                                grpWidth, grpHeight);
    m_grpTray->setGeometry(m_grpProjector->geometry().topRight().x()+grpSpace,
                           m_grpProjector->geometry().topRight().y(),
                           grpWidth, grpHeight);
}

FormSerialPortSetting::~FormSerialPortSetting()
{
    delete ui;
}

void FormSerialPortSetting::InitGroupMotor()
{
    m_grpMotor = new QGroupBox(this);
    m_grpMotor->setTitle("Motro Contorl");
    m_motorSerial = new QComboBox(this);
    m_motorSerial->addItem("COM2");
    m_motorSpeed = new QComboBox(this);
    m_motorSpeed->addItem("9600");
    m_motorDataBits = new QComboBox(this);
    m_motorDataBits->addItem("8");
    m_motorStopBits = new QComboBox(this);
    m_motorStopBits->addItem("1");
    m_motorParity = new QComboBox(this);
    m_motorParity->addItem("None");
    m_motorSerialName = new QLabel(this);
    m_motorSerialName->setText("Serial Port Name");
    m_motorSpeedName = new QLabel(this);
    m_motorSpeedName->setText("Speed");
    m_motorDataBitsName = new QLabel(this);
    m_motorDataBitsName->setText("Data Bits");
    m_motorStopBitsName = new QLabel(this);
    m_motorStopBitsName->setText("Stop Bits");
    m_motorParityName = new QLabel(this);
    m_motorParityName->setText("Parity");
    QGridLayout *layoutGrp = new QGridLayout();
    layoutGrp->addWidget(m_motorSerialName, 0, 0, 1, 1);
    layoutGrp->addWidget(m_motorSerial,     0, 1, 1, 1);
    layoutGrp->addWidget(m_motorSpeedName,  1, 0, 1, 1);
    layoutGrp->addWidget(m_motorSpeed,      1, 1, 1, 1);
    layoutGrp->addWidget(m_motorDataBitsName, 2, 0, 1, 1);
    layoutGrp->addWidget(m_motorDataBits,     2, 1, 1, 1);
    layoutGrp->addWidget(m_motorStopBitsName, 3, 0, 1, 1);
    layoutGrp->addWidget(m_motorStopBits,     3, 1, 1, 1);
    layoutGrp->addWidget(m_motorParityName, 4, 0, 1, 1);
    layoutGrp->addWidget(m_motorParity,     4, 1, 1, 1);
    m_grpMotor->setLayout(layoutGrp);
}

void FormSerialPortSetting::InitGroupProjector()
{
    m_grpProjector = new QGroupBox(this);
    m_grpProjector->setTitle("Projector Control");
    m_projectorSerial = new QComboBox(this);
    m_projectorSerial->addItem("COM2");
    m_projectorSpeed = new QComboBox(this);
    m_projectorSpeed->addItem("9600");
    m_projectorDataBits = new QComboBox(this);
    m_projectorDataBits->addItem("8");
    m_projectorStopBits = new QComboBox(this);
    m_projectorStopBits->addItem("1");
    m_projectorParity = new QComboBox(this);
    m_projectorParity->addItem("None");
    m_projectorSerialName = new QLabel(this);
    m_projectorSerialName->setText("Serial Port Name");
    m_projectorSpeedName = new QLabel(this);
    m_projectorSpeedName->setText("Speed");
    m_projectorDataBitsName = new QLabel(this);
    m_projectorDataBitsName->setText("Data Bits");
    m_projectorStopBitsName = new QLabel(this);
    m_projectorStopBitsName->setText("Stop Bits");
    m_projectorParityName = new QLabel(this);
    m_projectorParityName->setText("Parity");
    QGridLayout *layoutGrp = new QGridLayout();
    layoutGrp->addWidget(m_projectorSerialName, 0, 0, 1, 1);
    layoutGrp->addWidget(m_projectorSerial,     0, 1, 1, 1);
    layoutGrp->addWidget(m_projectorSpeedName,  1, 0, 1, 1);
    layoutGrp->addWidget(m_projectorSpeed,      1, 1, 1, 1);
    layoutGrp->addWidget(m_projectorDataBitsName, 2, 0, 1, 1);
    layoutGrp->addWidget(m_projectorDataBits,     2, 1, 1, 1);
    layoutGrp->addWidget(m_projectorStopBitsName, 3, 0, 1, 1);
    layoutGrp->addWidget(m_projectorStopBits,     3, 1, 1, 1);
    layoutGrp->addWidget(m_projectorParityName, 4, 0, 1, 1);
    layoutGrp->addWidget(m_projectorParity,     4, 1, 1, 1);
    m_grpProjector->setLayout(layoutGrp);

}

void FormSerialPortSetting::InitGroupTray()
{
    m_grpTray = new QGroupBox(this);
    m_grpTray->setTitle("Tray Control");
    m_traySerial = new QComboBox(this);
    m_traySerial->addItem("COM2");
    m_traySpeed = new QComboBox(this);
    m_traySpeed->addItem("9600");
    m_trayDataBits = new QComboBox(this);
    m_trayDataBits->addItem("8");
    m_trayStopBits = new QComboBox(this);
    m_trayStopBits->addItem("1");
    m_trayParity = new QComboBox(this);
    m_trayParity->addItem("None");
    m_traySerialName = new QLabel(this);
    m_traySerialName->setText("Serial Port Name");
    m_traySpeedName = new QLabel(this);
    m_traySpeedName->setText("Speed");
    m_trayDataBitsName = new QLabel(this);
    m_trayDataBitsName->setText("Data Bits");
    m_trayStopBitsName = new QLabel(this);
    m_trayStopBitsName->setText("Stop Bits");
    m_trayParityName = new QLabel(this);
    m_trayParityName->setText("Parity");
    QGridLayout *layoutGrp = new QGridLayout();
    layoutGrp->addWidget(m_traySerialName, 0, 0, 1, 1);
    layoutGrp->addWidget(m_traySerial,     0, 1, 1, 1);
    layoutGrp->addWidget(m_traySpeedName,  1, 0, 1, 1);
    layoutGrp->addWidget(m_traySpeed,      1, 1, 1, 1);
    layoutGrp->addWidget(m_trayDataBitsName, 2, 0, 1, 1);
    layoutGrp->addWidget(m_trayDataBits,     2, 1, 1, 1);
    layoutGrp->addWidget(m_trayStopBitsName, 3, 0, 1, 1);
    layoutGrp->addWidget(m_trayStopBits,     3, 1, 1, 1);
    layoutGrp->addWidget(m_trayParityName, 4, 0, 1, 1);
    layoutGrp->addWidget(m_trayParity,     4, 1, 1, 1);
    m_grpTray->setLayout(layoutGrp);
}
