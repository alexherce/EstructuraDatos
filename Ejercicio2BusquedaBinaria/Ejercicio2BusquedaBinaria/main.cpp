//
//  main.cpp
//  Ejercicio2BusquedaBinaria
//
//  Created by Alejandro Herce on 26/01/15.
//  Copyright (c) 2015 Alejandro Herce. All rights reserved.
//


#include <iostream>
#include <time.h>

#define N 5


template <typename T>
bool busquedaBinariaPos(T a[], T buscar, int inicio, int fin);

template <typename T>
void imprimeVector(T a[]);

int main(int argc, const char * argv[])
{
    int numeros[N][N] = {0};
    
    // srand((int)time(NULL));
    
    /* Inicializar con números ordenados */
    for (int i= 0; i < N; ++i) {
        for (int j = 0; j < N; j++)
        {
        numeros[i][j] = rand() % 1000;
        }
    }
    
    imprimeVector(numeros);
    
    int elementoABuscar;
    
    std::cout << "Entre el número a buscar: ";
    std::cin >> elementoABuscar;
    
    bool existe = busquedaBinariaPos(numeros, elementoABuscar, 0, N);
    
    if (existe) {
        std::cout << "El número " << elementoABuscar << " si existe en el vector";
    }
    else {
        std::cout << "El número " << elementoABuscar << " no existe en el vector";
    }
    
    std::cout << std::endl;
    
    
    return 0;
}

template <typename T>
bool busquedaBinariaPos(T a[], T buscar, int inicio, int fin)
{
    
    if (inicio > fin)
    {
        return -1;
    }
    else {
        int mitad = (inicio + fin) / 2;
        
        if (a[mitad] == buscar)
        {
            return mitad;
        }
        else if (buscar < a[mitad] )
        {
            return busquedaBinaria(a, buscar, inicio, mitad-1);
        }
        else {
            return busquedaBinaria(a, buscar, mitad+1, fin);
        }
    }
    
    return false;
}

template <typename T>
void imprimeVector(T a[])
{
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; j++)
        {
        std::cout << a[i][j] << " ";
        }
        std::cout << std::endl;
    }
    
    std::cout << std::endl;
}
