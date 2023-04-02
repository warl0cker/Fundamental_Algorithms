// 7.1 Cautarea primei aparitii a unei valori dintr-un vector unidimensional, folosind cautarea secventiala.
#include <stdio.h>
int main() {
    int n, e;
    printf("Introduceti dimensiunea vectorului: ");
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++) {
        printf("arr[%d]=", i);
        scanf("%d", &arr[i]);
    }
    printf("\n");
    printf("Introduceti elementul pentru cautare: ");
    scanf("%d", &e);
    for (int i = 0; i < n; i++) {
        if (arr[i] == e) {
            printf("Elementul %d a fost gasit pe pozitia %d\n", e, i);
            return 0;
        }
    }
    printf("Elementul %d nu a fost gasit\n", e);
    return 0;
}

// 7.2  Aceeasi problema ca la 7.1 dar folosind cautarea binara si cautarea prin interpolare.
#include <stdio.h>
int cautareBinara(int arr[], int stanga, int dreapta, int e) {
    if (stanga > dreapta) return -1;
    else {
        int mijloc = (stanga + dreapta) / 2;
        if (e == arr[mijloc]) return mijloc;
        if (e < arr[mijloc]) return cautareBinara(arr, stanga, mijloc - 1, e);
        return cautareBinara(arr, mijloc + 1, dreapta, e);
    }
}
int cautareInterpolara(const int arr[], int inf, int sup, int x) {
    int m = 0;
    if ((x <= arr[sup]) && (x >= arr[inf])) {
        do {
            m = inf + (x - arr[inf]) * (sup - inf) / (arr[sup] - arr[inf]);
            if (x > arr[m]) inf = m + 1;
            else sup = m - 1;
        } while ((arr[m] != x) && (inf < sup) && (arr[inf] != arr[sup]) && (x >= arr[inf]) && (x <= arr[sup]));
	}
    return (arr[m] == x) ? m : -1;
}
int main() {
    int n, e, temp;
    printf("Introduceti dimensiunea vectorului: ");
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++) {
        printf("arr[%d]=", i);
        scanf("%d", &arr[i]);
    }
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    printf("\n");
    printf("Introduceti elementul pentru cautare: ");
    scanf("%d", &e);
    int search1 = cautareBinara(arr, 0, n - 1, e);
    int search2 = cautareInterpolara(arr, 0, n - 1, e);
    if (search1 != -1) printf("cautareBinara: Elementul %d a fost gasit pe pozitia %d\n", e, search1);
    if (search2 != -1) printf("cautareInterpolara: Elementul %d a fost gasit pe pozitia %d\n", e, search2);
    if ((search1 ^ search2) == -1) printf("Elementul %d nu a fost gasit\n", e);
    return 0;
}

// 7.3 Cautarea ultimei aparitii a unei valori dintr-un vector unidimensional, folosind cautarea binara.
#include <stdio.h>
int ultimaAparitie(int arr[], int stanga, int dreapta, int e) {
    if (stanga > dreapta) return -1;
    int mijloc = (stanga + dreapta) / 2;
    if (e == arr[mijloc]) {
        int pozitie = ultimaAparitie(arr, mijloc + 1, dreapta, e);
        return (pozitie == -1) ? mijloc : pozitie;
    }
    else if (e < arr[mijloc]) return ultimaAparitie(arr, stanga, mijloc - 1, e);
    else return ultimaAparitie(arr, mijloc + 1, dreapta, e);
}
int main() {
    int n, e, temp;
    printf("Introduceti dimensiunea vectorului: ");
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++) {
        printf("arr[%d]=", i);
        scanf("%d", &arr[i]);
    }
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    printf("\n");
    printf("Introduceti elementul pentru cautare: ");
    scanf("%d", &e);
    int search = ultimaAparitie(arr, 0, n-1, e);
    if (search != -1) {
        printf("cautareBinara: Elementul %d a fost gasit pe pozitia %d\n", e, search);
        return 0;
    }
    printf("Elementul %d nu a fost gasit\n", e);
    return 0;
}

// 7.4. Determinarea numarului de aparitii ale unui numar din multimea valorilor unui vector unidimensional, folosind cautarea secventiala.
#include <stdio.h>
int main() {
    int n, e, aparitii = 0;
    printf("Introduceti dimensiunea vectorului: ");
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++) {
        printf("arr[%d]=", i);
        scanf("%d", &arr[i]);
    }
    printf("\n");
    printf("Introduceti elementul pentru cautare: ");
    scanf("%d", &e);
    for (int i = 0; i < n; i++) if (arr[i] == e) aparitii++;
    if (aparitii) printf("Elementul %d a fost gasit de %d ori\n", e, aparitii);
    else printf("Elementul %d nu a fost gasit\n", e);
    return 0;
}

