#include "add.h"
#include "ui_adminwindow.h"
#include "adminwindow.h"
#include <QTableWidget>

adminwindow::adminwindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::adminwindow)
{
    ui->setupUi(this);

   ui->tableWidget->setRowCount(dataPerson.Num());//
   ui->tableWidget->setColumnCount(5);//
   ui->tableWidget->setHorizontalHeaderLabels(QStringList()<<"Password"<<"First_name"<< "Last_name"<<"Age"<<"Gender");

   UpdateTable();
}


adminwindow::~adminwindow()
{
    delete ui;
}

void adminwindow::on_pushButton_clicked()//Добавить
{
    QString log_ = ui->lineEdit->text();
    QString pass_ = ui->lineEdit_2->text();
    QString f_name_ = ui->lineEdit_3->text();
    QString s_name_ = ui->lineEdit_4->text();
    QString a_ = ui->lineEdit_5->text();
    QString gend_ = ui->comboBox->currentText();;
    dataPerson.Make_Person(log_,pass_,f_name_,s_name_,a_,gend_);
    ui->lineEdit->setText("");
    ui->lineEdit_2->setText("");
    ui->lineEdit_3->setText("");
    ui->lineEdit_4->setText("");
    ui->lineEdit_5->setText("");
}


void adminwindow::on_pushButton_4_clicked()//Обновить
{
    UpdateTable();
    dataPerson.Ofstream();

}


void adminwindow::on_pushButton_3_clicked()//Удалить
{
    QString login_ = ui->lineEdit->text();
    dataPerson.Delete(login_);
    int l = dataPerson.Delete(login_);
    if (l==dataPerson.Num()-1 ){
    dataPerson.DeleteEnd(l);
    }
}


void adminwindow::on_pushButton_2_clicked()//Изменить
{
    QString login_ = ui->lineEdit->text();
    QString password_ = ui->lineEdit_2->text();
    QString f_name_ = ui->lineEdit_3->text();
    QString s_name_ = ui->lineEdit_4->text();
    QString age_ = ui->lineEdit_5->text();
    QString gender_ = ui->comboBox->currentText();
    dataPerson.ChangeAll(::login_,login_, password_,f_name_,s_name_,age_,gender_); // глобальный логин
    ui->lineEdit->setText("");
    ui->lineEdit_2->setText("");
    ui->lineEdit_3->setText("");
    ui->lineEdit_4->setText("");
    ui->lineEdit_5->setText("");

}

void adminwindow ::UpdateTable(){
    ui->tableWidget->setRowCount(dataPerson.Num());//
    ui->tableWidget->setColumnCount(5);//
    ui->tableWidget->setHorizontalHeaderLabels(QStringList()<<"Password"<<"First_name"<< "Last_name"<<"Age"<<"Gender");

    vector <QString> pass_vec,fname_vec,sname_vec,age_vec,g_vec;
    dataPerson.GetAllPass(pass_vec);
    dataPerson.GetAllFname(fname_vec);
    dataPerson.GetAllSname(sname_vec);
    dataPerson.GetAllAge(age_vec);
    dataPerson.GetAllGender(g_vec);
    for(int i=0; i<ui->tableWidget->rowCount(); i++){
        QTableWidgetItem * itm = new QTableWidgetItem(pass_vec[i]);
        ui->tableWidget->setItem(i,0,itm);
    }
    for(int i=0; i<ui->tableWidget->rowCount(); i++){
        QTableWidgetItem * itm = new QTableWidgetItem(fname_vec[i]);
        ui->tableWidget->setItem(i,1,itm);
    }
    for(int i=0; i<ui->tableWidget->rowCount(); i++){
        QTableWidgetItem * itm = new QTableWidgetItem(sname_vec[i]);
        ui->tableWidget->setItem(i,2,itm);
    }
    for(int i=0; i<ui->tableWidget->rowCount(); i++){
        QTableWidgetItem * itm = new QTableWidgetItem(age_vec[i]);
        ui->tableWidget->setItem(i,3,itm);
    }
    for(int i=0; i<ui->tableWidget->rowCount(); i++){
        QTableWidgetItem * itm = new QTableWidgetItem(g_vec[i]);
        ui->tableWidget->setItem(i,4,itm);
    }
}


void adminwindow::on_tableWidget_itemSelectionChanged()
{
    QTableWidgetItem * itm = new QTableWidgetItem(":D");
    int i= ui->tableWidget->currentRow();

    ui->lineEdit_2->setText(ui->tableWidget->item(i,0)->text());
    ui->lineEdit_3->setText(ui->tableWidget->item(i,1)->text());
    ui->lineEdit_4->setText(ui->tableWidget->item(i,2)->text());
    ui->lineEdit_5->setText(ui->tableWidget->item(i,3)->text());
    ui->comboBox->setCurrentText(ui->tableWidget->item(i,4)->text());
    ui->lineEdit->setText(dataPerson.GetLogin(ui->tableWidget->item(i,0)->text()));
    ::login_ = dataPerson.GetLogin(ui->tableWidget->item(i,0)->text());
}

