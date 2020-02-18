#include "formmotorsetting.h"
#include "ui_formmotorsetting.h"

FormMotorSetting::FormMotorSetting(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormMotorSetting)
{
    ui->setupUi(this);

    InitAxisName();
    InitAxisChannel();
    InitDriverMode();

    InitPostiveLevel();
    InitNegativeLevel();
    InitResetDirection();
    InitRestLevel();

    InitGroupProjectorPower();
    InitGroupProjectorLight();
    InitGroupBuzzer();
    InitGroupWaitTime();

    InitTimeCoefficientAndButton();
}

FormMotorSetting::~FormMotorSetting()
{
    delete ui;
}

void FormMotorSetting::InitAxisName()
{
    m_axisNameName = new QLabel(this);
    m_axisNameName->setText("AxisName");
    m_axisNameName->setGeometry(m_space*2, m_space,
                                m_labelWidth, m_labelHeight);
    m_cmbAxisName = new QComboBox(this);
    m_cmbAxisName->addItem("Z");
    m_cmbAxisName->setGeometry(m_axisNameName->geometry().topRight().x()+m_space,
                               m_axisNameName->geometry().topRight().y(),
                               m_cmbWidth, m_cmbHeight);

    m_ckbAxisName = new QCheckBox(this);
    m_ckbAxisName->setText("Valid");
    m_ckbAxisName->setCheckState(Qt::Checked);
    m_ckbAxisName->setGeometry(m_cmbAxisName->geometry().bottomLeft().x(),
                               m_cmbAxisName->geometry().bottomLeft().y()+m_space*2,
                               m_labelWidth,m_labelHeight);
}

void FormMotorSetting::InitAxisChannel()
{
    m_axisChannelName = new QLabel(this);
    m_axisChannelName->setText("Axis Channel");
    m_axisChannelName->setGeometry(m_axisNameName->geometry().topLeft().x(),
                                   m_ckbAxisName->geometry().bottomLeft().y()+m_space*2,
                                   m_labelWidth, m_labelHeight);
    m_cmbAxisChannel = new QComboBox(this);
    m_cmbAxisChannel->addItem("0");
    m_cmbAxisChannel->setGeometry(m_axisChannelName->geometry().topRight().x()+m_space,
                               m_axisChannelName->geometry().topRight().y(),
                               m_cmbWidth, m_cmbHeight);
}

void FormMotorSetting::InitDriverMode()
{
    m_driverModeName = new QLabel(this);
    m_driverModeName->setText("Driver Mode");
    m_driverModeName->setGeometry(m_axisChannelName->geometry().bottomLeft().x(),
                                  m_axisChannelName->geometry().bottomLeft().y()+m_space*2,
                                  m_labelWidth, m_labelHeight);
    m_cmbDriverMode = new QComboBox(this);
    m_cmbDriverMode->addItem("pulse/dir,rising");
    m_cmbDriverMode->setGeometry(m_driverModeName->geometry().topRight().x()+m_space,
                               m_driverModeName->geometry().topRight().y(),
                               m_cmbWidth, m_cmbHeight);
}

void FormMotorSetting::InitPostiveLevel()
{
    m_positiveLimitName = new QLabel(this);
    m_positiveLimitName->setText("Positive Limit");
    m_positiveLimitName->setGeometry(m_driverModeName->geometry().bottomLeft().x(),
                                     m_driverModeName->geometry().bottomLeft().y()+m_space*2,
                                     m_labelWidth+20, m_labelHeight);
    m_positiveLevelLow = new QRadioButton(this);
    m_positiveLevelLow->setText("Low Level");

    m_positiveLevelLow->setGeometry(m_positiveLimitName->geometry().topRight().x()+m_space,
                                    m_positiveLimitName->geometry().topRight().y(),
                                    m_labelWidth+20, m_labelHeight);
    m_positiveLevelHigh = new QRadioButton(this);
    m_positiveLevelHigh->setText("Heigh Level");
    m_positiveLevelHigh->setGeometry(m_positiveLevelLow->geometry().topRight().x()+m_space*2,
                                    m_positiveLevelLow->geometry().topRight().y(),
                                    m_labelWidth+20, m_labelHeight);
    m_positiveLevelGrp = new QButtonGroup(this);
    m_positiveLevelGrp->addButton(m_positiveLevelLow);
    m_positiveLevelGrp->addButton(m_positiveLevelHigh);
    m_positiveLevelLow->setChecked(true);
}

