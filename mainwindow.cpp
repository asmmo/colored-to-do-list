#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <QString>
#include <QDebug>
#include <QInputDialog>
#include <QDialog>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    connect(ui -> addTaskButton, &QPushButton::clicked, this, &MainWindow::addTask);

}



void MainWindow::addTask(){
    bool ok{};
    QString taskName {QInputDialog::getText(this, tr("Add a task"), tr("Enter your task name:"),
                                            QLineEdit::EchoMode::Normal, tr("untitled task"), &ok)};
    if(ok && !taskName.isEmpty()){
        auto task {new Task{ taskName, this}};
        tasks.push_back(task);
        ui -> tasksLayout -> addWidget(task);
        connect(task, &Task::removed, this, &MainWindow::removeTask);
        connect(task, &Task::statueChanged, this, &MainWindow::onStatueChanged);
        updateStatuesBar();

    }


}


void MainWindow::removeTask(Task* task){
    auto reply = QMessageBox::question(this,tr("Remove"), tr("Are you sure you want to remove the task!"));
    if(reply == QMessageBox::Yes){
        tasks.removeOne(task);
        ui -> tasksLayout -> removeWidget(task);
        if(task -> isDone())
            --numberOfDoneTasks;
        delete task;
        updateStatuesBar();
    }
}


void MainWindow::onStatueChanged(bool newState){
    if(newState)
        ++numberOfDoneTasks;
    else --numberOfDoneTasks;
    updateStatuesBar();
}


void MainWindow::updateStatuesBar(){
    ui -> statubarLabel -> setText(
    QString("Status:  %1 todo / %2 completed")
    .arg(tasks.size())
    .arg(numberOfDoneTasks));
}


MainWindow::~MainWindow()
{
    delete ui;
}

