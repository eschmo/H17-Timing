#include "h17t_main.h"
#include "ui_h17t_main.h"



H17T_Main::H17T_Main(QWidget *parent)
    : QMainWindow(parent, Qt::CustomizeWindowHint)
    , ui(new Ui::H17T_Main)
{
    ui->setupUi(this);
    setWindowFlags(Qt::FramelessWindowHint| Qt::WindowSystemMenuHint);
    connect(ui->Btn_EXIT_Main,SIGNAL(clicked()),this,SLOT(onExit()));
    connect(ui->Btn_Settings_Main,SIGNAL(clicked()),this,SLOT(onSettings()));
    thr_Main.start();
}


H17T_Main::~H17T_Main()
{
    thr_Main.wait();
    delete ui;
}

void H17T_Main::resizeEvent(QResizeEvent* event)
{
    qDebug("ResizeEvent");

    moveControls();

    QMainWindow::resizeEvent(event);
}

void H17T_Main::moveControls()
{
    //get actual environment data
    temp_width = ui->centralwidget->width();
    temp_height = ui->centralwidget->height();
    temp_Btn_Settings_Main_width = ui->Btn_Settings_Main->width();
    temp_Btn_Settings_Main_height = ui->Btn_Settings_Main->height();
    temp_Btn_EXIT_Main_width = ui->Btn_EXIT_Main->width();
    temp_Btn_EXIT_Main_height = ui->Btn_EXIT_Main->height();

    //move Buttons
    ui->Btn_Settings_Main->move(15,temp_height-(temp_Btn_Settings_Main_height+15));
    ui->Btn_EXIT_Main->move(temp_width-(temp_Btn_EXIT_Main_width+15),temp_height-(temp_Btn_EXIT_Main_height+15));

}

void H17T_Main::onExit()
{
    QMessageBox msgBox;
    msgBox.setText("EXIT H17-Timing");
    msgBox.setWindowFlag(Qt::FramelessWindowHint);
    msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
    msgBox.setDefaultButton(QMessageBox::Yes);
    int ret = msgBox.exec();

    if(ret==QMessageBox::Yes) close();
}

void H17T_Main::onSettings()
{
    SettingsForm = new H17T_Settings;
    SettingsForm->setModal(true);
    SettingsForm->setWindowFlags(Qt::FramelessWindowHint| Qt::WindowSystemMenuHint);
    frm_Settings.setupUi(SettingsForm);
    SettingsForm->show();


}
