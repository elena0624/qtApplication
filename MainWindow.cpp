#include "MainWindow.h"
#include <QListWidgetItem>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);

    connect(ui.sendBtn, &QPushButton::clicked, this, &MainWindow::on_sendBtnClicked);
    connect(ui.restartBtn, &QPushButton::clicked, this, &QMainWindow::on_restartBtnClicked);
}

void MainWindow::on_sendBtnClicked()
{
    QString msg = ui.textEdit->toPlainText();
    ui.textEdit->clear();

    QListWidgetItem* user = new QListWidgetItem("I:", ui.chatHistory);
    QFont font("myFontFamily");
    font.setBold(true);
    user->setFont(font);
    ui.chatHistory->addItem(user);

    QListWidgetItem* content = new QListWidgetItem(msg, ui.chatHistory);
    ui.chatHistory->addItem(content);

    QListWidgetItem* bot = new QListWidgetItem("Bot:", ui.chatHistory);
    bot->setFont(font);
    ui.chatHistory->addItem(bot);

    QListWidgetItem* respondContent = new QListWidgetItem("OK.", ui.chatHistory);
    ui.chatHistory->addItem(respondContent);

}

void MainWindow::on_restartBtnClicked()
{
    ui.chatHistory->();
}

MainWindow::~MainWindow()
{
}
