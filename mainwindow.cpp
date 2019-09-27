#include "mainwindow.h"
#include "passwordassembly.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

int MainWindow::getQuantitySymbol()
{
    QString quantityStr = ui->QuantityPassSymbol->text();
    int quantityInt = quantityStr.toInt();
    if (quantityInt > 15)
    {
        ui->statusbar->showMessage("Maximum password length 15 characters");
        quantityInt = 15;
        return quantityInt;
    }
    else if (quantityInt < 3)
    {
        ui->statusbar->showMessage("Minimum password length 3 characters");
        quantityInt = 3;
        return quantityInt;
    }
    else
    {
        ui->statusbar->showMessage("New password generate");
        return quantityInt;
    }
}

QString MainWindow::generatePassword()
{
    QString newPassword;
    PasswordAssembly genPass(getQuantitySymbol(), ui->upperCheck->checkState(), ui->numberCheck->checkState());
    newPassword = genPass.AssemblyNewPassword();
    return newPassword;
}

void MainWindow::on_QuantityPassSymbolSlide_sliderMoved(int position)
{
    ui->QuantityPassSymbol->setValue(position);
}
void MainWindow::on_QuantityPassSymbolSlide_valueChanged(int value)
{
    ui->QuantityPassSymbol->setValue(value);
}
void MainWindow::on_Generate_Password_clicked()
{
    ui->OutputPassword->setText(MainWindow::generatePassword());
}
