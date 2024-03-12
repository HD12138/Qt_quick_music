#ifndef ADMINDIALOG_H
#define ADMINDIALOG_H

#include <QDialog>
#include "userdialog.h"

namespace Ui {
class AdminDialog;
}

class AdminDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AdminDialog(QWidget *parent = nullptr);
    ~AdminDialog();
    void init();

private slots:
    void on_pushButton_clicked();

    void on_lineEdit_textChanged(const QString &arg1);

    void on_lineEdit_2_textChanged(const QString &arg1);

signals:
    void SigUserRemove();

private:
    Ui::AdminDialog *ui;
    QString name;
    QString password;
    UserDialog *user;
};

#endif // ADMINDIALOG_H
