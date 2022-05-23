#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QMessageBox"



using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}



MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked() // Шифр
{
        QString openMessage;
        int key;

        openMessage = ui->textedit->text();
        key = ui->lineEdit->text().toInt();

        if (openMessage.isEmpty() || ui->lineEdit->text().isEmpty())
        {
            QMessageBox::warning(this,"Ошибка", "Поле открытого текста пусто или ключ");
        }
        else
        {
            QString input = openMessage;

            for(int i = 0; i < input.length(); i++)
                {
                int sym = 0;
                    if(input[i].toLatin1() > 64 && input[i].toLatin1() < 91 && (sym = input[i].toLatin1() + key) > 90)
                        //Если буква большая
                        input[i] = QChar(sym - 90 + 64);
                    //Проверка на маленькую букву
                    else if(input[i].toLatin1() > 96 && input[i].toLatin1() < 123 && (sym = input[i].toLatin1() + key) > 122)
                        input[i] = QChar(sym - 122 + 96);
                    else input[i] = QChar(input[i].toLatin1() + key);

                }
        ui -> textedit_2 -> setText(QString(input));
   }
}


void MainWindow::on_pushButton_2_clicked() // Дешифр
{
    QString closeMessage;
    int key;

    closeMessage = ui->textedit_2->text();
    key = ui->lineEdit->text().toInt();

    if (closeMessage.isEmpty() || ui->lineEdit->text().isEmpty())
    {
        QMessageBox::warning(this,"Ошибка", "Поле закрытого текста пусто или ключ");
    }
    else
    {
        QString input = closeMessage;

        for(int i = 0; i < input.length(); i++)
        {
                int sym = 0;
                if(input[i].toLatin1() > 64 && input[i].toLatin1() < 91 && (sym = input[i].toLatin1() - key) < 65)
                    //Если буква большая
                    input[i] = QChar(sym - 64 + 90);
                //Теперь тоже самое но с проверкой на маленькую букву
                else if(input[i].toLatin1() > 96 && input[i].toLatin1() < 123 && (sym = input[i].toLatin1() - key) < 97)
                    //Если буква маленькая
                    input[i] = QChar(sym - 96 + 122);
                else input[i] = QChar(input[i].toLatin1() - key);
          }

    ui -> textedit -> setText(QString(input));
  }

}

