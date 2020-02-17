#ifndef FORMSERIALPORTSETTING_H
#define FORMSERIALPORTSETTING_H

#include <QWidget>
#include <QGroupBox>
#include <QComboBox>
#include <QLabel>
#include <QGridLayout>

namespace Ui {
class FormSerialPortSetting;
}

class FormSerialPortSetting : public QWidget
{
    Q_OBJECT

public:
    explicit FormSerialPortSetting(QWidget *parent = nullptr);
    ~FormSerialPortSetting();
    void InitGroupMotor();
    void InitGroupProjector();
    void InitGroupTray();
private:
    Ui::FormSerialPortSetting *ui;
    QGroupBox *m_grpMotor, *m_grpProjector, *m_grpTray;
    /* motor */
    QComboBox *m_motorSerial, *m_motorSpeed, *m_motorDataBits, *m_motorStopBits, *m_motorParity;
    QLabel *m_motorSerialName, *m_motorSpeedName, *m_motorDataBitsName, *m_motorStopBitsName, *m_motorParityName;
    /* projector */
    QComboBox *m_projectorSerial, *m_projectorSpeed, *m_projectorDataBits, *m_projectorStopBits, *m_projectorParity;
    QLabel *m_projectorSerialName, *m_projectorSpeedName, *m_projectorDataBitsName, *m_projectorStopBitsName, *m_projectorParityName;
    /* tray */
    QComboBox *m_traySerial, *m_traySpeed, *m_trayDataBits, *m_trayStopBits, *m_trayParity;
    QLabel *m_traySerialName, *m_traySpeedName, *m_trayDataBitsName, *m_trayStopBitsName, *m_trayParityName;
};

#endif // FORMSERIALPORTSETTING_H
