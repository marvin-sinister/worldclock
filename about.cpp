#include "about.h"
#include "ui_about.h"

About::About(QWidget *parent, QString version, QString configPath) :
    QDialog(parent),
    ui(new Ui::About)
{
    ui->setupUi(this);

    this->ui->lblVersion->setText(version);
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
