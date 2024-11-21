#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <iostream>
using namespace std;

void copy_str(char** dest,const char* sursa)
{
    if (sursa)
    {
        *dest= new char[strlen(sursa) + 1];
        strcpy(*dest, sursa);
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

    friend ostream& operator<<(ostream& out, const Autobuz& a) {
        out << "ID: " << a.idAutobuz
            << "; Capacitate: " << a.capacitate
            << "; Persoane imbarcate: " << a.nrPersoaneImbarcate
            << "; Producator: " << (a.producator ? a.producator : "")
            << endl;
        return out;
    }

    int getNumarLocuriLibere() const {
        return capacitate - nrPersoaneImbarcate;
    }
};

int Autobuz::nrAutobuze = 0;

int main()
{
    cout << "TC1\n" << endl;

    
    cout << "Testare constructor fara parametri" << endl;
    Autobuz a1;
    cout << a1 << endl;

    cout << "Testare constructor cu parametri" << endl;
    Autobuz a2(44, 26, "Mercedes");
    cout << a2 << endl;

    cout << "Testare constructor de copiere" << endl;
    Autobuz a3 = a2;
    cout << a3 << endl;
    
    cout << "Testare operatorul = (de atribuire)" << endl;
    a1 = a2;
    cout << a1 << endl;

    cout << "Testare metoda getNumarLocuriLibere()" << endl;
    cout << "a1.getNumarLocuriLibere(): " << a1.getNumarLocuriLibere() << endl;

    
    return 0;
}