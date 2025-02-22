#include "converterwgt.h"

#include <QApplication>
#include <QIcon>
#include <QScreen>
#include "settings.h"

#define INI_FILE_NAME "currency.ini"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setStyle("fusion");

    Settings::load(INI_FILE_NAME);

    ConverterWgt w;
    w.setWindowTitle("Конвертер валют");
    w.setWindowIcon(QIcon("://icons/icon.svg"));
    QRect desktopRect = QGuiApplication::primaryScreen()->availableGeometry();
    QPoint center = desktopRect.center();
    w.move(center.x() - w.width() * 0.5, center.y() - w.height() * 0.5);
    w.show();

    return a.exec();
}
