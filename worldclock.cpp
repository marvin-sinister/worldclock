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

#include "worldclock.h"

#include "ui_worldclock.h"

WorldClock::WorldClock(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::WorldClock)
{
    ui->setupUi(this);

    // read version from file
    QFile versionFile(":/version/VERSION");
    versionFile.open(QIODevice::ReadOnly);
    version = versionFile.readAll();
    version.chop(1);
    versionFile.close();

    // init settings manager
    settingsManager = new SettingsManager();

    // init about window
    about = new About(this, version, settingsManager->getConfigPath());

    // put version in botom of window
    ui->lblStatus->setText(version);

    // init timer
    timer = new QTimer(this);
    time = new QDateTime();

    // add zones
    for (const QByteArray &zone : settingsManager->zones) {
        zoneClocks.push_back(new ZoneClock(this, zone, time));
        connect(timer, &QTimer::timeout, zoneClocks.back(), &ZoneClock::tick);
        ui->layoutClocks->addWidget(zoneClocks.back());
    }

    // start timer
    timer->start(1000);
}

WorldClock::~WorldClock()
{
    delete ui;
}


void WorldClock::on_btnAbout_clicked()
{
    about->show();
}
