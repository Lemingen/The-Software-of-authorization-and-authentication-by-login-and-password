#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "add.h"
#include "adminwindow.h"
#include "clientwindow.h"
//#include "main.cpp"

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


void MainWindow::on_pushButton_clicked()
{

    QString login_ = ui->lineEdit->text();
    QString password_ = ui->lineEdit_2->text();
    ::login_ = login_;
    ::password_ = password_;

    QString str= "C:/Users/79531/Documents/client-server/Configurations.txt";
    QFile file(str);

    if (!file.open(QFile::ReadOnly | QFile::Text)){
        QMessageBox::information(this, "Error", " Path not correct");
        return;
    }
    QTextStream stream(&file);

    while (!stream.atEnd()){
        QString line = stream.readLine();

        QString login="",password="",first_name="",second_name="",age="",gender="";
        int d=1;
        for(int i=0; i<line.length(); i++){
        if ((line[i]!=' ') && (d==1)){
            login += line[i];
        }
        else if ((line[i]!=' ') && (d==2)){
            password += line[i];
        }
        else if ((line[i]!=' ') && (d==3)){
            first_name += line[i];
        }
        else if ((line[i]!=' ') && (d==4)){
            second_name += line[i];
        }
        else if ((line[i]!=' ') && (d==5)){
            age += line[i];
        }
        else if ((line[i]!=' ') && (d==6)){
            gender += line[i];
        }
        else{
            d++;
        }
        }
    dataPerson.Make_Person(login, password, first_name, second_name, age, gender);

    }
    file.close();




   if((dataPerson.Search(login_,password_)) == 2){
       //admin
       //QMessageBox::about(this, "Заголовок", "Админ");
       hide();
       adminwindow admin;
       admin.setModal(true);
       admin.exec();

   }
   else if((dataPerson.Search(login_,password_)) == 1){
       //user
       //QMessageBox::about(this, "Заголовок", "Юзер");
       hide();
       clientwindow client;
       client.SetAll();
       client.setModal(true);
       client.exec();
   }
   else if((dataPerson.Search(login_,password_)) == 0){
       // not access
       QMessageBox::about(this, "Заголовок", "Без доступа");
   }
}


