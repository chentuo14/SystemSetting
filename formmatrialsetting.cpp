#include "formmatrialsetting.h"
#include "ui_formmatrialsetting.h"

FormMatrialSetting::FormMatrialSetting(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormMatrialSetting)
{
    ui->setupUi(this);

    int space = 10;
    int tableWidth = 800;
    int tableHeight = 400;
    m_matrialTable = new QTableView(this);
    m_standItemModel = new QStandardItemModel(this);
    m_matrialTable->setGeometry(space, space, tableWidth, tableHeight);
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
    QStandardItem *standItem = new QStandardItem()

    m_matrialTable->setModel(m_standItemModel);
}

FormMatrialSetting::~FormMatrialSetting()
{
    delete ui;
}
