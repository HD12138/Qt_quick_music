#ifndef USERDIALOG_H
#define USERDIALOG_H

#include <QDialog>
#include <QListWidgetItem>

namespace Ui {
class UserDialog;
}

class UserDialog : public QDialog
{
    Q_OBJECT

public:
    explicit UserDialog(QWidget *parent = nullptr);
    ~UserDialog();
    void addUser();
    void init();


private slots:
    void on_listWidget_itemClicked(QListWidgetItem *item);
    void on_pushButton_clicked();

signals:
    void SigUserRemove();

private:
    Ui::UserDialog *ui;
    QString name;
};

#endif // USERDIALOG_H
