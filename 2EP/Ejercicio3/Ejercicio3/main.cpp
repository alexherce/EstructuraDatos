//
//  main.cpp
//  Ejercicio3
//
//  Created by Alejandro Herce on 09/04/15.
//  Copyright (c) 2015 Alejandro Herce. All rights reserved.
//

#include <iostream>
#include <string>
#include "LinkedList.h"
using namespace vcn;
using namespace std;

LinkedList<char> lista;
LinkedList<int> cola1;
LinkedList<int> cola2;
LinkedList<int> sol;

void funcionUnion();
void funcionNmenosM();
void funcionMmenosN();
void funcionMultiplicacion();
void funcionInterseccion();


int main(int argc, const char * argv[]) {
    
    
    string expression = "{1,2,3,4,5}*{5,6,7,8,9}";
    
    char chr, chr2;
    
    for(int i = 0; i < expression.size(); ++i)
    {
        chr = expression[i];
        chr2 = ',';
        if(expression[i] != chr2)
        {
            lista.insertBack(expression[i]);
        }
    }
    
    
    cout << lista << endl << endl;
    
    int posInicio1 = 0;
    int posFinal1 = 0;
    
    int posInicio2 = 0;
    int posFinal2 = 0;
    
    int operacion = 1;
    
    for (int i = 0; i < lista.size(); i++)
    {
        
        if(operacion == 1)
        {
            if (lista.at(i)->getInfo() == '{')
            {
                posInicio1 = i + 1;
            }
            
            if (lista.at(i)->getInfo() == '}')
            {
                posFinal1 = i - 1;
                operacion++;
            }
        }
        
        if(operacion == 2)
        {
            if (lista.at(i)->getInfo() == '{')
            {
                posInicio2 = i + 1;
            }
            
            if (lista.at(i)->getInfo() == '}')
            {
                posFinal2 = i - 1;
                operacion++;
            }
        }
    }

    int temp;
    for (int i = posInicio1; i < posFinal1 + 1; i++)
    {
        temp =  lista.at(i)->getInfo() - '0';
        cola1.insertBack(temp);
    }
    
    for (int i = posInicio2; i < posFinal2 + 1; i++)
    {
        temp =  lista.at(i)->getInfo() - '0';
        cola2.insertBack(temp);
    }
    
    
    funcionInterseccion();
    
    
    cout << cola1 << endl;
    cout << cola2 << endl;
    
    cout << sol << endl;
    
    
    lista.clear();
    
    
    return 0;
}

void funcionInterseccion()
{
    for (int i = 0; i < cola1.size(); ++i)
    {
        for (int j = 0; j < cola2.size(); ++j)
        {
            if (cola1.at(i)->getInfo() == cola2.at(j)->getInfo())
            {
                sol.insertBack(cola1.at(i)->getInfo());
            }
        }
    }
}


