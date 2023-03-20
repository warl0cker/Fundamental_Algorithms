// 5.1 Scrieti un program care demonstreaza ca suma numerelor de la 1 la n este egala cu n(n+1)/2
#include <stdio.h>
int main() {
    int n, suma = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) suma += i;
    if (suma == (n * (n + 1) / 2))
        printf("Suma numerelor de la 1 la %d este egala cu %d(%d+1)/2\n", n, n, n);
    else
        printf("Suma numerelor de la 1 la %d NU este egala cu %d(%d+1)/2\n", n, n, n);
    return 0;
}

// 5.2 Scrieti un program care demonstreaza ca suma patratelor numerelor de la 1 la n este egala cu n(n+1)(2n+1)/6
#include <stdio.h>
int main() {
    int n, suma = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) suma += (i * i);
    if (suma == (n * (n + 1) * (2 * n + 1) / 6))
        printf("Suma patratelor numerelor de la 1 la %d este egala cu %d*(%d+1)*(2*%d+1)/6", n, n, n, n);
    else
        printf("Suma patratelor numerelor de la 1 la %d NU este egala cu %d*(%d+1)*(2*%d+1)/6", n, n, n, n);
    return 0;
}

// 5.3 Scrieti un program care determina divizorul numerelor de forma n3+2n, n>0. Dar pentru n5-n
#include <stdio.h>
int main() {
    int n, nr, div;
    do {
        scanf("%d", &n);
    } while (n <= 0);
    nr = (n * n * n) + (2 * n);
    printf("Pentru numarul %d divizorii sunt: ", nr);
    for (div = 1; div <= nr / 2; div++) {
        if (nr % div == 0) printf("%d ", div);
    }
    printf("\n");
    return 0;
}

// 5.4 Scrieti un program care calculeaza ab, a si b numere naturale,  prin 2 metode diferite,
#include <stdio.h>
long putere1(int a, int b) {
    long produs = 1;
    for (int i = 1; i <= b; i++) produs *= a;
    return produs;
}
long putere2(int a, int b) {
    if (b == 0) return 1;
    int c = putere2(a, b - 1);
    int sum = 0;
    for (int i = 0; i < c; i++) sum += a;
    return sum;
}
int main() {
    int a, b;
    scanf("%d", &a);
    scanf("%d", &b);
    printf("Prima metoda: %ld\n", putere1(a, b));
    printf("A doua metoda: %ld\n", putere2(a, b));
    return 0;
}

// 5.5 Scrieti un program care determina elementul minim de pe linia elementului maxim dintr-un vector bidimensional.
#include <stdio.h>
int main() {
    int arr[5][5] = { 1,  2,  3,  4,  5,
                     10, 11, 12, 13, 14,
                      9,  8,  7,  6,  0,
                     20, 21, 22, 23, 24,
                     19, 18, 17, 16, 10,
    };
    int biggestLine = 0;
    int max = arr[biggestLine][0];
    for (int i = 0; i < 5; i++) {
        for (int j = 1; j < 5; j++) {
            if (max < arr[i][j]) {
                max = arr[i][j];
                biggestLine = i;
            }
        }
    }
    int min = arr[biggestLine][0];
    for (int i = 0; i < 5; i++) {
        if (min > arr[biggestLine][i])
            min = arr[biggestLine][i];
    }
    printf("Elementul minim %d de pe linia %d\n", min, biggestLine);
    printf("Elementul maxim %d de pe linia %d\n", max, biggestLine);
    return 0;
}

// 5.6 Scrieti un program care inverseaza un numar intreg, dupa care elimina din numarul rezultat cifrele pare, daca exista, fara a inversa numarul.
#include <stdio.h>
int main() {
    long nr, rest, temp = 0, result = 0;
    scanf("%ld", &nr);
    while (nr != 0) {
        rest = nr % 10;
        temp = temp * 10 + rest;
        nr /= 10;
    }
    while (temp != 0) {
        rest = temp % 10;
        if (rest % 2 != 0)
            result = result * 10 + rest;
        temp /= 10;
    }
    printf("Numarul final este: %ld\n", result);
    return 0;
}
