//
//  vehiculo.cpp
//  Problema2
//
//  Created by Alejandro Herce on 19/02/15.
//  Copyright (c) 2015 Alejandro Herce. All rights reserved.
//

#include <stdio.h>
#include "vehiculo.h"

Vehiculo::Vehiculo():Vehiculo("", "", "", 0, 0, "")
{
    
}
Vehiculo::Vehiculo(string t, string m, string c, int a, int k, string e)
{
    tipo = t;
    marca = m;
    codigo = c;
    anio = a;
    kilometraje = k;
    extra = e;
}

std::ostream & operator <<(std::ostream & os, Vehiculo & v)
{
    os << "Tipo: " << v.tipo << ", Marca: " << v.marca << ", Codigo: " << v.codigo << ", Año: " << v.anio << ", Kilometraje: " << v.kilometraje << ", Extra: " << v.extra <<  std::endl;
    
    return os;
}