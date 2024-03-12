#include "userdialog.h"
#include "ui_userdialog.h"
#include "alldata.h"
#include <QDebug>

UserDialog::UserDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::UserDialog)
{
    ui->setupUi(this);
    this->setWindowTitle("管理用户");
    addUser();
}

UserDialog::~UserDialog()
{
    delete ui;
}

void UserDialog::addUser()
{
    ui->listWidget->clear();
    QHash<QString,QString>::const_iterator it = alldata::user.constBegin();
    while (it != alldata::user.constEnd())
    {
        ui->listWidget->addItem(it.key());
        ++it;
    }
}

void UserDialog::init()
{
    ui->label_tip->setText(" ");
}

void UserDialog::on_listWidget_itemClicked(QListWidgetItem *item)
{
    name = item->text();
}

//注销
void UserDialog::on_pushButton_clicked()
{
    ui->label_tip->setText("注销成功！");
    alldata::user.remove(name);
    alldata::writeName("./CustomName.ini");
    addUser();  //更新用户列表
    emit SigUserRemove();
}
