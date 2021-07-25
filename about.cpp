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

#include "about.h"
#include "ui_about.h"

About::About(QWidget *parent, QString version, QString configPath) :
    QDialog(parent),
    ui(new Ui::About)
{
    ui->setupUi(this);

    this->ui->lblVersion->setText(version);

    // read license from file
    QFile licenseFile(":/license/LICENSE");
    licenseFile.open(QIODevice::ReadOnly);
    ui->txtLicense->setPlainText(licenseFile.readAll());
    licenseFile.close();

    this->ui->lblConfigPath->setText(configPath);
}

About::~About()
{
    delete ui;
}

void About::on_btnOk_clicked()
{
    this->close();
}
