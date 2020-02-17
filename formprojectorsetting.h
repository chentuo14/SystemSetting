#ifndef FORMPROJECTORSETTING_H
#define FORMPROJECTORSETTING_H

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>

namespace Ui {
class FormProjectorSetting;
}

class FormProjectorSetting : public QWidget
{
    Q_OBJECT

public:
    explicit FormProjectorSetting(QWidget *parent = nullptr);
    ~FormProjectorSetting();
    void InitProjectorSetting();
    void InitControlsPosition();
private:
    Ui::FormProjectorSetting *ui;
    QLabel *m_proAName, *m_proBName, *m_proCName, *m_proDName;
    QLabel *m_proPrintStartName;
    QLineEdit *m_proA, *m_proB, *m_proC, *m_proD, *m_proPrintStart;
    QPushButton *m_btnConfig, *m_btnSet, *m_btnRead;
    QLabel *m_proTAName, *m_proTBName, *m_proTCName, *m_proTDName;
    QLabel *m_proTName, *m_proMaxTName;
    QLineEdit *m_proTA, *m_proTB, *m_proTC, *m_proTD, *m_proT, *m_proMaxT;
};

#endif // FORMPROJECTORSETTING_H
