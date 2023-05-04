// Exercitiul 10.1. Implementati intr-un program C algoritmul de interclasare pentru doua tablouri unidimensionale de n, respectiv m valori intregi.
#include <stdio.h>
void interclasare(int a[], int n, int b[], int m, int c[]) {
    int i = 0, j = 0, k = 0;
    while (i < n && j < m) {
        if (a[i] <= b[j]) {
            c[k++] = a[i++];
        } else {
            c[k++] = b[j++];
        }
    }
    while (i < n) {
        c[k++] = a[i++];
    }
    while (j < m) {
        c[k++] = b[j++];
    }
}
int main() {
    int n, m;
    scanf("%d", &n);
    scanf("%d", &m);
    int a[n], b[m], c[n + m];
    for (int i = 0; i < n; i++) {
        printf("arr_n[%d]= ", i);
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < m; i++) {
        printf("arr_m[%d]= ", i);
        scanf("%d", &b[i]);
    }
    interclasare(a, n, b, m, c);
    for (int i = 0; i < n + m; i++) printf("%d, ", c[i]);
    return 0;
}

// Exercitiul 10.2. Implementati intr-un program C/C++ algoritmul de sortare prin interclasare pentru un tablou unidimensional de n valori intregi: 57, 44, 101, 85, 15, 75, 11, 33.
#include <stdio.h>

void interclasare(int v[], int w[], int st, int m, int dr){
    int i = st;
    int j = m + 1;
    int k = 0;
    while(i <= m && j <= dr){
        if(v[i] <= v[j]){
            w[k] = v[i];
            i = i + 1;
        } else {
            w[k] = v[j];
            j = j + 1;
        }
        k = k + 1;
    }
    while(i <= m){
        w[k] = v[i];
        i = i + 1;
        k = k + 1;
    }
    while(j <= dr){
        w[k] = v[j];
        j = j + 1;
        k = k + 1;
    }
    for (i = 0; i <= k - 1; i++){
        v[i + st] = w[i];
    }
}

void mergesort(int v[], int w[], int st, int dr){
    if (st < dr){
        int m = (st + dr) / 2;
        mergesort(v, w, st, m);
        mergesort(v, w, m + 1, dr);
        interclasare(v, w, st, m, dr);
    }
}

int main(){
    int arr1[8] = {57, 44, 101, 85, 15, 75, 11, 33};
    int arr2[8];
    mergesort(arr1, arr2, 0, 7);
    for (int i = 0; i < 8; i++) printf("%d,", arr1[i]);
    return 0;
}

// Exercitiul 10.3. Implementati intr-un program C secventa de pivotare, prima iteratie, din algoritmul de sortare pentru un tablou unidimensional de n valori intregi: 57, 44, 101, 85, 15, 75, 11, 33. Afisati elementele vectorului dupa executia primei iteratii de pivotare. Observati si explicati efectul acesteia.
#include <stdio.h>
int pivotare(int v[], int st, int dr) {
    int pivot = v[st], s = st + 1, d = dr;
    while (s <= d) {
        while (v[d] > pivot) {
            d--;
        }
        while (v[s] < pivot && s <= d) {
            s++;
        }
        if (s <= d) {
            int temp = v[s];
            v[s] = v[d];
            v[d] = temp;
            d--;
            s++;
        }
    }
    v[st] = v[d];
    v[d] = pivot;
    return d;
}
int main() {
    int v[] = {57, 44, 101, 85, 15, 75, 11, 33};
    int n = sizeof(v) / sizeof(v[0]);
    int poz = pivotare(v, 0, n - 1);
    printf("Elementele tabloului dupa executia primei iteratii de pivotare sunt:\n");
    for (int i = 0; i < n; i++) printf("%d ", v[i]);
    return 0;
}
