// 3.1. Implementati un program pentru rezolvarea exercitiului 3.1  din laborator
// cautare secventiala
#include <stdio.h>
int main(){
    int n, arr[10] = {5,4,3,2,1,9,8,7,6,10};
    do{
        scanf("%d", &n);
    }while(n>10 && n<1);
    for(int i=0; i<n; i++){
        if(i==n){
            printf("Numarul %d se afla pe pozitia %d", n,i);
            break;
        }
    }
    return 0;
}

/* 3.2. Implementati un program pentru calculul urmatoarei expresii:
 * E = 1+1*2+1*2*3+ ... + 1*2*3*...*n, in 2 variante:
 * a. Calculul sumei produselor la fiecare iteratie
 * b. Calculul sumei folosindu-ne de  produsul calculat la iteratia anteioara
 */
// Calculul sumei produselor la fiecare iteratie
#include <stdio.h>
int main(){
    int n, prd, sum=0;
    do {
        scanf("%d", &n);
    }while(n<1);
    for(int i=1; i<=n; i++){
        prd = 1;
        for(int j=1; j<=i; j++){
            prd *= j;
        }
        sum += prd;
    }
    printf("%d", sum);
}

// Calculul sumei folosindu-ne de  produsul calculat la iteratia anteioara
#include <stdio.h>
int main(){
    int n, prd=1, sum=0;
    do {
        scanf("%d", &n);
    }while(n<1);
    for(int i=1; i<=n; i++){
        prd *= i;
        sum += prd;
    }
    printf("%d", sum);
}
