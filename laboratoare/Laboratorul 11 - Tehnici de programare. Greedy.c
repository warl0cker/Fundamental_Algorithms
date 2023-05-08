// 11.1 Problema fracţionară a rucsacului
#include <stdio.h>
#include <stdlib.h>
struct obiect{
    float greutate;
    float valoare;
    int index;
};
void sort_desc(struct obiect ob[], int n) {
    struct obiect temp;    
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < (n - 1 - i); j++) {
            if (ob[j].valoare/ob[j].greutate < ob[j + 1].valoare/ob[j + 1].greutate) {
                temp = ob[j];
                ob[j] = ob[j + 1];
                ob[j + 1] = temp;
            } 
        }
    }
}
void rucsac(struct obiect ob[], int n, float M) {
	sort_desc(ob, n);
	float s = 0;
	int i = 0;
	while (s + ob[i].greutate <= M && i < n) {
		s += ob[i].greutate;
		printf("Obiectul %d a fost introdus complet - valoarea %f - greutatea %f\n", ob[i].index, ob[i].valoare, ob[i].greutate);
		i += 1;
	}
	if (s < M && i < n) {
		printf("Obiectul %d a fost introdus partial - valoarea %f - greutatea %f\n", ob[i].index, ob[i].valoare*(M - s)/ob[i].greutate, M-s);
	}
}
int main(int argc, char** argv) {
    float M = 100;
    int n = 7;
    struct obiect ob[100];
    for(int i = 0; i < n; i++) {
        printf("Introdu valoarea si greutatea obiectului %d:", i+1);
        scanf("%f %f", &ob[i].valoare, &ob[i].greutate);
        ob[i].index = i + 1;
    }
    rucsac( ob, n, M);
    return (EXIT_SUCCESS);
}


// 11.2 Colorarea unei hărţi ( zone)
#include <stdio.h>
void colorare(int n, int v[], int t[20][20]) {
	int c = 1, cmax = 1, ok = 0;
	v[0] = 1;
	for (int i = 1; i < n; i++) {
		c = 1;
		do {
			ok = 1;
			for (int j = 0; j < i; j++) {
				if (t[i][j] == 1 && v[j] == c) ok = 0;
			}
			if (ok == 1) v[i] = c;
			else c += 1;
		} while (ok == 0);
		if (c > cmax) cmax = c;
	}
}
int main() {
	int t[20][20] = {
		{0,1,1,1,0,1,0},
		{1,0,1,0,0,1,0},
		{1,1,0,0,0,0,0},
		{1,0,0,0,1,1,0},
		{0,0,0,1,0,1,1},
		{1,1,0,1,1,0,1},
		{0,0,0,0,1,1,0}
	};
	int v[20], n = 7;
	colorare(n, v, t);
	for (int i = 0; i < n; i++) printf("%d ", v[i]);
	return 0;
}

// 11.3 Pentru un vector unidimensional, determinati suma a[i]*i, astfel incat aceasta sa fie maxima. Folositi un algoritm Greedy. Pentru [10,2,13,40,5] suma maxima este 224.
#include <stdio.h>
int main() {
	int n, suma = 0;
	scanf("%d", &n);
	int arr[n];
	for(int i = 0; i < n; i++){
		printf("arr[%d]=", i);
		scanf("%d", &arr[i]);
	}
	for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < (n - 1 - i); j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            } 
        }
    }
	for(int i = 0; i < n; i++) suma += arr[i] * i;
	printf("Suma maxima este %d", suma);
	return 0;
}