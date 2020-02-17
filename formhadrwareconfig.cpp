#include "formhadrwareconfig.h"
#include "ui_formhadrwareconfig.h"

FormHadrwareConfig::FormHadrwareConfig(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormHadrwareConfig)
{
    ui->setupUi(this);
    InitGroupBoxs();
}

FormHadrwareConfig::~FormHadrwareConfig()
{
    delete ui;
}

void FormHadrwareConfig::InitGroupBoxs()
{
    int grpSpace = 10;
    int grpWidth = 244;
    int projectoHeight = 200;
    m_grpProjector = new QGroupBox(this);
    m_grpProjector->setTitle("Projector");
    m_grpProjector->setGeometry(grpSpace, grpSpace, grpWidth, projectoHeight);
    InitProjectorGroup();

    m_grpWorkBench = new QGroupBox(this);
    m_grpWorkBench->setTitle("WorkBench");
    m_grpWorkBench->setGeometry(grpSpace, m_grpProjector->geometry().bottomLeft().y() + grpSpace,
                                grpWidth, 100);
    InitWorkBenchGroup();

    m_grpZAxis = new QGroupBox(this);
    m_grpZAxis->setTitle("Z-Axis");
    m_grpZAxis->setGeometry(grpSpace, m_grpWorkBench->geometry().bottomLeft().y() + grpSpace,
                            grpWidth, 150);
    InitZAxisGroup();

    m_grpMotor = new QGroupBox(this);
    m_grpMotor->setTitle("Motor");
    m_grpMotor->setGeometry(m_grpProjector->geometry().topRight().x() + grpSpace,
                            grpSpace, grpWidth, 260);
    InitMotorGroup();

    m_grpRAxis = new QGroupBox(this);
    m_grpRAxis->setTitle("R-Axis");
    m_grpRAxis->setGeometry(m_grpMotor->geometry().topLeft().x(),
                            m_grpMotor->geometry().bottomLeft().y() + grpSpace,
                            grpWidth, 200);
    InitRAxisGroup();
    m_grpPrintSetting = new QGroupBox(this);
    m_grpPrintSetting->setTitle("PrintingSetting");
    m_grpPrintSetting->setGeometry(m_grpMotor->geometry().topRight().x() + grpSpace,
                            grpSpace, grpWidth, 400);
    InitPrintingGroup();
    m_grpBottomSetting = new QGroupBox(this);
    m_grpBottomSetting->setTitle("BottomSetting");
    m_grpBottomSetting->setGeometry(m_grpPrintSetting->geometry().topRight().x() + grpSpace,
                            grpSpace, grpWidth, 400);
    InitBottomGroup();

    m_axisValue = new QLineEdit(this);
    m_axisValue->setGeometry(m_grpPrintSetting->geometry().bottomLeft().x()+grpSpace,
                             m_grpPrintSetting->geometry().bottomLeft().y()+grpSpace,
                             grpWidth/2, 30);
    m_btnReadZ = new QPushButton(this);
    m_btnReadZ->setText("Read Z-Axis");
    m_btnReadZ->setGeometry(m_axisValue->geometry().topRight().x()+grpSpace*2,
                            m_axisValue->geometry().topRight().y(),
                            grpWidth/2, 30);
    m_btnReadR = new QPushButton(this);
    m_btnReadR->setText("Read R Axis");
    m_btnReadR->setGeometry(m_btnReadZ->geometry().topRight().x()+grpSpace*2,
                            m_btnReadZ->geometry().topRight().y(),
                            grpWidth/2, 30);
    InitReadZRAxis();
}

void FormHadrwareConfig::InitProjectorGroup()
{
    m_projectorName = new QLabel(this);
    m_projectorName->setText("projector");
    m_projectorXName = new QLabel(this);
    m_projectorXName->setText("X");
    m_projectorYName = new QLabel(this);
    m_projectorYName->setText("Y");
    m_cmbProjector = new QComboBox(this);
    m_cmbProjector->addItem("Test Display1");
    m_projectX = new QLineEdit(this);
    m_projectX->setText("3840");
    m_projectY = new QLineEdit(this);
    m_projectY->setText("2160");
    QHBoxLayout *layoutP = new QHBoxLayout();
    QHBoxLayout *layoutXY = new QHBoxLayout();
    QVBoxLayout *layoutGrp = new QVBoxLayout();
    layoutP->addWidget(m_projectorName);
    layoutP->addWidget(m_cmbProjector);
    layoutXY->addWidget(m_projectorXName);
    layoutXY->addWidget(m_projectX);
    layoutXY->addWidget(m_projectorYName);
    layoutXY->addWidget(m_projectY);
    layoutGrp->addLayout(layoutP);
    layoutGrp->addLayout(layoutXY);
    m_grpProjector->setLayout(layoutGrp);
}

