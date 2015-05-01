//
//  Contenedor.h
//  Ejercicio1
//
//  Created by Alejandro Herce on 30/04/15.
//  Copyright (c) 2015 Alejandro Herce. All rights reserved.
//

#ifndef Ejercicio1_Contenedor_h
#define Ejercicio1_Contenedor_h

#include <map>
#include <list>
#include <iostream>
#include "Productos.h"
using namespace std;

class Contenedor {
    
private:
    map<std::string,list<Productos>> contenedor;
    
public:
    Contenedor() {}
    
    void crearContenedor(string, Productos);
    float totalContenedor(string, Productos);
    void printContenedor(string, Productos);
    string getKey();
    
    friend ostream & operator <<(ostream &, Contenedor &);
    
};

void Contenedor::crearContenedor(string _key, Productos value)
{
    contenedor[_key].push_back(value);
}

float Contenedor::totalContenedor(string key, Productos producto)
{
    float total = 0.0;
    for(list<Productos>::iterator i = contenedor[key].begin(); i != contenedor[key].end(); ++i)
    {
        total += i->getTotalProductos();
    }
    return total;
}

void Contenedor::printContenedor(string key, Productos producto)
{
    float total = 0.0;
    cout << "------------------------------------" << endl;
    cout << "CONTENEDOR: " + key << endl;
    cout << "------------------------------------" << endl;
    for(list<Productos>::iterator i = contenedor[key].begin(); i != contenedor[key].end(); ++i)
    {
        cout << "Nombre: " << i->getNombre() << endl;
        cout << "Cantidad: " << i->getCantidad() << endl;
        cout << "Precio unidad: " << i->getPrecio() << endl;
        cout << "Precio total: " << i->getTotalProductos() << endl << endl;
        total += i->getTotalProductos();
    }
    cout << "------------------------------------" << endl;
    cout << "TOTAL CONTENEDOR: $" << total << endl;
    
}

string Contenedor::getKey()
{
    for(auto imap: contenedor)
       return imap.first;
    return "Walmart01";
}

#endif