void FormMotorSetting::InitNegativeLevel()
{
    m_negativeLimitName = new QLabel(this);
    m_negativeLimitName->setText("Negative Limit");
    m_negativeLimitName->setGeometry(m_positiveLimitName->geometry().bottomLeft().x(),
                                     m_positiveLimitName->geometry().bottomLeft().y()+m_space*2,
                                     m_labelWidth+20, m_labelHeight);
    m_negativeLevelLow = new QRadioButton(this);
    m_negativeLevelLow->setText("Low Level");
    m_negativeLevelLow->setGeometry(m_negativeLimitName->geometry().topRight().x()+m_space,
                                    m_negativeLimitName->geometry().topRight().y(),
                                    m_labelWidth+20, m_labelHeight);
    m_negativeLevelHigh = new QRadioButton(this);
    m_negativeLevelHigh->setText("Heigh Level");
    m_negativeLevelHigh->setGeometry(m_negativeLevelLow->geometry().topRight().x()+m_space,
                                    m_negativeLevelLow->geometry().topRight().y(),
                                    m_labelWidth+20, m_labelHeight);

    m_negativeLevelGrp = new QButtonGroup(this);
    m_negativeLevelGrp->addButton(m_negativeLevelLow);
    m_negativeLevelGrp->addButton(m_negativeLevelHigh);
    m_negativeLevelLow->setChecked(true);
}

void FormMotorSetting::InitResetDirection()
{
    m_resetDirectionName = new QLabel(this);
    m_resetDirectionName->setText("Reset Direction");
    m_resetDirectionName->setGeometry(m_negativeLimitName->geometry().bottomLeft().x(),
                                     m_negativeLimitName->geometry().bottomLeft().y()+m_space*2,
                                     m_labelWidth+30, m_labelHeight);
    m_resetDirectionNegative = new QRadioButton(this);
    m_resetDirectionNegative->setText("Negative");
    m_resetDirectionNegative->setChecked(true);
    m_resetDirectionNegative->setGeometry(m_resetDirectionName->geometry().topRight().x()+m_space,
                                    m_resetDirectionName->geometry().topRight().y(),
                                    m_labelWidth+20, m_labelHeight);
    m_resetDirectionPositive = new QRadioButton(this);
    m_resetDirectionPositive->setText("Positive");
    m_resetDirectionPositive->setChecked(true);
    m_resetDirectionPositive->setGeometry(m_resetDirectionNegative->geometry().topRight().x()+m_space,
                                    m_resetDirectionNegative->geometry().topRight().y(),
                                    m_labelWidth+20, m_labelHeight);

    m_resetDirectionGrp = new QButtonGroup(this);
    m_resetDirectionGrp->addButton(m_resetDirectionNegative);
    m_resetDirectionGrp->addButton(m_resetDirectionPositive);
    m_resetDirectionNegative->setChecked(true);
}

void FormMotorSetting::InitRestLevel()
{
    m_resetLevelName = new QLabel(this);
    m_resetLevelName->setText("Reset Level");
    m_resetLevelName->setGeometry(m_resetDirectionName->geometry().bottomLeft().x(),
                                  m_resetDirectionName->geometry().bottomLeft().y()+m_space*2,
                                  m_labelWidth+20, m_labelHeight);
    m_resetLevelLow = new QRadioButton(this);
    m_resetLevelLow->setText("Low Level");
    m_resetLevelLow->setChecked(true);
    m_resetLevelLow->setGeometry(m_resetLevelName->geometry().topRight().x()+m_space,
                                 m_resetLevelName->geometry().topRight().y(),
                                 m_labelWidth+20, m_labelHeight);
    m_resetLevelHigh = new QRadioButton(this);
    m_resetLevelHigh->setText("Heigh Level");
    m_resetLevelHigh->setChecked(true);
    m_resetLevelHigh->setGeometry(m_resetLevelLow->geometry().topRight().x()+m_space,
                                  m_resetLevelLow->geometry().topRight().y(),
                                  m_labelWidth+20, m_labelHeight);

    m_resetLevelGrp = new QButtonGroup(this);
    m_resetLevelGrp->addButton(m_resetLevelLow);
    m_resetLevelGrp->addButton(m_resetLevelHigh);
    m_resetLevelLow->setChecked(true);
}