void FormHadrwareConfig::InitWorkBenchGroup()
{
    m_workBenchXName = new QLabel(this);
    m_workBenchXName->setText("X");
    m_workBenchYName = new QLabel(this);
    m_workBenchYName->setText("Y");
    m_workBenchX = new QLineEdit(this);
    m_workBenchX->setText("249.6");
    m_workBenchY = new QLineEdit(this);
    m_workBenchY->setText("140.4");
    QHBoxLayout *layoutGrp = new QHBoxLayout();
    layoutGrp->addWidget(m_workBenchXName);
    layoutGrp->addWidget(m_workBenchX);
    layoutGrp->addWidget(m_workBenchYName);
    layoutGrp->addWidget(m_workBenchY);
    m_grpWorkBench->setLayout(layoutGrp);
}

void FormHadrwareConfig::InitZAxisGroup()
{
    m_zAxisDistanceName = new QLabel(this);
    m_zAxisDistanceName->setText("Distance");
    m_zAxisDistance = new QLineEdit(this);
    m_zAxisDistance->setText("192.15");
    m_zAxisStepPluseName = new QLabel(this);
    m_zAxisStepPluseName->setText("Step Pluse");
    m_zAxisStepPluse = new QLineEdit(this);
    m_zAxisStepPluse->setText("1000");
    m_zAxisHeightPermittedName = new QLabel(this);
    m_zAxisHeightPermittedName->setText("Height Permitted");
    m_zAxisHeightPermitted = new QLineEdit(this);
    m_zAxisHeightPermitted->setText("30");
    m_cbAutoChange = new QCheckBox(this);
    m_cbAutoChange->setCheckState(Qt::Unchecked);
    m_cbAutoChange->setText("Auto Change");
    m_btnFindDistance = new QPushButton(this);
    m_btnFindDistance->setText("Find Distance");
    QGridLayout *layoutGrp = new QGridLayout();
    layoutGrp->addWidget(m_zAxisDistanceName,       0, 0, 1, 1);
    layoutGrp->addWidget(m_zAxisDistance,           0, 1, 1, 1);
    layoutGrp->addWidget(m_zAxisStepPluseName,      1, 0, 1, 1);
    layoutGrp->addWidget(m_zAxisStepPluse,          1, 1, 1, 1);
    layoutGrp->addWidget(m_zAxisHeightPermittedName,   2, 0, 1, 1);
    layoutGrp->addWidget(m_zAxisHeightPermitted,       2, 1, 1, 1);
    layoutGrp->addWidget(m_cbAutoChange,            3, 0, 1, 1);
    layoutGrp->addWidget(m_btnFindDistance,         3, 1, 1, 1);
    m_grpZAxis->setLayout(layoutGrp);
}

void FormHadrwareConfig::InitMotorGroup()
{
    m_motorAccelName = new QLabel(this);
    m_motorAccelName->setText("Accel Time");
    m_motorAccel = new QLineEdit(this);
    m_motorAccel->setText("0.01");
    m_motorDecelName = new QLabel(this);
    m_motorDecelName->setText("Decel Time");
    m_motorDecel = new QLineEdit(this);
    m_motorDecel->setText("0.01");
    m_motorResetSpeedName = new QLabel(this);
    m_motorResetSpeedName->setText("Reset Speed");
    m_motorResetSpeed = new QLineEdit(this);
    m_motorResetSpeed->setText("4");
    m_motorDryRunSpeedName = new QLabel(this);
    m_motorDryRunSpeedName->setText("Dry Run Speed");
    m_motorDryRunSpeed = new QLineEdit(this);
    m_motorDryRunSpeed->setText("5");
    QGridLayout *layoutGrp = new QGridLayout();
    layoutGrp->addWidget(m_motorAccelName,  0, 0, 1, 1);
    layoutGrp->addWidget(m_motorAccel,      0, 1, 1, 1);
    layoutGrp->addWidget(m_motorDecelName,  1, 0, 1, 1);
    layoutGrp->addWidget(m_motorDecel,      1, 1, 1, 1);
    layoutGrp->addWidget(m_motorResetSpeedName, 2, 0, 1, 1);
    layoutGrp->addWidget(m_motorResetSpeed,     2, 1, 1, 1);
    layoutGrp->addWidget(m_motorDryRunSpeedName, 3, 0, 1, 1);
    layoutGrp->addWidget(m_motorDryRunSpeed,     3, 1, 1, 1);
    m_grpMotor->setLayout(layoutGrp);
}

