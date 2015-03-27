//
//  venta.cpp
//  Problema2
//
//  Created by Alejandro Herce on 19/02/15.
//  Copyright (c) 2015 Alejandro Herce. All rights reserved.
//

#include "venta.h"

Venta::Venta()
{
    
}
Venta::Venta(int m, Vehiculo v, Cliente c)
{
    monto = m;
    coche = v;
    client = c;
    
}

bool Venta::comparaMonto(int value) const
{
    return monto == value;
}

bool Venta::comparaClienteApellido(string value) const
{
    return client.comparaApellido(value);
}

bool Venta::comparaClienteNombre(string value) const
{
    return client.comparaNombre(value);
}


std::ostream & operator <<(std::ostream & os, Venta & v)
{
    os << "Monto: " << v.monto << endl << endl << "Cliente: " << endl << v.client << endl << "Vehiculo: " << endl << v.coche << endl;
    return os;
}