//
//  main.cpp
//  recursividadSumaArray
//
//  Created by Alejandro Herce on 19/01/15.
//  Copyright (c) 2015 Alejandro Herce. All rights reserved.
//

#include <iostream>
using namespace std;

int sumaArray (int * arreglo, int n);

int main(int argc, const char * argv[]) {
    
    int array[5] = {15,3,6,2,9};
    // Resultado = 35
    
    cout << "La suma del arreglo es: " << sumaArray(array, 4) << endl;
    
    return 0;
}

int sumaArray(int * arreglo, int n)
{
    if(n == 0)
    {
        return arreglo[0];
    } else {
        return arreglo[n] = arreglo[n] + sumaArray(arreglo, n - 1);
    }
}
