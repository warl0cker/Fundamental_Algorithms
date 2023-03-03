/* Exercitiul 2.1. Creati un program pentru implementarea unei stive, utilizand vectori in STL, plecand de la codul sursa de mai jos:
 * TODO 
 * - adaugare 3 intregi in stiva( adaugare la finalul vectorului)
 * - afisare elemente 
 * - verificare daca mai sunt elemente in vector
 * - creare o alta stiva si introducere valori
 * - testare daca cei doi vectori sunt egali
 * - stergerea unuia dintre  vectori
 */
#include <iostream>
#include <vector>
using namespace std;
int main() {
    vector<int> firstVector;
    for (auto i = 0; i < 3; i++)
        firstVector.push_back(i + i);
    vector<int>::iterator it;
    for (it = firstVector.begin(); it != firstVector.end(); it++)
        cout << *it << " ";
    cout << endl;
    vector<int> secondVector;
    for (auto i = 0; i < 5; i++)
        secondVector.push_back(i * i);
    if (firstVector == secondVector) {
        cout << "Vectorii sunt egali" << endl;
    } else {
        cout << "Vectorii nu sunt egali" << endl;
    }
    secondVector.clear();
	cout << "Vectorul 2 a fost sters" << endl;
    return 0;
}



// Exercitiul 2.2. Descarcati de aici fisierul AF-INFO1-5-2.cpp, si completati codul conforma instructiunilor.
#include <iostream>
#include <list>
#include <queue>
using namespace std;
int main () {
    list<int> L1;                       // lista vida
    list<int> L2(4, 100);               // 4 intregi cu valoarea 100
    list<int> L3(L2.begin(), L2.end()); // iterare de la L2 de la inceput la final
    list<int> L4(L3);                   // o cpie a L3
    L1.push_back(12);
    L1.push_back(21);
    cout << "Continutul L1 este ";
    for (list<int>::iterator it = L1.begin(); it != L1.end(); it++)
        cout << *it << ' ';
    cout << endl;

    L1.push_front(98);
    L1.push_front(89);
    cout << "Continutul L1 este ";
    for (list<int>::iterator it = L1.begin(); it != L1.end(); it++)
        cout << *it << ' ';
    cout << endl;
    // au fost adaugate 2 elemente in partea dreapta

    L1.pop_back();
    cout << "Continutul L1 este ";
    for (list<int>::iterator it = L1.begin(); it != L1.end(); it++)
        cout << *it << ' ';
    cout << endl;
    // a fost scos primul element din partea stanga

    for (list<int>::iterator it = L2.begin(); it != L2.end(); it++)
        cout << *it << ' ';
    list<int>::iterator j = L3.begin();
    list<int>::iterator k = L4.begin();
    while (j != L3.end() && k != L4.end()) {
        if (*j < *k) {
            L2.push_back(*j);
            j++;
        } else if (*k < *j) {
            L2.push_back(*k);
            k++;
        } else {
            L2.push_back(*j);
            j++;
            k++;
        }
    }
    while (j != L3.end()) {
        L2.push_back(*j);
        j++;
    }
    while (k != L4.end()) {
        L2.push_back(*k);
        k++;
    }
    for (list<int>::iterator it = L2.begin(); it != L2.end(); it++)
        cout << *it << ' ';

    int vInt[] = {16, 2, 77, 29};
    list<int> L5(vInt, vInt + sizeof(vInt) / sizeof(int));
    cout << "Continutul L5 este ";
    for (list<int>::iterator it = L5.begin(); it != L5.end(); it++)
        cout << *it << ' ';
    cout << endl;
    return 0;
}



// Exercitiul 2.3. Implementati codul sursa pentru o lista de structuri utilizand STL, avand  definirea de mai jos:
#include <iostream>
#include <list>
#include <cstring>

using namespace std;

struct Nod {
    int ID;
    char nume[50];
    int an;
};

int main() {
    list<struct Nod> lista;

    // introducere la final in lista
    Nod el;
    el.ID = 1;
    strcpy(el.nume, "nume 1");
    el.an = 1;
    lista.push_back(el);

    // Afisare elemente lista
    for (std::list<Nod>::iterator it = lista.begin(); it != lista.end(); it++) {
        cout << "ID: " << it->ID << " nume: " << it->nume << " an: " << it->an << endl;
    }

    // introducere la inceput in lista
    Nod el2;
    el2.ID = 2;
    strcpy(el2.nume, "nume 2");
    el2.an = 2;
    lista.push_front(el2);

    // introducere la final in lista
    Nod el3;
    el3.ID = 3;
    strcpy(el3.nume, "nume 3");
    el3.an = 3;
    lista.push_back(el3);

    // Afisare elemente lista
    for (std::list<Nod>::iterator it = lista.begin(); it != lista.end(); it++) {
        cout << "ID: " << it->ID << " nume: " << it->nume << " an: " << it->an << endl;
    }
    return 0;
}