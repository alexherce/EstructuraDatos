//
//  venta.h
//  Problema2
//
//  Created by Alejandro Herce on 19/02/15.
//  Copyright (c) 2015 Alejandro Herce. All rights reserved.
//

#ifndef __Problema2__venta__
#define __Problema2__venta__

#include <iostream>
#include "vehiculo.h"
#include "cliente.h"
using namespace std;


class Venta {
private:
    int monto;
    Vehiculo coche;
    Cliente client;
    
public:
    Venta();
    Venta(int, Vehiculo, Cliente);
    bool comparaMonto(int) const;
    bool comparaClienteApellido(std::string) const;
    bool comparaClienteNombre(std::string) const;
    friend std::ostream & operator <<(std::ostream &, Venta &);
    
};


#endif /* defined(__Problema2__venta__) */