void FormMotorSetting::InitGroupProjectorPower()
{
    m_grpProjectorPower = new QGroupBox(this);
    m_grpProjectorPower->setTitle("Projector Power Config");
    m_grpProjectorPower->setGeometry(m_cmbAxisName->geometry().topRight().x()+m_space*7,
                                     m_cmbAxisName->geometry().topRight().y(),
                                     m_grpWidth, m_grpHeight);
    m_projectorPowerChannelName = new QLabel(this);
    m_projectorPowerChannelName->setText("Channel");

    m_cmbProjectorPowerChannel = new QComboBox(this);
    m_cmbProjectorPowerChannel->addItem("1");

    m_projectorPowerOpenName = new QLabel(this);
    m_projectorPowerOpenName->setText("Open Level");

    m_projectorPowerOpenLow = new QRadioButton(this);
    m_projectorPowerOpenLow->setText("Low Level");
    m_projectorPowerOpenLow->setChecked(true);

    m_projectorPowerOpenHigh = new QRadioButton(this);
    m_projectorPowerOpenHigh->setText("High Level");
    QGridLayout *grpLayout = new QGridLayout();
    grpLayout->addWidget(m_projectorPowerChannelName, 0, 0, 1, 1);
    grpLayout->addWidget(m_cmbProjectorPowerChannel, 0, 1, 1, 3);
    grpLayout->addWidget(m_projectorPowerOpenName, 1, 0, 1, 1);
    grpLayout->addWidget(m_projectorPowerOpenLow, 1, 1, 1, 1);
    grpLayout->addWidget(m_projectorPowerOpenHigh, 1, 2, 1, 1);

    m_grpProjectorPower->setLayout(grpLayout);

}

void FormMotorSetting::InitGroupProjectorLight()
{
    m_grpProjectorLight = new QGroupBox(this);
    m_grpProjectorLight->setTitle("Projector Light Config");
    m_grpProjectorLight->setGeometry(m_grpProjectorPower->geometry().bottomLeft().x(),
                                     m_grpProjectorPower->geometry().bottomLeft().y()+m_space*2,
                                     m_grpWidth, m_grpHeight);
    m_proLightChannelName = new QLabel(this);
    m_proLightChannelName->setText("Channel");

    m_cmbProjectorLightChannel = new QComboBox(this);
    m_cmbProjectorLightChannel->addItem("2");

    m_proLightOpenName = new QLabel(this);
    m_proLightOpenName->setText("Open Level");

    m_proLightOpenLow = new QRadioButton(this);
    m_proLightOpenLow->setText("Low Level");
    m_proLightOpenLow->setChecked(true);

    m_proLightOpenHigh = new QRadioButton(this);
    m_proLightOpenHigh->setText("High Level");
    QGridLayout *grpLayout = new QGridLayout();
    grpLayout->addWidget(m_proLightChannelName, 0, 0, 1, 1);
    grpLayout->addWidget(m_cmbProjectorLightChannel, 0, 1, 1, 3);
    grpLayout->addWidget(m_proLightOpenName, 1, 0, 1, 1);
    grpLayout->addWidget(m_proLightOpenLow, 1, 1, 1, 1);
    grpLayout->addWidget(m_proLightOpenHigh, 1, 2, 1, 1);

    m_grpProjectorLight->setLayout(grpLayout);
}

