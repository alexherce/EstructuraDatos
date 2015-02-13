//
//  Libro.h
//  Ejercicio3
//
//  Created by Alejandro Herce on 12/02/15.
//  Copyright (c) 2015 Alejandro Herce. All rights reserved.
//

#ifndef __ordenamientoGenerico__Libro__
#define __ordenamientoGenerico__Libro__

#include <iostream>
using namespace std;

class Libro {
public:
    std::string titulo;
    std::string autor;
    int paginas;
    int apublicacion;
    
    
    Libro()
    {
        titulo = "Sin definir";
        autor = "Sin definir";
        paginas = 0;
        apublicacion = 0;
    }
    
    Libro(std::string _titulo, std::string _autor, int _paginas, int _apublicacion)
    :titulo(_titulo), autor(_autor), paginas(_paginas), apublicacion(_apublicacion)
    {
        
    }
    
    /* Otras funciones */
    
    friend std::ostream & operator <<(std::ostream &, Libro &);
    bool operator >(Libro & libro);
    bool operator <(Libro & libro);
};

#endif /* defined(__ordenamientoGenerico__Libro__) */

