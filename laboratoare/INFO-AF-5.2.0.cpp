#include <iostream>
#include <list>
#include <queue>

using namespace std;

int main ()
{

  list<int> L1;                                // lista vida
  list<int> L2 (4,100);                        // 4 intregi cu valoarea 100
  list<int> L3 (L2.begin(),L2.end());          // iterare de la L2 de la inceput la final
  list<int> L4 (L3);                           // o cpie a L3


  L1.push_back(12);
  L1.push_back(21);
  cout << "Continutul L1 este ";
  for (list<int>::iterator it = L1.begin(); it != L1.end(); it++)
    cout << *it << ' ';

  cout << '\n';
  /* TODO
  - adaugati 2 elemente noi in lista L1, in fata
  - afisati continutul L1
  - ce observati
  */

  L1.pop_back();
  /* TODO
   -  afisati continutul listei L1
   -  ce observati
  */

  /* TODO
 - afisati lista L2
 - interclasati elementele listelor  L2 cu L3, L4
 - afisati lista L2
 */
  // generare dintr-un vector de valori
  int vInt[] = {16,2,77,29};
  list<int> L5 (vInt, vInt + sizeof(vInt) / sizeof(int) );

  cout << "Continutul L5 este ";
  for (list<int>::iterator it = L5.begin(); it != L5.end(); it++)
    cout << *it << ' ';

  cout << '\n';

  return 0;
}