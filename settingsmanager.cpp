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

#include "settingsmanager.h"

SettingsManager::SettingsManager()
{
    // open settings file
    settings = new QSettings("worldclock.conf", QSettings::IniFormat);
    // load settings from file
    loadSettings();
}

void SettingsManager::saveSettings() {
    // set default zones to not have empty config file
    zones.push_back("America/New_York");
    zones.push_back("Europe/Berlin");
    zones.push_back("Asia/Tokyo");

    // add zones to string
    QString z = "";
    for (const QByteArray &zone : zones) {
        z += zone;
        z += ",";
    }
    // remove trailing comma
    z.chop(1);

    // save zones to file
    settings->setValue("zones", z);
}

void SettingsManager::loadSettings() {
    // load zones from file
    QByteArray z = settings->value("zones", "").toByteArray();
    // if no zone is defined, write default zones
    if (z.isEmpty()) {
        saveSettings();
        return;
    }

    // split zones into list
    zones = z.split(',');
}

QString SettingsManager::getConfigPath() {
    return settings->fileName();
}
