#ifndef ADD_H
#define ADD_H
#include <vector>
#include <QString>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QLocale>


using namespace std;
class Param
{
    public:
    QString login = "";
    QString password ="";
    QString first_name ="";
    QString second_name = "";
    QString age = "";
    QString gender = "";

    Param(QString, QString, QString, QString, QString, QString);
};

class Data
{
    public:
    vector<Param>vec ={};
    void Make_Person(QString ,QString ,QString ,QString ,QString ,QString );
    int Search(QString , QString );
    void Change();
    QString Find(QString );
    int Num();
    void Change_Pass(QString , QString);
    void Change_Fname(QString , QString);
    void Change_Sname(QString , QString);
    void Change_Age(QString , QString);
    void Change_Gender(QString , QString);
    QString Find_F_Name(QString );
    QString Find_S_Name(QString );
    QString Find_Age(QString );
    QString Find_Gender(QString );
    void GetAllPass(vector<QString> & new_vec);
    void GetAllFname(vector<QString> & new_vec);
    void GetAllSname(vector<QString> & new_vec);
    void GetAllAge(vector<QString> & new_vec);
    void GetAllGender(vector<QString> & new_vec);
    void Ofstream();
    int Delete(QString);
    QString GetLogin(QString);
    void ChangeAll(QString, QString, QString, QString, QString, QString, QString);
    void DeleteEnd(int);

};
extern Data dataPerson;
extern QString login_;
extern QString password_;

#endif // ADD_H
