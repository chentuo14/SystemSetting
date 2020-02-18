#include "formmatrialsetting.h"
#include "ui_formmatrialsetting.h"

FormMatrialSetting::FormMatrialSetting(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormMatrialSetting)
{
    ui->setupUi(this);


    //位置
    int space = 10;
    int tableWidth = 850;
    int tableHeight = 400;
    m_matrialTable = new QTableView(this);
    m_standItemModel = new QStandardItemModel(this);
    m_matrialTable->setGeometry(space, space, tableWidth, tableHeight);

    int btnWidth = 100;
    int btnHeight = 50;
    m_btnAdd = new QPushButton(this);
    m_btnAdd->setText("Add");
    m_btnAdd->setGeometry(m_matrialTable->geometry().topRight().x()+space*3,
                          m_matrialTable->geometry().topRight().y(),
                          btnWidth, btnHeight);
    m_btnDel = new QPushButton(this);
    m_btnDel->setText("Del");
    m_btnDel->setGeometry(m_btnAdd->geometry().bottomLeft().x(),
                          m_btnAdd->geometry().bottomLeft().y()+space*3,
                          btnWidth, btnHeight);
    m_btnChg = new QPushButton(this);
    m_btnChg->setText("Change");
    m_btnChg->setGeometry(m_btnDel->geometry().bottomLeft().x(),
                          m_btnDel->geometry().bottomLeft().y()+space*3,
                          btnWidth, btnHeight);
    m_btnSave = new QPushButton(this);
    m_btnSave->setText("Save");
    m_btnSave->setGeometry(m_btnChg->geometry().bottomLeft().x(),
                          m_btnChg->geometry().bottomLeft().y()+space*3,
                          btnWidth, btnHeight);

    m_info = new QLabel(this);
    m_info->setText("Time:ms");
    m_info->setGeometry(m_matrialTable->geometry().bottomRight().x()+space*3,
                        m_matrialTable->geometry().bottomRight().y()-space*3,
                        80, 20);

    //
    m_standItemModel->setColumnCount(7);
    m_standItemModel->setHeaderData(0, Qt::Horizontal, "Matrial Name");
    m_standItemModel->setHeaderData(1, Qt::Horizontal, "Bottom Light Intensity");
    m_standItemModel->setHeaderData(2, Qt::Horizontal, "Bottom Light Time(ms)");
    m_standItemModel->setHeaderData(3, Qt::Horizontal, "Bottom Layers");
    m_standItemModel->setHeaderData(4, Qt::Horizontal, "Light Intensity");
    m_standItemModel->setHeaderData(5, Qt::Horizontal, "Light Time");
    m_standItemModel->setHeaderData(6, Qt::Horizontal, "Count");
    //
    QStandardItem *standItem = new QStandardItem();
    m_standItemModel->setItem(0, 0, new QStandardItem("HT_300"));
    m_standItemModel->setItem(0, 1, new QStandardItem("100"));
    m_standItemModel->setItem(0, 2, new QStandardItem("12000"));
    m_standItemModel->setItem(0, 3, new QStandardItem("10"));
    m_standItemModel->setItem(0, 4, new QStandardItem("120"));
    m_standItemModel->setItem(0, 5, new QStandardItem("5000"));
    m_standItemModel->setItem(0, 6, new QStandardItem("1"));
    m_matrialTable->setModel(m_standItemModel);
}

FormMatrialSetting::~FormMatrialSetting()
{
    delete ui;
}
