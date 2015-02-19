//
//  vehiculo.h
//  Problema2
//
//  Created by Alejandro Herce on 19/02/15.
//  Copyright (c) 2015 Alejandro Herce. All rights reserved.
//

#ifndef Problema2_vehiculo_h
#define Problema2_vehiculo_h

#include <iostream>
using namespace std;


class Vehiculo {
private:
    string tipo;
    string marca;
    string codigo;
    int anio;
    int kilometraje;
    string extra;
    
public:
    Vehiculo();
    Vehiculo(std::string, std::string, std::string, int, int, std::string);
    friend std::ostream & operator <<(std::ostream &, Vehiculo &);
    
};


#endif
