#include "jennydigiclock.h"

#include <QApplication>


#include <QApplication>
#include <QSettings>
#include <QDebug>

int main(int argc, char *argv[])
{
    QSettings settings("GUIProgramming2022", "JennyDigitalClock");
    QApplication a(argc, argv);
    a.setOrganizationName("GUIProgramming2022");
    a.setApplicationName("JennyDigitalClock");
    JennyDigiClock w;
    w.show();
    return a.exec();
}
