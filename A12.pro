#-------------------------------------------------
#
# Project created by QtCreator 2018-01-14T21:32:18
#
#-------------------------------------------------

QT       += core gui
QT       += sql
QT       += network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = A12
TEMPLATE = app
#//DEFINES +=HAVE_CONFIG_H

SOURCES += main.cpp\
        mainwindow.cpp \
    rootdialog.cpp \
    cali.cpp \
    TestInput_Cursor/padbase.cpp \
    TestInput_Cursor/keyboard.cpp \
    TestInput_Cursor/inputmethod.cpp \
    TestInput_Cursor/HanziManager.cpp \
    TestInput_Cursor/formsymbolpad.cpp \
    TestInput_Cursor/formnumpad.cpp \
    TestInput_Cursor/formhanzitable.cpp \
    TestInput_Cursor/formhanziselector.cpp \
    TestInput_Cursor/dialogtooltip.cpp \
    configsetting.cpp \
    printer.cpp \
    numkeyboard.cpp \
    business.cpp \
    qrcode/split.c \
    qrcode/rscode.c \
    qrcode/qrspec.c \
    qrcode/qrinput.c \
    qrcode/qrencode.c \
    qrcode/mqrspec.c \
    qrcode/mmask.c \
    qrcode/mask.c \
    qrcode/bitstream.c \
    about.cpp \
    mysqlsheet.cpp \
    dataexport.cpp \
    networkcommunication.cpp \
    remotemysql.cpp \
    udpcommunication.cpp \
    usermodify.cpp \
    userlogindialog.cpp \
    user.cpp \
    adthread.cpp \
    loadbig.cpp \
    buzzer.cpp \
    commthread.cpp \
    printport.cpp \
    printthread.cpp \
    json/serializerrunnable.cpp \
    json/serializer.cpp \
    json/qobjecthelper.cpp \
    json/parserrunnable.cpp \
    json/parser.cpp \
    json/json_scanner.cpp \
    json/json_scanner.cc \
    json/json_parser.cc \
    ethernethttp.cpp

HEADERS  += mainwindow.h \
    rootdialog.h \
    cali.h \
    TestInput_Cursor/padbase.h \
    TestInput_Cursor/keyboard.h \
    TestInput_Cursor/inputmethod.h \
    TestInput_Cursor/HanziManager.h \
    TestInput_Cursor/formsymbolpad.h \
    TestInput_Cursor/formnumpad.h \
    TestInput_Cursor/formhanzitable.h \
    TestInput_Cursor/formhanziselector.h \
    TestInput_Cursor/dialogtooltip.h \
    TestInput_Cursor/ChineseTranslator.h \
    configsetting.h \
    printer.h \
    numkeyboard.h \
    business.h \
    GlobalVarible.h \
    qrcode/split.h \
    qrcode/rscode.h \
    qrcode/qrspec.h \
    qrcode/qrinput.h \
    qrcode/qrencode_inner.h \
    qrcode/qrencode.h \
    qrcode/mqrspec.h \
    qrcode/mmask.h \
    qrcode/mask.h \
    qrcode/config.h \
    qrcode/bitstream.h \
    about.h \
    mysqlsheet.h \
    dataexport.h \
    networkcommunication.h \
    remotemysql.h \
    udpcommunication.h \
    usermodify.h \
    userlogindialog.h \
    user.h \
    adthread.h \
    loadbig.h \
    buzzer.h \
    commthread.h \
    printport.h \
    printthread.h \
    json/stack.hh \
    json/serializerrunnable.h \
    json/serializer.h \
    json/qobjecthelper.h \
    json/qjson_export.h \
    json/qjson_debug.h \
    json/position.hh \
    json/parserrunnable.h \
    json/parser.h \
    json/parser_p.h \
    json/location.hh \
    json/json_scanner.h \
    json/json_parser.hh \
    json/FlexLexer.h \
    ethernethttp.h

