//
//  Productos.h
//  Ejercicio1
//
//  Created by Alejandro Herce on 30/04/15.
//  Copyright (c) 2015 Alejandro Herce. All rights reserved.
//

#ifndef Ejercicio1_Productos_h
#define Ejercicio1_Productos_h

#include <iostream>
using namespace std;

class Productos {
    
private:
    string nombre;
    int cantidad;
    float precio;
    
public:
    Productos() : Productos(" ", 0, 0) {}
    Productos(string _nombre, int _cantidad, int _precio) : nombre(_nombre), cantidad(_cantidad), precio(_precio) {}
    
    
    float getTotalProductos();
    
    friend ostream & operator << (ostream & os, const Productos & p);
    friend ostream & operator << (ostream & os, list<Productos> & lst);
    
    string getNombre();
    int getCantidad();
    float getPrecio();
    
};


float Productos::getTotalProductos()
{
    return precio * cantidad;
}

string Productos::getNombre()
{
    return nombre;
}

int Productos::getCantidad()
{
    return cantidad;
}

float Productos::getPrecio()
{
    return precio;
}

std::ostream & operator << (std::ostream & os, const Productos & producto)
{
    os << "Nombre: " << producto.nombre << std::endl;
    os << "Cantidad: " << producto.cantidad << std::endl;
    os << "Precio: " << producto.precio << std::endl;
    return os;
}

#endif