void FormMotorSetting::InitGroupBuzzer()
{
    m_grpBuzzer = new QGroupBox(this);
    m_grpBuzzer->setTitle("Buzzer Config");
    m_grpBuzzer->setGeometry(m_grpProjectorLight->geometry().bottomLeft().x(),
                             m_grpProjectorLight->geometry().bottomLeft().y()+m_space*2,
                             m_grpWidth, m_grpHeight);
    m_buzzerChannelName = new QLabel(this);
    m_buzzerChannelName->setText("Channel");

    m_cmbBuzzerChannel = new QComboBox(this);
    m_cmbBuzzerChannel->addItem("3");

    m_buzzerOpenName = new QLabel(this);
    m_buzzerOpenName->setText("Open Level");

    m_buzzerOpenLow = new QRadioButton(this);
    m_buzzerOpenLow->setText("Low Level");
    m_buzzerOpenLow->setChecked(true);

    m_buzzerOpenHigh = new QRadioButton(this);
    m_buzzerOpenHigh->setText("High Level");
    QGridLayout *grpLayout = new QGridLayout();
    grpLayout->addWidget(m_buzzerChannelName, 0, 0, 1, 1);
    grpLayout->addWidget(m_cmbBuzzerChannel, 0, 1, 1, 3);
    grpLayout->addWidget(m_buzzerOpenName, 1, 0, 1, 1);
    grpLayout->addWidget(m_buzzerOpenLow, 1, 1, 1, 1);
    grpLayout->addWidget(m_buzzerOpenHigh, 1, 2, 1, 1);

    m_grpBuzzer->setLayout(grpLayout);
}

void FormMotorSetting::InitGroupWaitTime()
{
    m_grpWaitTime = new QGroupBox(this);
    m_grpWaitTime->setTitle("Wait Time Config");
    m_grpWaitTime->setGeometry(m_grpProjectorPower->geometry().topRight().x()+m_space*2,
                             m_grpProjectorPower->geometry().topRight().y(),
                             m_grpWidth-m_space*3, m_grpHeight*2);
    m_cureBottomTimeName = new QLabel(this);
    m_cureBottomTimeName->setText("CureBottom");

    m_cureBottomTime = new QLineEdit(this);
    m_cureBottomTime->setText("1000");

    m_printTimeName = new QLabel(this);
    m_printTimeName->setText("PrintTime");

    m_printTime = new QLineEdit(this);
    m_printTime->setText("1000");

    m_intervalTimeName = new QLabel(this);
    m_intervalTimeName->setText("Interval");

    m_intervalTime = new QLineEdit(this);
    m_intervalTime->setText("500");

    m_separateTimeName = new QLabel(this);
    m_separateTimeName->setText("Separate");

    m_separateTime = new QLineEdit(this);
    m_separateTime->setText("500");

    QGridLayout *grpLayout = new QGridLayout();
    grpLayout->addWidget(m_cureBottomTimeName,  0, 0, 1, 1);
    grpLayout->addWidget(m_cureBottomTime,      0, 1, 1, 2);
    grpLayout->addWidget(m_printTimeName,       1, 0, 1, 1);
    grpLayout->addWidget(m_printTime,           1, 1, 1, 2);
    grpLayout->addWidget(m_intervalTimeName,    2, 0, 1, 1);
    grpLayout->addWidget(m_intervalTime,        2, 1, 1, 2);
    grpLayout->addWidget(m_separateTimeName,    3, 0, 1, 1);
    grpLayout->addWidget(m_separateTime,        3, 1, 1, 2);
    m_grpWaitTime->setLayout(grpLayout);
}

void FormMotorSetting::InitTimeCoefficientAndButton()
{
    m_timeCoefficientName = new QLabel(this);
    m_timeCoefficientName->setText("Time Coefficient");
    m_timeCoefficientName->setGeometry(m_grpWaitTime->geometry().bottomLeft().x(),
                                       m_grpWaitTime->geometry().bottomLeft().y()+m_space*2,
                                       m_labelWidth+m_space*2, m_labelHeight);
    m_timeCoefficient = new QLineEdit(this);
    m_timeCoefficient->setText("1.4");
    m_timeCoefficient->setGeometry(m_timeCoefficientName->geometry().topRight().x() + m_space,
                                   m_timeCoefficientName->geometry().topRight().y(),
                                   m_labelWidth, m_labelHeight);

    m_btnSave = new QPushButton(this);
    m_btnSave->setText("save");
    m_btnSave->setGeometry(m_grpBuzzer->geometry().bottomLeft().x()+m_space*2,
                           m_grpBuzzer->geometry().bottomLeft().y()+m_space*2,
                           m_labelWidth*1.5, m_labelHeight*1.2);
}
