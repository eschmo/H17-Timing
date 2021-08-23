#include "main_thread.h"

void main_thread::run()
{

    qDebug() << QTime::currentTime().toString() << "Main Thread active" << "Main Thread active" << thread()->currentThreadId();




}

void main_thread::setMainWindow(QMainWindow tmp_MWID)
{
//    mwt_MWID = tmp_MWID;
}
