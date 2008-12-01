TEMPLATE = app
TARGET = QtView
QT += core \
    gui
HEADERS += ConsoleView.h \
    UpdateInfo.h \
    Cell.h \
    CoordinateTypes.h \
    Exception.h \
    GameBoard.h \
    HitResult.h \
    Model.h \
    Ship.h \
    ShipPattern.h \
    View.h \
    qtview.h
SOURCES += ConsoleView.cpp \
    Cell.cpp \
    Exception.cpp \
    GameBoard.cpp \
    HitResult.cpp \
    Model.cpp \
    Ship.cpp \
    ShipPattern.cpp \
    runprg.cpp \
    View.cpp \
    main.cpp \
    qtview.cpp
FORMS += qtview.ui
RESOURCES += 
