#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTabWidget>
#include <QGridLayout>
#include <QHBoxLayout>

#include "formhadrwareconfig.h"
#include "formserialportsetting.h"
#include "formprojectorsetting.h"
#include "formmatrialsetting.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void InitSystemTabWidget();

private:
    Ui::MainWindow *ui;
    QTabWidget *m_systemSettingTab;
    QHBoxLayout *m_mainLayout;
    FormHadrwareConfig *m_hwConfig;
    FormSerialPortSetting *m_spConfig;
    FormProjectorSetting *m_pjConfig;
    FormMatrialSetting *m_msConfig;
};
#endif // MAINWINDOW_H
