//
//  cliente.cpp
//  Problema2
//
//  Created by Alejandro Herce on 19/02/15.
//  Copyright (c) 2015 Alejandro Herce. All rights reserved.
//

#include "cliente.h"

Cliente::Cliente():Cliente("", "", "")
{
    
}
Cliente::Cliente(string n, string a, string i)
{
    nombre = n;
    apellido = a;
    ife = i;
    
    
}

bool Cliente::comparaApellido(string value) const
{
    return apellido == value;
}

bool Cliente::comparaNombre(string value) const
{
    return nombre == value;
}


std::ostream & operator <<(std::ostream & os, Cliente & v)
{
    os << "Nombre: " << v.nombre << ", Apellido: " << v.apellido << ", IFE: " << v.ife << std::endl;
    
    return os;
}