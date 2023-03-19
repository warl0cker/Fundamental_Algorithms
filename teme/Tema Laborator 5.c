// 5.1. Scrieți un program C/C++ care pentru 2 numere returneaza adevărat dacă unul dintre ele  sau dacă suma lor este 30.
#include <stdio.h>
int main() {
    int n1, n2;
    scanf("%d", &n1);
    scanf("%d", &n2);
    if (n1 == 30 || n2 == 30 || n1 + n2 == 30)
        printf("True\n");
    else
        printf("False\n");
    return 0;
}

// 5.2. Scrieți un program C/C++ pentru a verifica dacă două numere întregi nenegative date au aceeași ultima cifră.
#include <stdio.h>
int main() {
    int n1, n2;
    do {
        scanf("%d", &n1);
        scanf("%d", &n2);
    } while (n1 <= 0 || n2 <= 0);
    int last_n1 = n1 % 10, last_n2 = n2 % 10;
    if (last_n1 == last_n2)
        printf("Cele doua numere au aceiasi ultima cifra\n");
    else
        printf("Cele doua numere NU au aceiasi ultima cifra\n");
    return 0;
}

// 5.3. Scrieți un program C/C++ pentru a verifica dacă două numere întregi nenegative date au același cel mai putin semnificativ bit. Folositi cel putin 2 metode.
#include <stdio.h>
int main() {
    int n1, n2;
    do {
        scanf("%d", &n1);
        scanf("%d", &n2);
    } while (n1 < 0 || n2 < 0);
    // folosim operatorul AND (&)
    if ((n1 & 1) == (n2 & 1))
		printf("Numerele au același cel mai putin semnificativ bit\n");
    else
		printf("Numerele NU au același cel mai putin semnificativ bit\n");
    // folosim operatorul XOR (^)
    if ((n1 ^ n2) & 1)
		printf("Numerele au același cel mai putin semnificativ bit\n");
    else
		printf("Numerele NU au același cel mai putin semnificativ bit\n");
    return 0;
}

// 5.4. Scrieti un program C/C++ pentru eliminarea cifrelor divizibile cu 3 din numar. Folositi cel putin 2 metode.
#include <stdio.h>
int main() {
    int n, rest, nou = 0;
    scanf("%d", &n);
    int temp = n;
    while (temp > 0) {
        rest = temp % 10;
        temp /= 10;
        if (rest % 3 != 0) nou = nou * 10 + rest;
    }
    printf("Metoda 1: %d\n", nou);
    return 0;
}

// 5.5. Scrieti un program C/C++ pentru inversarea ordinii elementelor unui vector unidimensional. Folositi cel putin 2 metode.
#include <stdio.h>
int main() {
    int n;
    scanf("%d", &n);
    int arr[n], temp[n];
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
    printf("Metoda 1 prin array temporar: ");
    for (int i = n - 1, j = 0; i >= 0; i--, j++) temp[j] = arr[i];
    for (int i = 0; i < n; i++) arr[i] = temp[i];
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");
    printf("Metoda 2 prin interschimbarea elementelor: ");
    for (int i = n - 1, j = 0; i >= 0; i--, j++) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");
    return 0;
}

// 5.6. Scrieti un program C/C++ pentru inversarea unui sir de caractere  fara a utiliza memorie suplimentara.
#include <stdio.h>
#include <string.h>
void reverse(char* str) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
}
int main() {
    char str[100];
    scanf("%[^\n]", str);
    reverse(str);
    printf("Stringul invers: %s\n", str);
    return 0;
}

// 5.7. Scrieţi un program  care demonstrează că  din numărul 4 se poate obţine orice număr natural n prin aplicarea următoarelor operaţii:
// - se adaugă la sfârşit cifra 4;
// - se adaugă la sfârşit cifra 0;
// - dacă numărul este par, se împarte la 2.
// Programul afiseaza un şir de numere construit conform regulilor precedente,  în care primul număr este 4 iar ultimul este n.
// Indicaţie: Şirul se va genera invers, de la n la 4, aplicând transformarile inverse. Spre exemplu: n=125, rezulta: 250, 25, 50, 5,10, 1, 2, 4.
