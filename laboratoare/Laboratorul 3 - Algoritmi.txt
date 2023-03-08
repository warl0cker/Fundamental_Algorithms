/************************************************************/
3.1
I.
    - a. 2 variante, binara si secventiala.
    - b. binara
II.
    - pentru secvential O(n)=100 iar pentru binar O(log(n))=7.

/************************************************************/
3.2
    - folosim o matrice bidimensionala, zidurile le marcam cu
    -1, drumul il marcam cu 0 si orice mutare incrementeaza cu
    +1 drumul parcurs. la final alegem drumul cel mai scurt.
    Drumul cel mai scurt este prin dreapta.

    -1 -1 -1 -1 -1 13 -1 -1
    -1 10 11 12 13 12 11 -1
    -1  9 -1 -1 -1 -1 10 -1
    -1  8 -1  X -1 10  9 -1
    -1  7 -1  1 -1 -1  8 -1
    -1  6 -1  2 -1  6  7 -1
    -1  5  4  3  4  5  6 -1
    -1 -1 -1 -1 -1 -1 -1 -1

/************************************************************/
3.3
    - adunare repetitiva. Se dau doua numere a,b inmultite.
    int sum=0;
    for(int i=1; i<=b; i++){
      sum += a;
    }

/************************************************************/
3.4
    - adunare repetitiva. Se dau trei numere a,b,c inmultite.
    int sum=0, sum2=0;
    for(int i=1; i<=b; i++){
      sum += a;
    }
    for(int i=1; i<=c; i++){
      sum2 += sum;
    }

/************************************************************/
3.5
    - 

/************************************************************/
