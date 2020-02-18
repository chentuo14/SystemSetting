#ifndef FORMMOTORSETTING_H
#define FORMMOTORSETTING_H

#include <QWidget>
#include <QLabel>
#include <QComboBox>
#include <QCheckBox>
#include <QRadioButton>
#include <QGroupBox>
#include <QLineEdit>
#include <QHBoxLayout>
#include <QButtonGroup>
#include <QGridLayout>
#include <QPushButton>

namespace Ui {
class FormMotorSetting;
}

class FormMotorSetting : public QWidget
{
    Q_OBJECT

public:
    explicit FormMotorSetting(QWidget *parent = nullptr);
    ~FormMotorSetting();
    void InitAxisName();
    void InitAxisChannel();
    void InitDriverMode();
    void InitPostiveLevel();
    void InitNegativeLevel();
    void InitResetDirection();
    void InitRestLevel();
    void InitGroupProjectorPower();
    void InitGroupProjectorLight();
    void InitGroupBuzzer();
    void InitGroupWaitTime();
    void InitTimeCoefficientAndButton();
private:
    Ui::FormMotorSetting *ui;
    int m_space = 10;
    int m_labelWidth = 100;
    int m_labelHeight = 30;
    int m_cmbWidth = 200;
    int m_cmbHeight = 30;
    int m_grpWidth = 300;
    int m_grpHeight = 100;

    QLabel *m_axisNameName, *m_axisChannelName, *m_driverModeName, *m_positiveLimitName,
        *m_negativeLimitName, *m_resetDirectionName, *m_resetLevelName;
    /* AxisName AxisChannel */
    QComboBox *m_cmbAxisName, *m_cmbAxisChannel, *m_cmbDriverMode;
    QCheckBox *m_ckbAxisName;
    /* Positvie Negative Reset RadioButtons */
    QButtonGroup *m_positiveLevelGrp, *m_negativeLevelGrp,
        *m_resetDirectionGrp, *m_resetLevelGrp;
    QRadioButton *m_positiveLevelLow, *m_positiveLevelHigh;
    QRadioButton *m_negativeLevelLow, *m_negativeLevelHigh;
    QRadioButton *m_resetDirectionNegative, *m_resetDirectionPositive;
    QRadioButton *m_resetLevelLow, *m_resetLevelHigh;
    /* QGroupBoxs */
    QGroupBox *m_grpProjectorPower, *m_grpProjectorLight, *m_grpBuzzer, *m_grpWaitTime;
    /* Projector Power and Light */
    QLabel *m_projectorPowerChannelName, *m_projectorPowerOpenName;
    QComboBox *m_cmbProjectorPowerChannel;
    QRadioButton *m_projectorPowerOpenLow, *m_projectorPowerOpenHigh;
    QLabel *m_proLightChannelName, *m_proLightOpenName;
    QComboBox *m_cmbProjectorLightChannel;
    QRadioButton *m_proLightOpenLow, *m_proLightOpenHigh;
    /* Buzzer */
    QLabel *m_buzzerChannelName, *m_buzzerOpenName;
    QComboBox *m_cmbBuzzerChannel;
    QRadioButton *m_buzzerOpenLow, *m_buzzerOpenHigh;
    /* Wait Time */
    QLabel *m_cureBottomTimeName, *m_printTimeName, *m_intervalTimeName, *m_separateTimeName;
    QLineEdit *m_cureBottomTime, *m_printTime, *m_intervalTime, *m_separateTime;
    /* Time Coefficient */
    QLabel *m_timeCoefficientName;
    QLineEdit *m_timeCoefficient;
    QPushButton *m_btnSave;
};

#endif // FORMMOTORSETTING_H
