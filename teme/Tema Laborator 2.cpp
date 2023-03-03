/* Exercitiul 2.1. Plecand de la exercitiul 3 din laborator, sa se ordoneze crescator lista studentilor dupa criteriul an, utilizand functii STL.
 * Indicatii: se construieste functia criteriului de selectie. Spre exepmplu:
 * bool comparAn(Nod &a, Nod &b) {
 * 	return a.an < b.an;
 * }
 * se apeleaza functia de sortare sort, a bibliotecii STL.
 */
#include <iostream>
#include <list>
#include <cstring>

using namespace std;

struct Nod {
    int ID;
    char nume[50];
    int an;
};

bool comparAn(Nod &a, Nod &b){
    return a.an < b.an;
}

int main() {
    list<struct Nod> lista;

    // introducere la final in lista
    Nod el{};
    el.ID = 1;
    strcpy(el.nume, "nume 1");
    el.an = 1;
    lista.push_back(el);

    // Afisare elemente lista
    for (std::list<Nod>::iterator it = lista.begin(); it != lista.end(); it++) {
        cout << "ID: " << it->ID << " nume: " << it->nume << " an: " << it->an << endl;
    }

    // introducere la inceput in lista
    Nod el2{};
    el2.ID = 2;
    strcpy(el2.nume, "nume 2");
    el2.an = 2;
    lista.push_front(el2);

    // introducere la final in lista
    Nod el3{};
    el3.ID = 3;
    strcpy(el3.nume, "nume 3");
    el3.an = 3;
    lista.push_back(el3);

    // Afisare elemente lista
    for (std::list<Nod>::iterator it = lista.begin(); it != lista.end(); it++) {
        cout << "ID: " << it->ID << " nume: " << it->nume << " an: " << it->an << endl;
    }
    // sortam elementele crescator
    lista.sort(comparAn);
    // Afisare elemente lista
    for (std::list<Nod>::iterator it = lista.begin(); it != lista.end(); it++) {
        cout << "ID: " << it->ID << " nume: " << it->nume << " an: " << it->an << endl;
    }
    return 0;
}



// Exercitiul 2.2. Modificati exercitiul 2.1. prin implementarea criteriului de ordonare dupa nume.
#include <iostream>
#include <list>
#include <cstring>

using namespace std;

struct Nod {
    int ID;
    char nume[50];
    int an;
};

bool comparNume(Nod &a, Nod &b){
    return a.nume == b.nume;
}

int main() {
    list<struct Nod> lista;

    // introducere la final in lista
    Nod el{};
    el.ID = 1;
    strcpy(el.nume, "nume 1");
    el.an = 1;
    lista.push_back(el);

    // Afisare elemente lista
    for (std::list<Nod>::iterator it = lista.begin(); it != lista.end(); it++) {
        cout << "ID: " << it->ID << " nume: " << it->nume << " an: " << it->an << endl;
    }

    // introducere la inceput in lista
    Nod el2{};
    el2.ID = 2;
    strcpy(el2.nume, "dume 2");
    el2.an = 2;
    lista.push_front(el2);

    // introducere la final in lista
    Nod el3{};
    el3.ID = 3;
    strcpy(el3.nume, "sume 3");
    el3.an = 3;
    lista.push_back(el3);

    // Afisare elemente lista
    for (std::list<Nod>::iterator it = lista.begin(); it != lista.end(); it++) {
        cout << "ID: " << it->ID << " nume: " << it->nume << " an: " << it->an << endl;
    }
    // sortam elementele crescator
    lista.sort(comparNume);
    // Afisare elemente lista
    for (std::list<Nod>::iterator it = lista.begin(); it != lista.end(); it++) {
        cout << "ID: " << it->ID << " nume: " << it->nume << " an: " << it->an << endl;
    }
    return 0;
}