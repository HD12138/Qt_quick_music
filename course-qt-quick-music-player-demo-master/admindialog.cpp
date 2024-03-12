#include "admindialog.h"
#include "ui_admindialog.h"

AdminDialog::AdminDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AdminDialog)
{
    ui->setupUi(this);
    this->setWindowTitle("管理员入口");
    user = new UserDialog();
    connect(user,&UserDialog::SigUserRemove,this,&AdminDialog::SigUserRemove);
}

AdminDialog::~AdminDialog()
{
    delete ui;
}

void AdminDialog::init()
{
    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
    ui->label_tip->setText(" ");
}

//登录
void AdminDialog::on_pushButton_clicked()
{
    if(name == "admin" && password == "admin123456")
    {
        user->init();
        user->addUser();
        user->show();
        this->close();
    }
    else if(name != "admin")
    {
        ui->label_tip->setText("用户名错误！");
    }
    else if(password != "admin123456")
    {
        ui->label_tip->setText("密码错误！");
    }
}

//用户名
void AdminDialog::on_lineEdit_textChanged(const QString &arg1)
{
    name = arg1;
}

//密码
void AdminDialog::on_lineEdit_2_textChanged(const QString &arg1)
{
    password = arg1;
}
