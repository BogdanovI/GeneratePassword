#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "passwordassembly.h"
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui
{
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    int getQuantitySymbol();
    QString generatePassword();
private slots:
    void on_Generate_Password_clicked();
    void on_QuantityPassSymbolSlide_sliderMoved(int position);

    void on_QuantityPassSymbolSlide_valueChanged(int value);

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
