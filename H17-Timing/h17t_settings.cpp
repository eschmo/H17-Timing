#include "h17t_settings.h"
#include "ui_h17t_settings.h"

H17T_Settings::H17T_Settings(QWidget *parent) :
    QDialog(parent, Qt::CustomizeWindowHint),
    ui(new Ui::H17T_Settings)
{
    ui->setupUi(this);

    qDebug() << "Tab Connect:" <<connect(ui->tabWidget,&QTabWidget::currentChanged,this,&H17T_Settings::onTabChanged);
    qDebug() << "Button Connect:" <<connect(ui->Btn_Save_Settings,&QPushButton::clicked,this,&H17T_Settings::close);

}

void H17T_Settings::onTabChanged()
{
    QString curWidget = ui->tabWidget->currentWidget()->objectName();

    qDebug("Ausgeloest");
    ui->debugLabel->setText("Haut hin");

}

H17T_Settings::~H17T_Settings()
{
    delete ui;
}
