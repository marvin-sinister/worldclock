//    Copyright (C) 2021 Marvin Sinister
//
//    This file is part of World Clock.
//
//    World Clock is free software: you can redistribute it and/or modify
//    it under the terms of the GNU General Public License as published by
//    the Free Software Foundation, either version 3 of the License, or
//    (at your option) any later version.
//
//    World Clock is distributed in the hope that it will be useful,
//    but WITHOUT ANY WARRANTY; without even the implied warranty of
//    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//    GNU General Public License for more details.
//
//    You should have received a copy of the GNU General Public License
//    along with World Clock.  If not, see <https://www.gnu.org/licenses/>.

#ifndef WORLDCLOCK_H
#define WORLDCLOCK_H

#include <QWidget>
#include <QTimer>
#include <QDateTime>
#include <QFile>

#include "zoneclock.h"
#include "settingsmanager.h"
#include "about.h"


QT_BEGIN_NAMESPACE
namespace Ui { class WorldClock; }
QT_END_NAMESPACE

class WorldClock : public QWidget
{
    Q_OBJECT

public:
    WorldClock(QWidget *parent = nullptr);
    ~WorldClock();

private slots:
    void on_btnAbout_clicked();

private:
    Ui::WorldClock *ui;
    std::vector<ZoneClock*> zoneClocks;

    QTimer* timer;
    QDateTime* time;

    SettingsManager* settingsManager;

    About* about;

    QString version;
};
#endif // WORLDCLOCK_H
