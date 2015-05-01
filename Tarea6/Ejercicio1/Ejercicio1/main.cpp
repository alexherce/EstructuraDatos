//
//  main.cpp
//  Ejercicio1
//
//  Created by Alejandro Herce on 30/04/15.
//  Copyright (c) 2015 Alejandro Herce. All rights reserved.
//

#include <iostream>
#include <stack>
#include <vector>
#include "Contenedor.h"

int const m = 5;
int const n = 5;

Productos producto;
Contenedor contenedor, getContenedor;
vector<stack<Contenedor>> puerto(m);

void insertarContenedor(string, string, int, float);
void insertarProducto(string, string, int, float);
void imprimirPuerto(Contenedor contenedor);

int main(int argc, const char * argv[]) {
   
    /* Crea e inserta el contenedor en el "puerto" (vector con stack) */
    /* Key del mapa, Item, Cantidad y Costo. */
    insertarContenedor("Walmart01", "Sabritas", 300, 8.99);
    
    /* Inserta productos a un contenedor existente o crea uno pero no lo inserta en el puerto */
    insertarProducto("Walmart01", "CocaCola", 400, 9.99);
    insertarProducto("Walmart01", "Frutsi", 600, 19.99);
    insertarProducto("Walmart01", "Oreo", 100, 12.99);
    
    /* Crea e inserta el contenedor en el "puerto" (vector con stack) */
    insertarContenedor("Apple01", "iPhone 6", 1000, 12999.99);
    
    /* Inserta productos a un contenedor existente o crea uno pero no lo inserta en el puerto */
    insertarProducto("Apple01", "MacBook", 1000, 25999.99);
    insertarProducto("Apple01", "Mac Pro", 500, 50599.99);
    insertarProducto("Apple01", "MacBook Pro", 2000, 35599.99);
    
    imprimirPuerto(contenedor);
    
    return 0;
}

void insertarContenedor(string key, string nombreProducto, int cantidadProducto, float precioProducto)
{
    bool insertado = false;
    contenedor.crearContenedor(key, Productos(nombreProducto, cantidadProducto, precioProducto));
    for(int i = 0; i < m; i++)
    {
        if(puerto[i].size() <= n)
        {
            puerto[i].push(contenedor);
            insertado = true;
            break;
        }
    }
    if(insertado == false)
    {
        cout << "Ya no hay espacio en el puerto." << endl;
    }
}

void insertarProducto(string key, string nombreProducto, int cantidadProducto, float precioProducto)
{
    contenedor.crearContenedor(key, Productos(nombreProducto, cantidadProducto, precioProducto));
}

void imprimirPuerto(Contenedor contenedor)
{
    float total = 0;
    float stack = 0;
    for(int i = 0; i < puerto.size(); i++)
    {
        cout << "------------------------------------" << endl;
        cout << "PILA " << i << ": " << endl;
        cout << "------------------------------------" << endl;
        
        while(!puerto[i].empty())
        {
            contenedor.printContenedor(puerto[i].top().getKey(), producto);
            stack += contenedor.totalContenedor(puerto[i].top().getKey(), producto);
            total += contenedor.totalContenedor(puerto[i].top().getKey(), producto);
            puerto[i].pop();
        }
        cout << "------------------------------------" << endl;
        cout << "TOTAL DE LA PILA: $" << stack << endl;
        cout << "------------------------------------" << endl << endl;
        stack = 0;
        
    }
    
    cout << "------------------------------------" << endl;
    cout << "TOTAL DEL PUERTO: $" << total << endl;
    cout << "------------------------------------" << endl;

}