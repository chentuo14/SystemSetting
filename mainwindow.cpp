#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setGeometry(0, 0, 1024, 600);

    m_systemSettingTab = new QTabWidget(this);
    m_systemSettingTab->setGeometry(0, 0, 1024, 550);
    m_hwConfig = new FormHadrwareConfig();
    m_spConfig = new FormSerialPortSetting();
    m_pjConfig = new FormProjectorSetting();
    m_msConfig = new FormMatrialSetting();
    m_mtConfig = new FormMotorSetting();
    m_systemSettingTab->addTab(m_hwConfig, "HardWare Setting");
    m_systemSettingTab->addTab(m_spConfig, "SerialPort Setting");
    m_systemSettingTab->addTab(m_pjConfig, "Projector Setting");
    m_systemSettingTab->addTab(m_msConfig, "Matrial Setting");
    m_systemSettingTab->addTab(m_mtConfig, "Motor Setting");
    m_mainLayout = new QHBoxLayout();
    m_mainLayout->addWidget(m_systemSettingTab);
    this->setLayout(m_mainLayout);
}

MainWindow::~MainWindow()
{
    delete ui;
}

