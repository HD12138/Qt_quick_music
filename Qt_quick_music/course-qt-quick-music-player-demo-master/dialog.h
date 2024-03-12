#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include "alldata.h"

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();

private slots:
    void on_pushButton_clicked();

    void on_lineEdit_textChanged(const QString &arg1);

    void on_lineEdit_2_textChanged(const QString &arg1);

    void on_lineEdit_3_textChanged(const QString &arg1);

signals:
    void SigUserRemove();

private:
    Ui::Dialog *ui;
    QString name;
    QString password;
    QString password_2;
};

#endif // DIALOG_H
