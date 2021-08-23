#ifndef MAIN_THREAD_H
#define MAIN_THREAD_H
#include <QThread>
#include <QTime>
#include <QDebug>
#include <QObject>
#include <QMainWindow>

class main_thread : public QThread
{

public:
    void setMainWindow(QMainWindow tmp_MWID);
private:
    //QMainWindow mwt_MWID;
    void run();
};

#endif // MAIN_THREAD_H
