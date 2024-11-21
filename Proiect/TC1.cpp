#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <iostream>
using namespace std;

void copy_str(char** dest,const char* sursa)
{
    if (sursa)
    {
        *dest= new char[strlen(sursa) + 1];
        strcpy(*dest, "");
    }
    else
    {
        *dest = NULL;
    }
}

class Autobuz
{
    static int nrAutobuze;
    const int idAutobuz; 
    int capacitate;
    int nrPersoaneImbarcate;
    char* producator;

public:

    Autobuz():idAutobuz(++nrAutobuze)
    {
        this->capacitate = 0;
        this->nrPersoaneImbarcate = 0;
        copy_str(&this->producator, "");
    }
};

int Autobuz::nrAutobuze = 0;

int main()
{
    cout << "TC1!\n";


}