// 8.5. Scrieti un program recursiv care calculeaza 3n-2n.
#include <stdio.h>
int putere1(int n, int a, int b){
    if (n == 0) return 0;
    if (n == 1) return a - b;
    return putere1(n-1, 3 * a, 2 * b);
}
int putere2(int nr, int n){
    if (n == 0) return 1;
    if (n == 1) return nr;
    return nr * putere2(nr, n - 1);
}
int main(){
    int n;
    int a = 3, b = 2;
    scanf("%d", &n);
    printf("%d\n", putere1(n, a, b));
    printf("%d\n", (putere2(a, n) - putere2(b, n)));
    return 0;
}

// 8.6. Scrieti un program recursiv care calculeaza factorialul unui numar natural n.
#include <stdio.h>
int factorial(int n){
    if(n == 1) return n;
    return n * factorial(n - 1);
}
int main(){
    int n;
    scanf("%d", &n);
    printf("%d", factorial(n));
    return 0;
}

/**
 *
 * 8.7 Având în vedere un vector unidimensional, găsiți numărul total de inversiuni ale acestuia.
 * Dacă (i < j) și (A[i] > A[j]), atunci perechea (i, j) se numește o inversare a unui vector A.
 * Trebuiesc numărate toate astfel de perechi din tablou. Exemplu: 
 * Input:  A[] = [1, 9, 6, 4, 5]
 * Output: Numarul de inversari este 5:  (9, 6), (9, 4), (9, 5), (6, 4), (6, 5)
 *
 */
#include <stdio.h>
int main(){
    int arr[] = {1, 9, 6, 4, 5};
    size_t length = sizeof(arr) / sizeof(arr[0]);
    for(int i = 0; i < length; i++){
        for(int j = 0; j < length; j++){
           if (i < j && arr[i] > arr[j]) printf("(%d,%d), ", arr[i], arr[j]);
        }
    }
    return 0;
}

/**
 *
 * 8.8. Determinati elementul cel mai mic diferit de 0 lipsa dintre elementele unui vector unidimensional, ordonat crescator. 
 * Exemplu:
 * Input:  nums[] = [0, 1, 2, 6, 9, 11, 15]
 * Output: Cel mai mic element lipsa este: 3
 *
 */
#include <stdio.h>
int main() {
    int arr[] = {0, 1, 2, 6, 9, 11, 15};
    size_t n = sizeof(arr) / sizeof(arr[0]);
	int st = 0, dr = n-1, int = mij;
	while (st <= dr) {
	    mij = (st + dr) / 2;
	    if (arr[mid] == mij) st = mij + 1;
	    else dr = mij -1;
	}
	printf("Cel mai mic element lipsa este: %d\n", st);
}

// 8.9. Aceeasi problema ca la exercitiul 8.9, dar utilizand un algoritm in timp de executie logaritmic.
#include <stdio.h>
int cautaElemLipsa(int arr[], int st, int dr){
    if (st > dr) return st;
    int mij = (st + dr) / 2;
    if (arr[mij] == mij) return cautaElemLipsa(arr, mij + 1, dr);
    else return cautaElemLipsa(arr, st, mij - 1);
}
int main() {
    int arr[] = {0, 1, 2, 6, 9, 11, 15};
    size_t n = sizeof(arr) / sizeof(arr[0]);
    printf("%d\n", cautaElemLipsa(arr, 0, n-1));
    return 0;
}
