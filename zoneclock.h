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

#ifndef ZONECLOCK_H
#define ZONECLOCK_H

#include <QWidget>
#include <QString>
#include <QDateTime>
#include <QTimeZone>

namespace Ui {
class ZoneClock;
}

class ZoneClock : public QWidget
{
    Q_OBJECT

public:
    explicit ZoneClock(QWidget *parent = nullptr, QByteArray tz = "Europe/Zagreb", QDateTime* t = nullptr);
    ~ZoneClock();
    void setZone(QByteArray tz);


private:
    Ui::ZoneClock *ui;
    QTimeZone* zone;
    QDateTime* time;

public slots:
    void tick();

};

#endif // ZONECLOCK_H
