//
//  main.cpp
//  Ejercicio2
//
//  Created by Alejandro Herce on 12/02/15.
//  Copyright (c) 2015 Alejandro Herce. All rights reserved.
//

#include <iostream>
#include "ordenamiento.h"
#include <cstdlib>
#include <ctime>
using namespace std;

static const char alphanum[] =
"0123456789"
"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
"abcdefghijklmnopqrstuvwxyz";

int stringLength = sizeof(alphanum) - 1;

char genRandom()
{
    
    return alphanum[rand() % stringLength];
}


int main(int argc, const char * argv[]) {
    
    string arreglo[1000];
    srand(time(0));
    for(int i = 0; i < 1000; i++)
    {
        string tmp;
        for (int j = 0; j < 5; j++)
        {
            tmp += genRandom();
        }
        arreglo[i] = tmp;
    }
    
    int opcion;
        cout << "Ingrese la opcion deseada:" << endl;
        cout << " 1.- Ordenar por burbuja ascendente" << endl;
        cout << " 2.- Ordenar por burbuja descendente" << endl;
        cout << " 3.- Ordenar por insercion ascendente" << endl;
        cout << " 4.- Ordenar por insercion descendente" << endl;
        cout << " 5.- Ordenar por seleccion ascendente" << endl;
        cout << " 6.- Ordenar por seleccion descendente" << endl;
        cin >> opcion;
        
        switch (opcion) {
            case 1:
            {
                Ordenamiento<string>::burbuja(arreglo, 1000, Ordenamiento<string>::asc);
                break;
            }
                
            case 2:
            {
                Ordenamiento<string>::burbuja(arreglo, 1000, Ordenamiento<string>::desc);
                break;
            }
                
            case 3:
            {
                Ordenamiento<string>::insercion(arreglo, 1000, Ordenamiento<string>::asc);
                break;
            }
            case 4:
            {
                Ordenamiento<string>::insercion(arreglo, 1000, Ordenamiento<string>::desc);
                break;
            }
            case 5:
            {
                Ordenamiento<string>::seleccion(arreglo, 1000, Ordenamiento<string>::asc);
                break;
            }
            case 6:
            {
                Ordenamiento<string>::seleccion(arreglo, 1000, Ordenamiento<string>::desc);
                break;
            }
            default:
            {
                cout << "Ingrese una opcion valida" << endl;
                break;
            }
        }
    
    for ( int i = 0; i < 1000; i++)
    {
        cout << arreglo[i] << endl;
    }
    
    return 0;
}
