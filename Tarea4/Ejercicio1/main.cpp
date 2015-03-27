//
//  main.cpp
//  Ejercicio1
//
//  Created by Alejandro Herce on 20/10/14.
//  Copyright (c) 2014 Alejandro Herce. All rights reserved.
//

#include <iostream>
#include "Pila.h"
using namespace std;

int main(int argc, const char * argv[]) {
    
    string operation;
    unsigned size;
    char temp;
    int contAbre = 0;
    int contCierra = 0;
    int notBalanced = 0;
    char tempAnalisis;
    
    Pila<char> * pila = new Pila<char>();
    
    cout << "Ingrese la operacion a analizar: " << endl;
    cin >> operation;
    
    size = operation.length();
    
    for (int i = 0; i < size; i++)
    {
        temp = operation[i];
        pila->push(temp);
    }
    
    
    while(!pila->empty())
    {
        tempAnalisis = pila->pop()->getInfo();
        
        if(tempAnalisis == '(' && contCierra == 0)
           {
               cout << "MATH ERROR" << endl;
               notBalanced++;
               break;
           } else {
               
               if( tempAnalisis == '(')
               {
                   contAbre++;
               }
               if (tempAnalisis == ')')
               {
                   contCierra++;
               }
               
           }
        
    }
    
    if(contAbre == contCierra && notBalanced == 0)
    {
        cout << "LA OPERACION ESTA BALANCEADA" << endl;
    } else {
        cout << "LA OPERACION NO ESTA BALANCEADA" << endl;
    }
    
    
    
    return 0;
}
