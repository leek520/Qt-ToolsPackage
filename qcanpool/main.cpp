#include "fancywindow.h"
#include "fancydialog.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    FancyWindow w;
    w.show();
    return a.exec();
}
