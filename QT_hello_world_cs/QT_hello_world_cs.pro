QT       += core gui
QT       += multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17


# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    banished.cpp \
    dialog.cpp \
    dialogue.cpp \
    effectaudio.cpp \
    end.cpp \
    fire.cpp \
    getmagic.cpp \
    getsword.cpp \
    iceiron.cpp \
    iceplace.cpp \
    information.cpp \
    ironmanhouse.cpp \
    load.cpp \
    magichouse.cpp \
    main.cpp \
    mainwindow.cpp \
    map.cpp \
    oliver.cpp \
    outsea.cpp \
    pass.cpp \
    rolig_sea.cpp \
    rolig_village.cpp \
    settings.cpp \
    shop.cpp \
    status_show.cpp

HEADERS += \
    banished.h \
    dialog.h \
    dialogue.h \
    effectaudio.h \
    end.h \
    file.h \
    fire.h \
    getmagic.h \
    getsword.h \
    iceiron.h \
    iceplace.h \
    information.h \
    ironmanhouse.h \
    load.h \
    magichouse.h \
    mainwindow.h \
    map.h \
    oliver.h \
    outsea.h \
    pass.h \
    rolig_sea.h \
    rolig_village.h \
    set_context.h \
    settings.h \
    shop.h \
    status_show.h

FORMS += \
    banished.ui \
    dialog.ui \
    end.ui \
    fire.ui \
    getmagic.ui \
    getsword.ui \
    iceiron.ui \
    iceplace.ui \
    information.ui \
    ironmanhouse.ui \
    load.ui \
    magichouse.ui \
    mainwindow.ui \
    map.ui \
    outsea.ui \
    pass.ui \
    rolig_sea.ui \
    rolig_village.ui \
    settings.ui \
    shop.ui \
    status_show.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    img.qrc


