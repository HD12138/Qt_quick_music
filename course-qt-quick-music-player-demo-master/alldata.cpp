#include "alldata.h"
#include <QDebug>
#include <QFile>

QHash<QString,QString> alldata::user;

alldata::alldata()
{

}

bool alldata::FileWrite(QString path,QString data)
{
    FILE *fd = NULL;

    fd = fopen(path.toLocal8Bit().data(),"w+");
    if(fd == NULL)return -1;

    fwrite(data.toUtf8().data(),data.toUtf8().size(),1,fd);

    fflush(fd);
    fclose(fd);
    return 0;
}

void alldata::writeName(QString path)
{
    QString data;
    QHash<QString,QString>::const_iterator it = user.constBegin();
    while (it != user.constEnd())
    {
        data.append(QString("<用户名:%1:用户密码:%2>").arg(it.key()).arg(it.value()));
        ++it;
    }

    FileWrite(path,data);
}

void alldata::initName(QString path)
{
    QString Data;
    QFile file(path);

    if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        return;
    }

    Data = file.readAll();
    file.close();

    //<用户名:123456:用户密码:123456>
    QStringList list = Data.split('>', QString::SkipEmptyParts);
    QStringList data;

    for(int i=0; i< list.size() ;i++)
    {
        data = list.at(i).split(':', QString::SkipEmptyParts);
        if(data.at(0) == "<用户名")
        {
            user.insert(data.at(1),data.at(3));
        }
    }
}
