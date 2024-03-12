#include "apply.h"
#include "ui_apply.h"

Apply::Apply(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Apply)
{
    ui->setupUi(this);
}

Apply::~Apply()
{
    delete ui;
}
//确认按钮
void Apply::on_pushButton_clicked()
{
    //1，判断密码对不对

    //2，判断用户名重复了吗

    //3，申请成功，返回登陆界面
    QWidget *p=this->parentWidget();
    p->show();
    delete this;
}
