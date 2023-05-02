// Tema 9.1. Implementaţi algoritmul de sortare prin selecţia maximului crescator.
#include <stdio.h>
void selectie_maxim_crescator(int arr[], int n){
	int poz_max, j;
	for (int i = n - 1; i >= 0; i--) {
        poz_max = i;
        for (j = 0; j < i; j++) if (arr[j] > arr[poz_max]) poz_max = j;
        int aux = arr[poz_max];
        arr[poz_max] = arr[i];
        arr[i] = aux;
    }
    for (int i = 0; i < n; i++) printf("%d, ", arr[i]);

}
int main() {
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++) {
        printf("arr[%d]= ", i);
        scanf("%d", &arr[i]);
    }
	selectie_maxim_crescator(arr, n);
    return 0;
}

// Tema 9.2. Pentru algoritmii de sortare prin inserţie, respectiv prin selecţia minimului, scrieţi variantele care ordonează descrescător elementele vectorului v.
#include <stdio.h>
void insertie_descrescator(int arr[], int n) {
    int aux, j;
    for (int i = 1; i < n; i++) {
        aux = arr[i];
        j = i - 1;
        while (aux > arr[j] && j >= 0) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = aux;
    }
    for (int i = 0; i < n; i++) printf("%d, ", arr[i]);
}
void selectie_minim_descrescator(int arr[], int n) {
    int poz_min, aux, j;
    for (int i = 0; i < n - 1; i++) {
        poz_min = i;
        j = i - 1;
        for (j = i + 1; j < n; j++) if (arr[j] > arr[poz_min]) poz_min = j;
        if (poz_min != i) {
            aux = arr[poz_min];
            arr[poz_min] = arr[i];
            arr[i] = aux;
        }
    }
    for (int i = 0; i < n; i++) printf("%d, ", arr[i]);
}
int main() {
    int n;
    scanf("%d", &n);
    int arr1[n], arr2[n];
    for (int i = 0; i < n; i++) {
        printf("arr[%d]= ", i);
        scanf("%d", &arr1[i]);
        arr2[i] = arr1[i];
    }
    insertie_descrescator(arr1, n);
    printf("\n");
    selectie_minim_descrescator(arr2, n);
    return 0;
}

// Tema 9.3. Sortare prin numărare. Fie un vector de n numere naturale ale cărui elemente fac parte din mulţimea {0; 1; 2; ... ;m-1}, unde m este cel mult egal cu n. Să se sorteze crescător elementele vectorului astfel încât complexitatea algoritmului folosit să fie liniară.
// Indicaţie: se construieşte un vector w cu m elemente în care w[i] reprezintă frecvenţa de apariţie a lui i în şirul dat, oricare ar fi 0 ≤ i < m; se construieşte şirul sortat crescător folosind informaţia din w. La implementare se ţine cont de timpul de execuţie astfel încât complexitatea să fie O(n + m).
#include <stdio.h>
int find_max(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) if (arr[i] > max) max = arr[i];
    return max;
}
void numarare(int arr[], int n) {
    int max = find_max(arr, n);
    int m = max + 1, w[m], output[n], index = 0;
    for (int i = 0; i < m; i++) w[i] = 0;
    for (int i = 0; i < n; i++) w[arr[i]]++;
    for (int i = 0; i < m; i++) {
        while (w[i] > 0) {
            output[index++] = i;
            w[i]--;
        }
    }
    for (int i = 0; i < n; i++) arr[i] = output[i];
    for (int i = 0; i < n; i++) printf("%d, ", arr[i]);
}
int main() {
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++) {
        printf("arr[%d]= ", i);
        scanf("%d", &arr[i]);
    }
    numarare(arr, n);
    return 0;
}

// Tema 9.4.*. Fie un vector de n numere naturale ale cărui elemente fac parte din mulţimea {0; 1; 2; ... ;m - 1}, unde m este cel mult egal cu n. Să se modifice vectorul construit la problema anterioară, folosind orice algoritm, astfel încât, dacă se doreşte răspunsul la întrebarea: câte elemente sunt în intervalul [a; b], cu 0  ≤ a  ≤ b < m?, să se obţină în timp constant această problemă este relevantă atunci când şirul se modifică foarte rar în timp, însă interogări ca cea de mai sus se produc frecvent).
#include <stdio.h>
int find_max(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) if (arr[i] > max) max = arr[i];
    return max;
}
void frecventa_numar(int arr[], int n, int w[], int m) {
    for (int i = 0; i < m; i++) w[i] = 0;
    for (int i = 0; i < n; i++) w[arr[i]]++;
}
void prefix_suma(int w[], int m, int arr[]) {
    arr[0] = w[0];
    for (int i = 1; i < m; i++) arr[i] = arr[i - 1] + w[i];
}
int numara_elemente(int arr[], int a, int b) {
    return (a == 0) ? arr[b] : arr[b] - arr[a - 1];
}
int main() {
    int n, a, b;
    scanf("%d", &n);
    printf("start interval:");
    scanf("%d", &a);
    printf("sfarsit interval:");
    scanf("%d", &b);
    int arr[n];
    for (int i = 0; i < n; i++) {
        printf("arr[%d]= ", i);
        scanf("%d", &arr[i]);
    }
    int max = find_max(arr, n);
    int m = max + 1, w[m], suma_prefix[m];
    frecventa_numar(arr, n, w, m);
    prefix_suma(w, m, suma_prefix);
    int count = numara_elemente(suma_prefix, a, b);
    printf("Numarul de elemente in intervalul [%d, %d] este: %d\n", a, b, count);
    return 0;
}
