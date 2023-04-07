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

/*
 * 8.7 Având în vedere un vector unidimensional, găsiți numărul total de inversiuni ale acestuia.
 * Dacă (i < j) și (A[i] > A[j]), atunci perechea (i, j) se numește o inversare a unui vector A.
 * Trebuiesc numărate toate astfel de perechi din tablou. Exemplu: 
 * Input:  A[] = [1, 9, 6, 4, 5]
 * Output: Numarul de inversari este 5:  (9, 6), (9, 4), (9, 5), (6, 4), (6, 5)
 */
