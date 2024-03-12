#ifndef ALLDATA_H
#define ALLDATA_H

#include <QString>
#include <QHash>

class alldata
{
public:
    alldata();
    static bool FileWrite(QString path,QString data);
    static void writeName(QString path);
    static void initName(QString path);

public:
    static QHash<QString,QString> user;
};

#endif // ALLDATA_H
