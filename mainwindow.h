#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <task.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
public slots:
    void removeTask(Task* );
    void onStatueChanged( bool );

private slots:
    void addTask();
private:
    void updateStatuesBar();
    Ui::MainWindow *ui;
    QVector<Task*> tasks;
    size_t numberOfDoneTasks{};

};
#endif // MAINWINDOW_H
