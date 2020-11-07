#ifndef TASK_H
#define TASK_H

#include <QWidget>

namespace Ui {
class Task;
}

class Task : public QWidget
{
    Q_OBJECT

public:
    Task(const QString&, QWidget *parent = nullptr);
    void setName(const QString& );
    QString getName()const;
    bool isDone()const;
    void setStatue(bool);
    ~Task();
private:
    Ui::Task *ui;
    QString name;
    bool done {};
    void rename();
    void checked();

signals: void removed(Task* );
    void statueChanged(bool );
};

#endif // TASK_H
