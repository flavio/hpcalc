#include <QApplication>
#include "DlgMain.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    
    DlgMain mainWin;
    mainWin.show();
    
    if (argc > 1)
        mainWin.init(argv[1]);
    else
        mainWin.init();

    return app.exec();
}
