#include <iostream>
#include <math.h>
#include "LinkedList.h"
#include "Node.h"
using namespace std;

bool IsPrime(const unsigned int x)
{
  const unsigned int TOP
  = static_cast<int>(
      sqrt( static_cast<double>( x ) )
    ) + 1;

  for ( int i=2; i != TOP; ++i )
  {
    if (x % i == 0) return false;
  }
  return true;
}

int main()
{
    using namespace vcn;
    LinkedList<int> * primos  = new LinkedList<int>();
    int p, q, n;
    int nTemp = 0;

    cout << "Ingrese desde que numero desea buscar primos: " << endl;
    cin >> p;
    cout << "Ingrese hasta que numero desea buscar primos: " << endl;
    cin >> q;
    cout << "Cuantos numeros primos desea buscar?: " << endl;
    cin >> n;


    for(int i = p; i < q; i++)
    {
        if(nTemp >  n - 1)
        {
            break;
        } else if (i > 1)
        {
            if(IsPrime(i) == true)
            {
                primos->insertBack(i);
                nTemp++;
            }
        }
    }

    int temp = primos->size();

    for(int i = 0; i < temp; i++)
    {
        cout << primos->removeBack()->getInfo() << endl;
    }






    return 0;
}
