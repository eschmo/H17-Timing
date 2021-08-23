#ifndef H17T_MAIN_H
#define H17T_MAIN_H

#include "ui_h17t_settings.h"
#include "h17t_settings.h"
#include <QMainWindow>
#include <QDebug>
#include <QTime>
#include "main_thread.h"
#include <QMessageBox>


QT_BEGIN_NAMESPACE
namespace Ui { class H17T_Main; }
QT_END_NAMESPACE

class H17T_Main : public QMainWindow
{
    Q_OBJECT

public:
    H17T_Main(QWidget *parent = nullptr);
    ~H17T_Main();

private:
    int temp_width;
    int temp_height;
    int temp_Btn_Settings_Main_width;
    int temp_Btn_Settings_Main_height;
    int temp_Btn_EXIT_Main_width;
    int temp_Btn_EXIT_Main_height;
    main_thread thr_Main;
    Ui::H17T_Main *ui;

    QDialog *SettingsForm; //<--------- Pointer auf QDialog
    Ui::H17T_Settings frm_Settings;    //<--------- Neuer Dialog
    void resizeEvent(QResizeEvent* event);

    void moveControls();

public slots:
    void onExit();
    void onSettings();
};
#endif // H17T_MAIN_H
