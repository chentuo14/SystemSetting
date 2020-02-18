#ifndef FORMMATRIALSETTING_H
#define FORMMATRIALSETTING_H

#include <QWidget>
#include <QTableView>
#include <QStandardItemModel>
#include <QPushButton>
#include <QLabel>

namespace Ui {
class FormMatrialSetting;
}

class FormMatrialSetting : public QWidget
{
    Q_OBJECT

public:
    explicit FormMatrialSetting(QWidget *parent = nullptr);
    ~FormMatrialSetting();

private:
    Ui::FormMatrialSetting *ui;
    QTableView *m_matrialTable;
    QStandardItemModel *m_standItemModel;
    QPushButton *m_btnAdd, *m_btnDel, *m_btnChg, *m_btnSave;
    QLabel *m_info;
};

#endif // FORMMATRIALSETTING_H