void FormHadrwareConfig::InitRAxisGroup()
{
    m_rAxisDistanceName = new QLabel(this);
    m_rAxisDistanceName->setText("Distance");
    m_rAxisDistance = new QLineEdit(this);
    m_rAxisDistance->setText("46");
    m_rAxisStepPluseName = new QLabel(this);
    m_rAxisStepPluseName->setText("Step Pluse");
    m_rAxisStepPluse = new QLineEdit(this);
    m_rAxisStepPluse->setText("1600");
    m_rAxisFallSpeedName = new QLabel(this);
    m_rAxisFallSpeedName->setText("Fall Speed");
    m_rAxisFallSpeed = new QLineEdit(this);
    m_rAxisFallSpeed->setText("5");
    m_rAxisRiseSpeedName = new QLabel(this);
    m_rAxisRiseSpeedName->setText("Rise Speed");
    m_rAxisRiseSpeed = new QLineEdit(this);
    m_rAxisRiseSpeed->setText("0");
    QGridLayout *layoutGrp = new QGridLayout();
    layoutGrp->addWidget(m_rAxisDistanceName,   0, 0, 1, 1);
    layoutGrp->addWidget(m_rAxisDistance,       0, 1, 1, 1);
    layoutGrp->addWidget(m_rAxisStepPluseName,  1, 0, 1, 1);
    layoutGrp->addWidget(m_rAxisStepPluse,      1, 1, 1, 1);
    layoutGrp->addWidget(m_rAxisFallSpeedName,  2, 0, 1, 1);
    layoutGrp->addWidget(m_rAxisFallSpeed,      2, 1, 1, 1);
    layoutGrp->addWidget(m_rAxisRiseSpeedName,  3, 0, 1, 1);
    layoutGrp->addWidget(m_rAxisRiseSpeed,      3, 1, 1, 1);
    m_grpRAxis->setLayout(layoutGrp);
}

void FormHadrwareConfig::InitPrintingGroup()
{
    m_printingApproachDistanceName = new QLabel(this);
    m_printingApproachDistanceName->setText("Approach Distance");
    m_printingApproachDistance = new QLineEdit(this);
    m_printingApproachDistance->setText("3");
    m_printingApproachSpeedName = new QLabel(this);
    m_printingApproachSpeedName->setText("Approach Speed");
    m_printingApproachSpeed = new QLineEdit(this);
    m_printingApproachSpeed->setText("3");
    m_printingContactDistanceName = new QLabel(this);
    m_printingContactDistanceName->setText("contact Distance");
    m_printingContactDistance = new QLineEdit(this);
    m_printingContactDistance->setText("1");
    m_printingContactSpeedName = new QLabel(this);
    m_printingContactSpeedName->setText("Contact Speed");
    m_printingContactSpeed = new QLineEdit(this);
    m_printingContactSpeed->setText("0.5");
    m_printingSeparationDistanceName = new QLabel(this);
    m_printingSeparationDistanceName->setText("Separation Distance");
    m_printingSeparationDistance = new QLineEdit(this);
    m_printingSeparationDistance->setText("3");
    m_printingSeparatingSpeedName = new QLabel(this);
    m_printingSeparatingSpeedName->setText("Separate Speed");
    m_printingSeparatingSpeed = new QLineEdit(this);
    m_printingSeparatingSpeed->setText("0.5");
    m_printingRollbackDistanceName = new QLabel(this);
    m_printingRollbackDistanceName->setText("Rollback Distance");
    m_printingRollbackDistance = new QLineEdit(this);
    m_printingRollbackDistance->setText("3");
    m_printingRollbackSpeedName = new QLabel(this);
    m_printingRollbackSpeedName->setText("Rollback Speed");
    m_printingRollbackSpeed = new QLineEdit(this);
    m_printingRollbackSpeed->setText("3");
    QGridLayout *layoutGrp = new QGridLayout();
    layoutGrp->addWidget(m_printingApproachDistanceName, 0, 0, 1, 1);
    layoutGrp->addWidget(m_printingApproachDistance, 0, 1, 1, 1);
    layoutGrp->addWidget(m_printingApproachSpeedName, 1, 0, 1, 1);
    layoutGrp->addWidget(m_printingApproachSpeed, 1, 1, 1, 1);
    layoutGrp->addWidget(m_printingContactDistanceName, 2, 0, 1, 1);
    layoutGrp->addWidget(m_printingContactDistance, 2, 1, 1, 1);
    layoutGrp->addWidget(m_printingContactSpeedName, 3, 0, 1, 1);
    layoutGrp->addWidget(m_printingContactSpeed, 3, 1, 1, 1);
    layoutGrp->addWidget(m_printingSeparationDistanceName, 4, 0, 1, 1);
    layoutGrp->addWidget(m_printingSeparationDistance, 4, 1, 1, 1);
    layoutGrp->addWidget(m_printingSeparatingSpeedName, 5, 0, 1, 1);
    layoutGrp->addWidget(m_printingSeparatingSpeed, 5, 1, 1, 1);
    layoutGrp->addWidget(m_printingRollbackDistanceName, 6, 0, 1, 1);
    layoutGrp->addWidget(m_printingRollbackDistance, 6, 1, 1, 1);
    layoutGrp->addWidget(m_printingRollbackSpeedName, 7, 0, 1, 1);
    layoutGrp->addWidget(m_printingRollbackSpeed, 7, 1, 1, 1);
    m_grpPrintSetting->setLayout(layoutGrp);
}

