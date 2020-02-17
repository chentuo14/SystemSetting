#ifndef FORMHADRWARECONFIG_H
#define FORMHADRWARECONFIG_H

#include <QWidget>
#include <QGroupBox>
#include <QLabel>
#include <QComboBox>
#include <QLineEdit>
#include <QCheckBox>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
namespace Ui {
class FormHadrwareConfig;
}

class FormHadrwareConfig : public QWidget
{
    Q_OBJECT

public:
    explicit FormHadrwareConfig(QWidget *parent = nullptr);
    ~FormHadrwareConfig();
private:
    void InitGroupBoxs();
    void InitProjectorGroup();
    void InitWorkBenchGroup();
    void InitZAxisGroup();
    void InitMotorGroup();
    void InitRAxisGroup();
    void InitPrintingGroup();
    void InitBottomGroup();
    void InitReadZRAxis();
private:
    Ui::FormHadrwareConfig *ui;
    QGroupBox *m_grpProjector, *m_grpWorkBench, *m_grpZAxis, *m_grpMotor, *m_grpRAxis, *m_grpPrintSetting, *m_grpBottomSetting;
    /* projector */
    QLabel *m_projectorName, *m_projectorXName, *m_projectorYName;
    QComboBox *m_cmbProjector;
    QLineEdit *m_projectX, *m_projectY;
    /* workbench */
    QLabel *m_workBenchXName, *m_workBenchYName;
    QLineEdit *m_workBenchX, *m_workBenchY;
    /* z-Axis */
    QLabel *m_zAxisDistanceName, *m_zAxisStepPluseName, *m_zAxisHeightPermittedName;
    QLineEdit *m_zAxisDistance, *m_zAxisStepPluse, *m_zAxisHeightPermitted;
    QCheckBox *m_cbAutoChange;
    QPushButton *m_btnFindDistance;
    /* motor */
    QLabel *m_motorAccelName, *m_motorDecelName, *m_motorResetSpeedName, *m_motorDryRunSpeedName;
    QLineEdit *m_motorAccel, *m_motorDecel, *m_motorResetSpeed, *m_motorDryRunSpeed;
    /* R-Axis */
    QLabel *m_rAxisDistanceName, *m_rAxisStepPluseName, *m_rAxisFallSpeedName, *m_rAxisRiseSpeedName;
    QLineEdit *m_rAxisDistance, *m_rAxisStepPluse, *m_rAxisFallSpeed, *m_rAxisRiseSpeed;
    /* printing */
    QLabel *m_printingApproachDistanceName, *m_printingApproachSpeedName, *m_printingContactDistanceName, *m_printingContactSpeedName,
        *m_printingSeparationDistanceName, *m_printingSeparatingSpeedName, *m_printingRollbackDistanceName, *m_printingRollbackSpeedName;
    QLineEdit *m_printingApproachDistance, *m_printingApproachSpeed, *m_printingContactDistance, *m_printingContactSpeed,
    *m_printingSeparationDistance, *m_printingSeparatingSpeed, *m_printingRollbackDistance, *m_printingRollbackSpeed;
    /* bottom */
    QLabel *m_bottomApproachDistanceName, *m_bottomApproachSpeedName, *m_bottomContactDistanceName, *m_bottomContactSpeedName,
        *m_bottomSeparationDistanceName, *m_bottomSeparatingSpeedName, *m_bottomRollbackDistanceName, *m_bottomRollbackSpeedName;
    QLineEdit *m_bottomApproachDistance, *m_bottomApproachSpeed, *m_bottomContactDistance, *m_bottomContactSpeed,
    *m_bottomSeparationDistance, *m_bottomSeparatingSpeed, *m_bottomRollbackDistance, *m_bottomRollbackSpeed;
    /* read z r axis */
    QLineEdit *m_axisValue;
    QPushButton *m_btnReadZ, *m_btnReadR;
};

#endif // FORMHADRWARECONFIG_H
