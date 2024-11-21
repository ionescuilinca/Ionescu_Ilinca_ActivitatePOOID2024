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

    Autobuz(int capacitate, int nrPersoaneImbarcate, const char* producator): idAutobuz(++nrAutobuze) {
        this->capacitate = (capacitate > 0) ? capacitate : 0;
        this->nrPersoaneImbarcate = (nrPersoaneImbarcate >= 0 && nrPersoaneImbarcate <= capacitate)
            ? nrPersoaneImbarcate : 0;
        copy_str(&this->producator, producator);
    }

    ~Autobuz() {
        delete[] producator;
    }    

    Autobuz(const Autobuz& a) : idAutobuz(++nrAutobuze) {
        capacitate = a.capacitate;
        nrPersoaneImbarcate = a.nrPersoaneImbarcate;
        copy_str(&producator, a.producator);
    }

    Autobuz& operator=(const Autobuz& a) {
        if (this != &a) {
            capacitate = a.capacitate;
            nrPersoaneImbarcate = a.nrPersoaneImbarcate;
            delete[] producator;
            copy_str(&producator, a.producator);
        }
        return *this;
    }
};

int Autobuz::nrAutobuze = 0;

int main()
{
    cout << "TC1!\n";


}