//
//  Libro.cpp
//  Ejercicio3
//
//  Created by Alejandro Herce on 12/02/15.
//  Copyright (c) 2015 Alejandro Herce. All rights reserved.
//

#include "Libro.h"

std::ostream & operator <<(std::ostream & os, Libro & libro)
{
    os << libro.titulo << std::endl;
    
    return os;
}

bool Libro::operator >(Libro & libro)
{
    return titulo > libro.titulo;
}

bool Libro::operator <(Libro & libro)
{
    return titulo < libro.titulo;
}
