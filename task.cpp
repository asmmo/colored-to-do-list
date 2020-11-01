#include "task.h"
#include "ui_task.h"
#include <QInputDialog>
#include <mainwindow.h>
#include <QDebug>

Task::Task(const QString& name_, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Task)
{
    ui->setupUi(this);
    setName(name_);
    connect(ui -> editButoon, &QPushButton::clicked,[&]{rename();} );
    connect(ui -> removeButton, &QPushButton::clicked,[this]{emit removed(this);});
    connect(ui ->checkBox, &QCheckBox::toggled, [this]{ done = !done; checked(); emit statueChanged(done);});

}

bool Task::isDone() const{
    return ui -> checkBox -> isChecked();
}

void Task::setName(const QString& name_ ){
    ui -> checkBox ->setText(name = name_);
}


QString Task::getName()const{
    return ui -> checkBox ->text();
}


void Task::checked(){
    QFont font {ui -> checkBox -> font()};
    font.setStrikeOut(done);
    ui -> checkBox -> setFont(font);
}
void Task::rename(){
    bool ok{};
    auto newName {QInputDialog::getText(this, tr("Add new name"), tr("name:"),
                                        QLineEdit::EchoMode::Normal, name, &ok)};
    if(ok && !newName.isEmpty())
        setName(newName);
}


Task::~Task()
{
    delete ui;
}
