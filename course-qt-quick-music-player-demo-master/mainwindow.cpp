#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QIcon>
#include "httputils.h"
#include <QQuickWidget>
#include "dialog.h"
#include <QDebug>
#include <QQmlContext>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("MusicPlayer");

    admin = new AdminDialog();
    dialog = new Dialog();
    visitor = new VisitorMode();
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &MainWindow::onTimeout);

    ui->label_tipe->setText(" ");
    alldata::initName("./CustomName.ini");
    addUser();    //将用户名添加进列表框

    connect(admin,&AdminDialog::SigUserRemove,this,&MainWindow::onRemove);
    connect(dialog,&Dialog::SigUserRemove,this,&MainWindow::onRemove);
}

MainWindow::~MainWindow()
{
    delete ui;
}

//更新用户下拉列表
void MainWindow::addUser()
{
    ui->comboBox_user->clear();
    QHash<QString,QString>::const_iterator it = alldata::user.constBegin();
    while (it != alldata::user.constEnd())
    {
        ui->comboBox_user->insertItem(ui->comboBox_user->count(),it.key());
        ui->comboBox_user->setCurrentText(it.key());
        user = it.key();
        qDebug()<<"用户"<<it.key()<<it.value();
        ++it;
    }
}

//登录按钮
void MainWindow::on_pushButton_clicked()
{
    if(!alldata::user.contains(user))
    {
        ui->label_tipe->setText("用户名不存在");
        ui->comboBox_user->setCurrentText("");
        ui->lineEdit_2->setText("");
    }
    else if(alldata::user.value(user) != password)    //判断密码是否正确
    {
        ui->label_tipe->setText("密码错误，请重新输入密码！");
        ui->lineEdit_2->setText("");
    }
    else if(ui->lineEdit_2->text() == "" || ui->comboBox_user->currentText() == "")
    {
        ui->label_tipe->setText("请输入用户名或密码！");
    }
    else
    {
        //显示qml界面
        qmlRegisterType<HttpUtils>("MyUtils",1,0,"HttpUtils");
        QQuickWidget* qmlWidget = new QQuickWidget(QUrl("qrc:/App.qml"));
        qmlWidget->setResizeMode(QQuickWidget::SizeRootObjectToView);

        this->hide();
    }
}

//注销用户
void MainWindow::on_pushButton_3_clicked()
{
    if(!alldata::user.contains(user))
    {
        ui->label_tipe->setText("用户名不存在");
        ui->comboBox_user->setCurrentText("");
        ui->lineEdit_2->setText("");
    }
    else if(alldata::user.value(user) != password)    //判断密码是否正确
    {
        ui->label_tipe->setText("密码错误，请重新输入密码！");
        ui->lineEdit_2->setText("");
    }
    else if(ui->lineEdit_2->text() == "" || ui->comboBox_user->currentText() == "")
    {
        ui->label_tipe->setText("请输入用户名或密码！");
    }
    else
    {
        ui->label_tipe->setText("注销成功！");
        ui->lineEdit_2->setText("");
        alldata::user.remove(user);
        alldata::writeName("./CustomName.ini");
        addUser();  //更新用户列表
    }
}

//注册按钮
void MainWindow::on_pushButton_2_clicked()
{
    dialog->show();
}

//输入密码
void MainWindow::on_lineEdit_2_textChanged(const QString &arg1)
{
    password = arg1;
}

//选择用户
void MainWindow::on_comboBox_user_currentTextChanged(const QString &arg1)
{
    user = arg1;
}

//手动输入用户
void MainWindow::on_comboBox_user_editTextChanged(const QString &arg1)
{
    user = arg1;
}

void MainWindow::onTimeout()
{
    timer->stop();
    visitor->hide();
    //时间到退出程序
    QApplication::quit();
}

void MainWindow::onRemove()
{
    addUser();
}

//游客登录
void MainWindow::on_pushButton_4_clicked()
{
    //显示qml界面
    qmlRegisterType<HttpUtils>("MyUtils",1,0,"HttpUtils");
    QQuickWidget* qmlWidget = new QQuickWidget(QUrl("qrc:/App.qml"));
    qmlWidget->setResizeMode(QQuickWidget::SizeRootObjectToView);

    visitor->show();
    visitor->timer->start(1000);

    timer->start(120000);
    this->hide();
}

//管理员入口
void MainWindow::on_pushButton_5_clicked()
{
    admin->init();
    admin->show();
}
