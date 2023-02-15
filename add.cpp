#include <vector>
#include <QString>
#include <add.h>
#include <QDebug>
using namespace std;


Data dataPerson;
QString login_;
QString password_;

Param::Param(QString a, QString b, QString c, QString d, QString e, QString f){
    login = a;
    password = b;
    first_name = c;
    second_name = d;
    age = e;
    gender = f;
}

void Data::Make_Person(QString login,QString password,QString first_name,QString second_name,QString age,QString gender){
    vec.push_back(Param{login, password,first_name, second_name, age, gender});
}

int Data::Search(QString login_, QString password_){
    for(auto it = vec.begin(); it!= vec.end(); it++){
        if((((*it).login)==login_)&&(((*it).password)==password_)){
            //аутентификация прошла успешно
            if (login_=="admin"){
                return 2;
            }
            return 1;
        }
    }
    return 0;
}

QString Data::Find(QString login_){
    for(auto it = vec.begin(); it!= vec.end(); it++){
        if(((*it).login)==login_){
            return login_;
       }
    }
    return "nothing";
}

int Data::Num(){
    int num=0;
    for(auto it = vec.begin(); it!= vec.end(); it++){
        num++;
    }
    return num;
}
void Data::Change_Pass(QString pass_, QString login__){
    for(auto it = vec.begin(); it!= vec.end(); it++){
        if(((*it).login)==login__){
            (*it).password = pass_;
       }
    }

}

void Data::Change_Fname(QString f_name_, QString login__){
    for(auto it = vec.begin(); it!= vec.end(); it++){
        if(((*it).login)==login__){
            (*it).first_name = f_name_;
       }
    }
}


void Data::Change_Sname(QString s_name_, QString login__){
    for(auto it = vec.begin(); it!= vec.end(); it++){
        if(((*it).login)==login__){
            (*it).second_name = s_name_;
       }
    }
}

void Data::Change_Age(QString age_, QString login__){
    for(auto it = vec.begin(); it!= vec.end(); it++){
        if(((*it).login)==login__){
            (*it).age = age_;
       }
    }
}

void Data::Change_Gender(QString gender_, QString login__){
    for(auto it = vec.begin(); it!= vec.end(); it++){
        if(((*it).login)==login__){
            (*it).gender = gender_;
       }
    }
}

QString Data::Find_F_Name(QString login_){
    for(auto it = vec.begin(); it!= vec.end(); it++){
        if(((*it).login)==login_){
            return (*it).first_name;
       }
    }
}

QString Data::Find_S_Name(QString login_){
    for(auto it = vec.begin(); it!= vec.end(); it++){
        if(((*it).login)==login_){
            return (*it).second_name;
       }
    }
}

QString Data::Find_Age(QString login_){
    for(auto it = vec.begin(); it!= vec.end(); it++){
        if(((*it).login)==login_){
            return (*it).age;
       }
    }
}
QString Data::Find_Gender(QString login_){
    for(auto it = vec.begin(); it!= vec.end(); it++){
        if(((*it).login)==login_){
            return (*it).gender;
       }
    }
}

void Data::GetAllPass(vector<QString> & new_vec){
    for(auto it = vec.begin(); it!= vec.end(); it++){
        new_vec.push_back((it)->password);
    }
}

void Data::GetAllFname(vector<QString> & new_vec){
    for(auto it = vec.begin(); it!= vec.end(); it++){
        new_vec.push_back((it)->first_name);
    }
}
void Data::GetAllSname(vector<QString> & new_vec){
    for(auto it = vec.begin(); it!= vec.end(); it++){
        new_vec.push_back((it)->second_name);
    }
}
void Data::GetAllAge(vector<QString> & new_vec){
    for(auto it = vec.begin(); it!= vec.end(); it++){
        new_vec.push_back((it)->age);
    }
}
void Data::GetAllGender(vector<QString> & new_vec){
    for(auto it = vec.begin(); it!= vec.end(); it++){
        new_vec.push_back((it)->gender);
    }
}
void Data::Ofstream(){
QFile mFile("C:/Users/79531/Documents/client-server/Configurations.txt");
if(!mFile.open(QFile::WriteOnly | QFile::Text)){
    //QMessageBox::information(this, "Error", " Path not correct");
    return;
}

QTextStream stream(&mFile);

for(auto it = vec.begin(); it!= vec.end(); it++){
    if (it != (vec.end()-1)){
    stream << it->login << " " << it->password << " " << it->first_name << " " << it->second_name << " " << it->age << " " << it->gender << "\n";
    }
    else{
        stream << it->login << " " << it->password << " " << it->first_name << " " << it->second_name << " " << it->age << " " << it->gender;
    }
}

mFile.close();
}

int Data::Delete(QString log_){
    int c = 0;
    for(auto it = vec.begin(); it!= vec.end(); it++){

        if((((*it).login)==log_) && (it != (vec.end()-1))){
            vec.erase(it);
        }
        else if((((*it).login)==log_) && (it == vec.end()-1)){
            return c;

        }
        c++;
    }
    return 0;
}

void Data::DeleteEnd(int l){
    vec.erase(vec.begin()+l);
}



QString Data::GetLogin(QString pass_){
    for(auto it = vec.begin(); it!= vec.end(); it++){
        if(((*it).password)==pass_){
            return it->login;
        }
    }
}

void Data::ChangeAll(QString login_, QString log_, QString pass_, QString f_name, QString s_name, QString age_, QString gender_){
    for(auto it = vec.begin(); it!= vec.end(); it++){
        if(((*it).login)==login_){
            (*it).login = log_;
            (*it).password = pass_;
            (*it).first_name = f_name;
            (*it).second_name = s_name;
            (*it).age = age_;
            (*it).gender = gender_;
        }
    }
}
