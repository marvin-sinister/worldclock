#    Copyright (C) 2021 Marvin Sinister
#
#    This file is part of World Clock.
#
#    World Clock is free software: you can redistribute it and/or modify
#    it under the terms of the GNU General Public License as published by
#    the Free Software Foundation, either version 3 of the License, or
#    (at your option) any later version.
#
#    World Clock is distributed in the hope that it will be useful,
#    but WITHOUT ANY WARRANTY; without even the implied warranty of
#    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#    GNU General Public License for more details.
#
#    You should have received a copy of the GNU General Public License
#    along with World Clock.  If not, see <https:#www.gnu.org/licenses/>.

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    about.cpp \
    main.cpp \
    settingsmanager.cpp \
    worldclock.cpp \
    zoneclock.cpp

HEADERS += \
    about.h \
    settingsmanager.h \
    worldclock.h \
    zoneclock.h

FORMS += \
    about.ui \
    worldclock.ui \
    zoneclock.ui

TRANSLATIONS += \
    WorldClock_en_GB.ts

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
  worldclock.qrc
