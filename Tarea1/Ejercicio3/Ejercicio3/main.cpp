//
//  main.cpp
//  Ejercicio3
//
//  Created by Alejandro Herce on 29/01/15.
//  Copyright (c) 2015 Alejandro Herce. All rights reserved.
//

#include <iostream>
using namespace std;


int robot(int x, int y, int m, int n);

int main(int argc, const char * argv[]) {
    
    int m, n;
    cout << "Ingrese X: " << endl;
    cin >> m;
    
    
    cout << "Ingrese Y: " << endl;
    cin >> n;
    
    cout << "El robot puede recorrer " << robot(0, 0, m, n) << " caminos." << endl;
    
    
    return 0;
}


int robot(int x, int y, int m, int n)
{
    int cont = 0;
    if((x != m - 1) && (y != n - 1))
    {
        if (x < m - 3)
        {
            cont += robot(x + 3, y, m, n);
        }
        if (y < n - 2)
        {
            cont += robot(x, y + 2, m, n);
        }
        return cont;
    } else {
        return 1;
    }
    return cont;
}