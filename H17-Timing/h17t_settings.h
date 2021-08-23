#ifndef H17T_SETTINGS_H
#define H17T_SETTINGS_H

#include <QDialog>
#include <QMessageBox>
#include <QDebug>

namespace Ui{
class H17T_Settings;
}

class H17T_Settings : public QDialog
{
    Q_OBJECT

public:
    explicit H17T_Settings(QWidget *parent = nullptr);
    ~H17T_Settings();

private:
    Ui::H17T_Settings *ui;

public slots:
    void onTabChanged();
};

#endif // H17T_SETTINGS_H
