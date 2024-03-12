#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QApplication>
#include <QCloseEvent>
#include "alldata.h"
#include <QTimer>
#include <QQuickWidget>
#include "visitormode.h"
#include "admindialog.h"
#include "dialog.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void addUser();

protected:
    void closeEvent(QCloseEvent *event) override {
        QApplication::quit();
    }


private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();
    
    void on_lineEdit_2_textChanged(const QString &arg1);

    void on_comboBox_user_currentTextChanged(const QString &arg1);

    void on_pushButton_3_clicked();

    void on_comboBox_user_editTextChanged(const QString &arg1);

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

public slots:
    void onTimeout();
    void onRemove();

private:
    Ui::MainWindow *ui;
    QString password;
    QString user;
    QTimer *timer;
    AdminDialog *admin;
    Dialog *dialog;
    VisitorMode *visitor;

};

#endif // MAINWINDOW_H
