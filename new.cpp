#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <algorithm>
#include <QString>
using namespace std;

int main(){

    setlocale(LC_ALL, "rus");
    ifstream fun;
    string path = "Configurations.txt";
    fun.open(path);
    if(!fun.is_open()){
        cout <<"Ошибка пути!";
    }
    else{
            }
    return 0;
}
