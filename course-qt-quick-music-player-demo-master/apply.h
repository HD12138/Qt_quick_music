#ifndef APPLY_H
#define APPLY_H

#include <QWidget>

namespace Ui {
class Apply;
}

class Apply : public QWidget
{
    Q_OBJECT

public:
    explicit Apply(QWidget *parent = nullptr);
    ~Apply();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Apply *ui;
};

#endif // APPLY_H