void FormHadrwareConfig::InitBottomGroup()
{
    m_bottomApproachDistanceName = new QLabel(this);
    m_bottomApproachDistanceName->setText("Approach Distance");
    m_bottomApproachDistance = new QLineEdit(this);
    m_bottomApproachDistance->setText("7");
    m_bottomApproachSpeedName = new QLabel(this);
    m_bottomApproachSpeedName->setText("Approach Speed");
    m_bottomApproachSpeed = new QLineEdit(this);
    m_bottomApproachSpeed->setText("5");
    m_bottomContactDistanceName = new QLabel(this);
    m_bottomContactDistanceName->setText("contact Distance");
    m_bottomContactDistance = new QLineEdit(this);
    m_bottomContactDistance->setText("1");
    m_bottomContactSpeedName = new QLabel(this);
    m_bottomContactSpeedName->setText("Contact Speed");
    m_bottomContactSpeed = new QLineEdit(this);
    m_bottomContactSpeed->setText("0.5");
    m_bottomSeparationDistanceName = new QLabel(this);
    m_bottomSeparationDistanceName->setText("Separation Distance");
    m_bottomSeparationDistance = new QLineEdit(this);
    m_bottomSeparationDistance->setText("3");
    m_bottomSeparatingSpeedName = new QLabel(this);
    m_bottomSeparatingSpeedName->setText("Separate Speed");
    m_bottomSeparatingSpeed = new QLineEdit(this);
    m_bottomSeparatingSpeed->setText("0.5");
    m_bottomRollbackDistanceName = new QLabel(this);
    m_bottomRollbackDistanceName->setText("Rollback Distance");
    m_bottomRollbackDistance = new QLineEdit(this);
    m_bottomRollbackDistance->setText("5");
    m_bottomRollbackSpeedName = new QLabel(this);
    m_bottomRollbackSpeedName->setText("Rollback Speed");
    m_bottomRollbackSpeed = new QLineEdit(this);
    m_bottomRollbackSpeed->setText("5");
    QGridLayout *layoutGrp = new QGridLayout();
    layoutGrp->addWidget(m_bottomApproachDistanceName, 0, 0, 1, 1);
    layoutGrp->addWidget(m_bottomApproachDistance, 0, 1, 1, 1);
    layoutGrp->addWidget(m_bottomApproachSpeedName, 1, 0, 1, 1);
    layoutGrp->addWidget(m_bottomApproachSpeed, 1, 1, 1, 1);
    layoutGrp->addWidget(m_bottomContactDistanceName, 2, 0, 1, 1);
    layoutGrp->addWidget(m_bottomContactDistance, 2, 1, 1, 1);
    layoutGrp->addWidget(m_bottomContactSpeedName, 3, 0, 1, 1);
    layoutGrp->addWidget(m_bottomContactSpeed, 3, 1, 1, 1);
    layoutGrp->addWidget(m_bottomSeparationDistanceName, 4, 0, 1, 1);
    layoutGrp->addWidget(m_bottomSeparationDistance, 4, 1, 1, 1);
    layoutGrp->addWidget(m_bottomSeparatingSpeedName, 5, 0, 1, 1);
    layoutGrp->addWidget(m_bottomSeparatingSpeed, 5, 1, 1, 1);
    layoutGrp->addWidget(m_bottomRollbackDistanceName, 6, 0, 1, 1);
    layoutGrp->addWidget(m_bottomRollbackDistance, 6, 1, 1, 1);
    layoutGrp->addWidget(m_bottomRollbackSpeedName, 7, 0, 1, 1);
    layoutGrp->addWidget(m_bottomRollbackSpeed, 7, 1, 1, 1);
    m_grpBottomSetting->setLayout(layoutGrp);
}

void FormHadrwareConfig::InitReadZRAxis()
{

}
