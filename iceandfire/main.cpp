#include "level.h"

#include <windows.h>
#include <windows.system.h>
#include <QApplication>
#include <QLocale>
#include <QTranslator>
#include <QResource>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QTranslator translator;
    const QStringList uiLanguages = QLocale::system().uiLanguages();
    for (const QString &locale : uiLanguages) {
        const QString baseName = "iceandfire_" + QLocale(locale).name();
        if (translator.load(":/i18n/" + baseName)) {
            a.installTranslator(&translator);
            break;
        }
    }
    level *h = new level(nullptr, 0) ;
    h -> show() ;
    return a.exec();
}