FORMS    += mainwindow.ui \
    rootdialog.ui \
    TestInput_Cursor/keyboard.ui \
    TestInput_Cursor/formsymbolpad.ui \
    TestInput_Cursor/formnumpad.ui \
    TestInput_Cursor/formhanzitable.ui \
    TestInput_Cursor/formhanziselector.ui \
    TestInput_Cursor/dialogtooltip.ui \
    configsetting.ui \
    printer.ui \
    business.ui \
    about.ui \
    mysqlsheet.ui \
    dataexport.ui \
    usermodify.ui \
    userlogindialog.ui \
    user.ui

RESOURCES += \
    file.qrc \
    TestInput_Cursor/keypad.qrc \
    A31.qrc

OTHER_FILES += \
    inputPanel/keyboard.jpg \
    inputPanel/025.png \
    inputPanel/arrow-big-01.png \
    inputPanel/arrow-big-02.png \
    inputPanel/arrow-big-03.png \
    inputPanel/arrow-big-04.png \
    inputPanel/arrow-small-09.png \
    inputPanel/backspace.png \
    inputPanel/br_down.png \
    inputPanel/br_left.png \
    inputPanel/br_right.png \
    inputPanel/br_up.png \
    inputPanel/down.png \
    inputPanel/f0e2.png \
    inputPanel/f01e.png \
    inputPanel/left.png \
    inputPanel/multiply2_.png \
    inputPanel/power-shutdown.png \
    inputPanel/right.png \
    inputPanel/top.png \
    inputPanel/triangle-down.png \
    inputPanel/triangle-left.png \
    inputPanel/triangle-right.png \
    inputPanel/triangle-up.png \
    TestInput_Cursor/TestInput.vcxproj.filters \
    TestInput_Cursor/TestInput.vcxproj \
    TestInput_Cursor/TestInput.pro \
    TestInput_Cursor/readme.hcj.txt \
    TestInput_Cursor/py_mb.freq.db \
    TestInput_Cursor/py_mb.db \
    TestInput_Cursor/HanziFreq.txt \
    configsetting.o \
    A31/A31/35_all/001.bmp \
    A31/A31/35_all/5.bmp \
    A31/A31/35_all/6.bmp \
    A31/A31/35_all/9.bmp \
    A31/A31/35_all/10.bmp \
    A31/A31/35_all/11.bmp \
    A31/A31/35_all/12.bmp \
    A31/A31/35_all/13.bmp \
    A31/A31/35_all/14.bmp \
    A31/A31/35_all/15.bmp \
    A31/A31/35_all/16.bmp \
    A31/A31/35_all/17.bmp \
    A31/A31/35_all/18.bmp \
    A31/A31/35_all/19.bmp \
    A31/A31/35_all/20.bmp \
    A31/A31/35_all/21.bmp \
    A31/A31/35_all/22.bmp \
    A31/A31/35_all/50.bmp \
    A31/A31/35_all/52.bmp \
    A31/A31/35_all/53.bmp \
    A31/A31/35_all/67.bmp \
    A31/A31/35_all/68.bmp \
    A31/A31/35_all/69.bmp \
    A31/A31/35_all/110.bmp \
    A31/A31/35_all/background.bmp \
    A31/A31/35_all/cha.bmp \
    A31/A31/35_all/down.bmp \
    A31/A31/35_all/logo.bmp \
    A31/A31/35_all/queue.bmp \
    A31/A31/35_all/queue1.bmp \
    A31/A31/35_all/up.bmp \
    A31/A31/35_all/background.png \
    A31/A31/35_all/g01.png \
    A31/A31/35_all/LOGO.png \
    A31/A31/35_all/r01.png \
    A31/A31/35_all/w01.png \
    A31/A31/35_all/y01.png \
    A31/A31/logo/50-自动.png \
    A31/A31/logo/49-置零.png \
    A31/A31/logo/48-稳定.png \
    A31/A31/logo/47-去皮.png





