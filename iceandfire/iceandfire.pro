QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    block.cpp \
    box.cpp \
    die.cpp \
    fireboy.cpp \
    icegirl.cpp \
    level.cpp \
    liquid.cpp \
    main.cpp \
    map.cpp \
    object.cpp \
    pic.cpp

HEADERS += \
    block.h \
    box.h \
    config.h \
    die.h \
    fireboy.h \
    icegirl.h \
    level.h \
    liquid.h \
    map.h \
    object.h \
    pic.h

FORMS +=

TRANSLATIONS += \
    iceandfire_zh_CN.ts
CONFIG += lrelease
CONFIG += embed_translations

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    image.qrc

DISTFILES += \
    image/_background2.png \
    image/dead.gif \
    image/dead.png \
    image/game_over.png \
    image/icegirl/icegirl_01.png \
    image/icegirl/icegirl_down.gif \
    image/icegirl/icegirl_run_left.gif \
    image/icegirl/icegirl_run_right.gif \
    image/icegirl/icegirl_stand.gif \
    image/icegirl/icegirl_up.gif \
    image/icegirl/run_body_01.png \
    image/icegirl/run_body_02.png \
    image/icegirl/run_body_03.png \
    image/icegirl/run_body_04.png \
    image/icegirl/run_body_05.png \
    image/icegirl/run_body_06.png \
    image/icegirl/run_body_07.png \
    image/icegirl/run_body_08.png \
    image/icegirl/run_head_01.png \
    image/icegirl/run_head_02.png \
    image/icegirl/run_head_03.png \
    image/icegirl/run_head_04.png \
    image/icegirl/run_head_05.png \
    image/icegirl/stand_body.png
