#ifndef VISITORMODE_H
#define VISITORMODE_H

#include <QDialog>
#include <QTimer>

namespace Ui {
class VisitorMode;
}

class VisitorMode : public QDialog
{
    Q_OBJECT

public:
    explicit VisitorMode(QWidget *parent = nullptr);
    ~VisitorMode();

private slots:
    void TimeChange();

private:
    Ui::VisitorMode *ui;
    int time;

public:
    QTimer *timer;
};

#endif // VISITORMODE_H
