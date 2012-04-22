FORMS += NewForm.ui \
         MainForm.ui \
         ChangeTitleForm.ui
HEADERS += DlgNew.h \
           DlgMain.h \
           DlgChangeTitle.h \
           symbolconverter.h \
           symbol.h 
SOURCES += DlgNew.cpp \
           DlgMain.cpp \
           DlgChangeTitle.cpp \
           hpcalc.cpp \
           symbolconverter.cpp \
           symbol.cpp 

#build with debug support
#CONFIG += debug

TEMPLATE = app
TARGET = hpcalc
RESOURCES = resources.qrc
