//
//  cliente.h
//  Problema2
//
//  Created by Alejandro Herce on 19/02/15.
//  Copyright (c) 2015 Alejandro Herce. All rights reserved.
//

#ifndef __Problema2__cliente__
#define __Problema2__cliente__


#include <iostream>
using namespace std;


class Cliente {
private:
    string nombre;
    string apellido;
    string ife;
    
public:
    Cliente();
    Cliente(std::string, std::string, std::string);
    bool comparaApellido(std::string) const;
    bool comparaNombre(std::string) const;
    
    friend std::ostream & operator <<(std::ostream &, Cliente &);
    
};


#endif /* defined(__Problema2__cliente__) */
