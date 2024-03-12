#include "dialog.h"
#include "ui_dialog.h"
#include <QDebug>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    this->setWindowTitle("注册用户");
    ui->label_tipe->setText("");
}

Dialog::~Dialog()
{
    delete ui;
}

//输入用户名
void Dialog::on_lineEdit_textChanged(const QString &arg1)
{
    name = arg1;
}
//输入密码1
void Dialog::on_lineEdit_2_textChanged(const QString &arg1)
{
    password = arg1;
}
//输入密码2
void Dialog::on_lineEdit_3_textChanged(const QString &arg1)
{
    password_2 = arg1;
}
//确认
void Dialog::on_pushButton_clicked()
{
    //用户名和密码至少6位数
    if(ui->lineEdit->text().length() < 6 || ui->lineEdit_2->text().length() <6)
    {
        ui->label_tipe->setText("用户名或密码请输入至少6位数！");
    }
    //判断密码一致
    else if(password != password_2)
    {
        ui->label_tipe->setText("两次密码不一致，请确认密码！");
    }
    //判断用户名是否存在
    else if(alldata::user.contains(name))
    {
        ui->label_tipe->setText("用户名已存在！");
    }
    else
    {
        if(!password.isEmpty() && !name.isEmpty())
        {
            alldata::user.insert(name,password);
            alldata::writeName("./CustomName.ini");
        }
        emit SigUserRemove();
        this->close();
    }
}

