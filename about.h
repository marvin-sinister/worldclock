#ifndef ABOUT_H
#define ABOUT_H

#include <QDialog>

namespace Ui {
class About;
}

class About : public QDialog
{
    Q_OBJECT

public:
    explicit About(QWidget *parent = nullptr, QString version = "1.0", QString configPath = "/");
    ~About();

private slots:
    void on_btnOk_clicked();

private:
    Ui::About *ui;
};

#endif // ABOUT_H
