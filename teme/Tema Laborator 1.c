/*
 * 1.1. Pornind de la definitia de mai jos:
 * typedef struct Carti {
 *     char titlu[50], autor[50], domeniu[100];
 *     int  id_carte;
 * } carte; 
 * Implementati un program in care sa definiti cateva functii: introducere, adaugare, afisare, cautare, utilizate intr-un program principal.
 */
#include <stdio.h>
#include <string.h>

typedef struct carte {
    char titlu[50], autor[50], domeniu[100];
    int  id_carte;
} carte;

carte citire(int n){
    carte c;
    printf("Titlul: ");
    fgets(c.titlu, 50, stdin);
    printf("Autorul: ");
    fgets(c.autor, 50, stdin);
    printf("Domeniul: ");
    fgets(c.domeniu, 100, stdin);
    c.id_carte = n;
    return c;
}
void afisare(carte c){
    printf("%s %s %s %d\n", c.titlu, c.autor, c.domeniu, c.id_carte);
}
void cautare(carte c[], int n, char *keyword) {
    int ok = 1;
    for (int i = 0; i < n && ok; i++) {
        if (strcmp(c[i].autor, keyword) == 0 || strcmp(c[i].titlu, keyword) == 0) {
            ok = 0;
            afisare(c[i]);
        }
    }
}

int main() {
    int n,i;
    printf("Introdu in biblioteca numarul de carti: ");
    scanf("%d", &n);
    carte biblioteca[n];
    for (i = 0; i < n; i++)
        biblioteca[i] = citire(i);
    printf("Cauta o carte dupa autor sau titlu: ");
    char keyword[50];
    fgets(keyword, 50, stdin);
    cautare(biblioteca, n, keyword);
    return 0;
}



/*
 * 1.2. Scrieti un program in C in care definiti o structura pentru a modela un numar complex avand componente reale si functii pentru operatorii aritmetici cu numere complexe. Folositi functiile in mod corespunzator.
 * struct Complex {
 *     float x, y;
 * };
 * struct Complex citeste();
 * void afiseaza(struct Complex a);
 * struct Complex adunare(struct Complex a, struct Complex b);
 * struct Complex scadere(struct Complex a, struct Complex b);
 * struct Complex inmultire(struct Complex a, struct Complex b);
 * struct Complex modul(struct Complex a);
 */
#include <stdio.h>
#include <math.h>

typedef struct Complex {
    float x, y;
    double modul;
} Complex;

Complex citeste() {
    Complex a;
    scanf("%f", &a.x);
    scanf("%f", &a.y);
    return a;
}
void afiseaza(Complex a) {
    printf("%f %f\n", a.x, a.y);
}
Complex adunare(Complex a, Complex b) {
    Complex c;
    c.x = a.x + b.x;
    c.y = a.y + b.y;
    return c;
}
Complex scadere(Complex a, Complex b) {
    Complex c;
    c.x = a.x - b.x;
    c.y = a.y - b.y;
    return c;
}
Complex inmultire(Complex a, Complex b) {
    Complex c;
    c.x = a.x * b.x + a.y * b.y * (-1);
    c.y = a.x * b.y + a.y * b.x;
    return c;

}
void modul(Complex *a) {
    a->modul = sqrt(pow(a->x, 2) + pow(a->y, 2));
}

int main () {
    Complex arr[2];
    arr[0] = citeste();
    arr[1] = citeste();
    Complex sum = adunare(arr[0], arr[1]);
    Complex dif = scadere(arr[0], arr[1]);
    Complex prd = inmultire(arr[0], arr[1]);
    modul(&sum);
    modul(&dif);
    modul(&prd);
    afiseaza(sum);
    afiseaza(dif);
    afiseaza(prd);
    return 0;
}



// 1.3. Pentru structura de mai sus, cititi dintr-un fisier componentele a n numere complexe si ordonati-le descrescator dupa valoarea modulului acestora.
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LEN 256

typedef struct Complex {
    float x, y;
    double modul;
} Complex;

Complex citeste(float x, float y) {
    Complex a;
    a.x = x;
    a.y = y;
    return a;
}
void afiseaza(Complex a, int n) {
    printf("[%d] -> %f, %f, %f\n", n, a.x, a.y, a.modul);
}
void modul(Complex *a) {
    a->modul = sqrt(pow(a->x, 2) + pow(a->y, 2));
}
void ordoneaza(Complex a[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i].modul < a[j].modul) {
                Complex tmp = a[i];
                a[i] = a[j];
                a[j] = tmp;
            }
        }
    }
}

int main (int argc, char *argv[]) {
    if (argc != 2) {
        printf("\n[*] Usage:\n\t%s <fisier>\n\n", argv[0]);
        return 0;
    }
    FILE *fp;
    int ch, i = 0, n = 0;
    char buffer[MAX_LEN];
    fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("[-] FATAL: Could not open file %s\n", argv[1]);
        return 0;
    }
    while ((ch = fgetc(fp)) != EOF) {
        if (ch == '\n') n++;
    }
    printf("[*] We've got %d lines in %s\n", n, argv[1]);
    fseek(fp, 0, SEEK_SET);
    Complex numbers[n];
    printf("[*] Saving data into struct and sort it\n");
    while(fgets(buffer, MAX_LEN, fp)) {
		buffer[strcspn(buffer, "\n")] = 0;
        char *a = strtok(buffer, " ");
        char *b = strtok(NULL, " ");
        numbers[i] = citeste(strtod(a, NULL), strtod(b, NULL));
        modul(&numbers[i]);
        i++;
    }
    fclose(fp);
    ordoneaza(numbers, n);
    printf("\n[*] Print sorted data: \n");
    for (i = 0; i < n; i++)
        afiseaza(numbers[i], i);
	printf("\n[~] Done.\n\n");
    return 0;
}



// 1.4.* Modificati codul sursa de la  1.2, 1.3 folosind conceptele Programarii Orientat Obiect, similar cu exercitiul 1.1. din laborator.
// exercitiu 1.2
#include <iostream>
#include <cmath>

using namespace std;

typedef struct data {
    float x, y;
} data;

class Complex {
private:
    data numar{};
    float modulx;
public:
    Complex(data a){
        numar = a;
        modulx = modul(numar);
    }
    void afiseaza() const {
        printf("%f %f %f\n", numar.x, numar.y, modulx);
    }
    static data adunare(data a, data b) {
        data c;
        c.x = a.x + b.x;
        c.y = a.y + b.y;
        return c;
    }
    static data scadere(data a, data b) {
        data c;
        c.x = a.x - b.x;
        c.y = a.y - b.y;
        return c;
    }
    static data inmultire(data a, data b) {
        data c;
        c.x = a.x * b.x + a.y * b.y * (-1);
        c.y = a.x * b.y + a.y * b.x;
        return c;
    }
    static float modul(data a) {
        return sqrt(pow(a.x, 2) + pow(a.y, 2));
    }
};

int main() {
    data n1, n2;
    cin >> n1.x;
    cin >> n1.y;
    cin >> n2.x;
    cin >> n2.y;
    Complex sum = Complex::adunare(n1, n2);
    sum.afiseaza();
    Complex dif = Complex::scadere(n1, n2);
    dif.afiseaza();
    Complex prd = Complex::inmultire(n1, n2);
    prd.afiseaza();
    return 0;
}
