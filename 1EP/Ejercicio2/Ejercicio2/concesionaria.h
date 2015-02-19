//
//  concesionaria.h
//  Problema2
//
//  Created by Alejandro Herce on 19/02/15.
//  Copyright (c) 2015 Alejandro Herce. All rights reserved.
//

#ifndef __Problema2__concesionaria__
#define __Problema2__concesionaria__

#include <iostream>
#include <map>
#include <algorithm>
#include <ostream>
#include <vector>
#include "venta.h"

class Concesionaria {
private:
    std::map<std::string, Venta> concesionaria;
    
public:
    Concesionaria();
    ~Concesionaria();
    
    void adicionarVenta(std::string, Venta);
    
    void buscarCompradorApellido(std::string);
    void buscarCompradorNombre(std::string);
    void buscarMonto(int);
    void ordena();
    
    friend std::ostream & operator <<(std::ostream &, Concesionaria &);
};

#endif /* defined(__Problema2__concesionaria__) */
