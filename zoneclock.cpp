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

#include "zoneclock.h"
#include "ui_zoneclock.h"

ZoneClock::ZoneClock(QWidget *parent, QByteArray tz, QDateTime* t) :
    QWidget(parent),
    ui(new Ui::ZoneClock)
{
    ui->setupUi(this);
    time = t;
    setZone(tz);
}

ZoneClock::~ZoneClock()
{
    delete ui;
}

void ZoneClock::setZone(QByteArray tz) {
    this->ui->zoneBox->setTitle(tz);
    zone = new QTimeZone(tz);
    tick();
}

void ZoneClock::tick() {
    this->ui->lblTime->setText(time->currentDateTime().toTimeZone(*zone).toString("HH:mm:ss"));
    this->ui->lblDate->setText(time->currentDateTime().toTimeZone(*zone).toString("yyyy-MM-dd"));
}