// 7.5 Modificati programul de la 7.4 folosind cautarea binara
#include <stdio.h>
int ultimaAparitie(int arr[], int stanga, int dreapta, int e) {
    if (stanga > dreapta) return -1;
    int mijloc = (stanga + dreapta) / 2;
    if (e == arr[mijloc]) {
        return 1 + ultimaAparitie(arr, mijloc + 1, dreapta, e)
                 + ultimaAparitie(arr, mijloc + 1, dreapta, e);
    }
    else if (e < arr[mijloc]) return ultimaAparitie(arr, stanga, mijloc - 1, e);
    else return ultimaAparitie(arr, mijloc + 1, dreapta, e);
}
int main() {
    int n, e, aparitii = 0;
    printf("Introduceti dimensiunea vectorului: ");
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++) {
        printf("arr[%d]=", i);
        scanf("%d", &arr[i]);
    }
    printf("\n");
    printf("Introduceti elementul pentru cautare: ");
    scanf("%d", &e);
    for (int i = 0; i < n; i++) if (arr[i] == e) aparitii++;
    if (aparitii) printf("Elementul %d a fost gasit de %d ori\n", e, aparitii);
    else printf("Elementul %d nu a fost gasit\n", e);
    return 0;
}

// 7.6 determinati elementul de varf dintre elementele unui vector unidimensional, folosin cautarea binara. Exemplu: 
// elementul 11 este varf pentru valorile vectorului: [7, 9, 11, 2, 5, 7],  [11, 8, 6, 5, 3, 2],  [2, 3, 6, 8, 9, 10,11]
#include <stdio.h>
#include <math.h>
int findMax(int arr[], int stanga, int dreapta) {
    if (stanga == dreapta) return arr[stanga];
    if (dreapta == stanga + 1) return fmax(arr[stanga], arr[dreapta]);
    int mijloc = (stanga + dreapta) / 2;
    int max1 = findMax(arr, stanga, mijloc);
    int max2 = findMax(arr, mijloc + 1, dreapta);
    return fmax(max1, max2);
}
int main() {
    int n, max;
    printf("Introduceti dimensiunea vectorului: ");
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++) {
        printf("arr[%d]=", i);
        scanf("%d", &arr[i]);
    }
    max = findMax(arr, 0, n-1);
    printf("Elementul de varf este: %d\n", max);
    return 0;
}

// 7.7 Cautarea elementului lipsa dintr-o secventa de valori ale unui vector unidimensional, intr-un timp logaritmic. Exemplu:
// pentru vectorul [3, 5, 7, 9, 11, 15] elementul lipsa este 13, iar pentru [1, 4, 7, 13, 16] elementul lipsa este 10
#include <stdio.h>
int elemLipsa(int arr[], int n) {
    int dif_max = arr[n - 1] - arr[0], dif_elem = dif_max / n, st = 0, dr = n - 1;
    while (st <= dr) {
        int mij = (st + dr) / 2;
        if ((arr[mij] - arr[0]) / dif_elem == mij) st = mij + 1;
        else dr = mij - 1;
    }
    return arr[dr] + dif_elem;
}
int main() {
    int arr1[] = {3, 5, 7, 9, 11, 15};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    int lipsa1 = elemLipsa(arr1, n1);
    printf("Elementul lipsa pentru vectorul arr1 este: %d\n", lipsa1);
    int arr2[] = {1, 4, 7, 13, 16};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    int lipsa2 = elemLipsa(arr2, n2);
    printf("Elementul lipsa pentru vectorul arr2 este: %d\n", lipsa2);
    return 0;
}

// 7.8 Determinarea radacinii patrate a unui numar intreg ( partea intraga), folosind o functie recursiva
#include <stdio.h>
int sqrt(int n, int stanga, int dreapta) {
    if (stanga == dreapta) return stanga;
    int mijloc = (stanga + dreapta) / 2;
    return (mijloc <= n / mijloc) ? sqrt(n, mijloc + 1, dreapta) : sqrt(n, stanga, mijloc);
}
int main() {
    int n;
    printf("Introduceti numarul: ");
    scanf("%d", &n);
    int radacina = sqrt(n, 0, n);
    printf("Radacina patrata a %d este %d\n", n, radacina);
    return 0;
}

// 7.9.* Implementati un algoritm de cautare ternara. Cautarea ternara presupune impartirea intervalului de cautare in 3 parti.
