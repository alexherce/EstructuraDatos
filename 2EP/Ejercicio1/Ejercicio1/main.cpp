//
//  main.cpp
//  Ejercicio1
//
//  Created by Alejandro Herce on 09/04/15.
//  Copyright (c) 2015 Alejandro Herce. All rights reserved.
//

#include "Stack.h"
#include <iostream>
using namespace std;
using namespace vcn;
Stack<int> cola;

string convertirBinario(int);

int main(int argc, const char * argv[]) {
    
    
    cout << convertirBinario(1000) << endl;
    
    
    return 0;
}

string convertirBinario(int numero){
    
    int num = numero;
    string convertido = "";
    
    while (num != 0)
    {
        cola.push(num%2);
        num = num/2;
    }
    
    
    // No hay alguna funcion similar a append pero para int???
    while (!cola.empty())
    {
        convertido.append(to_string(cola.pop()->getInfo()));
    }
    return convertido;
}
