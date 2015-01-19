//
//  main.cpp
//  Ejercicio1
//
//  Created by Alejandro Herce on 08/10/14.
//  Copyright (c) 2014 Alejandro Herce. All rights reserved.
//

#include <iostream>
#include <string>
#include "ListaEnlazada.h"

int main(int argc, const char * argv[]) {
    
    
    /* Crear la lista */
    ListaEnlazada<int> * numerosEnteros = new ListaEnlazada<int>();
    
    int randomNum = 0;
    
    /* Insertar valores */
    for(int i = 0; i < 100; i++)
    {
        
        randomNum = rand() % 1000;
        
        numerosEnteros->insertBack(randomNum);
        
    }
    
    
    for(int i = 100; i >= 0; i--)
    {
        Nodo<int> * index = numerosEnteros->At(i);
        
        if (index) {
            std::cout << "Lista[" << i << "] = " << *index << std::endl;
        }
        
    }
    
    
    /* Eliminar todos los nodos */
    numerosEnteros->clear();
    
    std::cout << "Se limpió la lista ..." << std::endl;
    
    std::cout << "Tamaño = " << numerosEnteros->size() << std::endl;
    
    std::cout << *numerosEnteros << std::endl;
    
    /* Borrar la lista de memoria y todos sus nodos */
    
    delete numerosEnteros;
    
    return 0;
}
