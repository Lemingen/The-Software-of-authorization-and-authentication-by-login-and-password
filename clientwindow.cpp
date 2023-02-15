#include "clientwindow.h"
#include "ui_clientwindow.h"
#include "add.h"

clientwindow::clientwindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::clientwindow)
{
    ui->setupUi(this);
}

clientwindow::~clientwindow()
{
    delete ui;
}

void clientwindow::on_pushButton_clicked()//пароль
{
    QString password_ = ui->lineEdit->text();
    dataPerson.Change_Pass(password_, ::login_);
    ui->label_7->setText(password_);
}


void clientwindow::on_pushButton_6_clicked()//имя
{
    QString f_name_ = ui->lineEdit_2->text();
    dataPerson.Change_Fname(f_name_, ::login_);
    ui->label_8->setText(f_name_);

}


void clientwindow::on_pushButton_5_clicked()//фамилия
{
    QString s_name_ = ui->lineEdit_3->text();
    dataPerson.Change_Sname(s_name_, ::login_);
    ui->label_12->setText(s_name_);
}


void clientwindow::on_pushButton_4_clicked()
{
    int a = ui->spinBox->value();
    QString age_ = QString::number(a);
    dataPerson.Change_Age(age_, ::login_);
    ui->label_9->setText(age_);
}


void clientwindow::on_pushButton_3_clicked() //пол
{
    QString gender_ = ui->comboBox->currentText();
    dataPerson.Change_Gender(gender_, ::login_);
    ui->label_11->setText(gender_);
}

void clientwindow :: SetAll(){
    QLocale::setDefault(QLocale::Russian);
    ui->label_10->setText(::login_);
    ui->label_7->setText(::password_);
    ui->label_8->setText(dataPerson.Find_F_Name(::login_)); //имя
    ui->label_12->setText(dataPerson.Find_S_Name(::login_));//фамилия
    ui->label_9->setText(dataPerson.Find_Age(::login_)); //возраст
    ui->label_11->setText(dataPerson.Find_Gender(::login_));//пол
}


void clientwindow::on_pushButton_2_clicked() //загрузить данные
{
    dataPerson.Ofstream();
}

