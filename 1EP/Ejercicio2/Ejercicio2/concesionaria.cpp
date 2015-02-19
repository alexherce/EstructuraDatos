//
//  concesionaria.cpp
//  Problema2
//
//  Created by Alejandro Herce on 19/02/15.
//  Copyright (c) 2015 Alejandro Herce. All rights reserved.
//

#include "concesionaria.h"

Concesionaria::Concesionaria()
{
    
}

Concesionaria::~Concesionaria()
{
    concesionaria.clear();
}

void Concesionaria::adicionarVenta(std::string key, Venta value)
{
    concesionaria[key] = value;
}


void Concesionaria::buscarCompradorApellido(std::string value)
{
    for (auto a : concesionaria) {
        if (a.second.comparaClienteApellido(value)) {
            std::cout << a.first << " ---> " << a.second;
        }
    }
}

void Concesionaria::buscarCompradorNombre(std::string value)
{
    for (auto a : concesionaria) {
        if (a.second.comparaClienteNombre(value)) {
            std::cout << a.first << " ---> " << a.second;
        }
    }
}

void Concesionaria::buscarMonto(int value)
{
    for (auto a : concesionaria) {
        if (a.second.comparaMonto(value)) {
            std::cout << a.first << " ---> " << a.second;
        }
    }
}

//void Concesionaria::ordena()
//{
//    std::vector<Venta> autos;
//
//    for (auto a : concesionaria) {
//        autos.push_back(a.second);
//    }
//
//    std::sort(autos.begin(), autos.end(), std::greater<Venta>());
//
//    for (auto a: autos) {
//        std::cout << a;
//    }
//
//}

std::ostream & operator <<(std::ostream & os, Concesionaria & c)
{
    for (auto a : c.concesionaria) {
        os << a.first << " ---> " << a.second;
    }
    
    return os;
}