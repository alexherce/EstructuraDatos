#ifndef PERSONA_H
#define PERSONA_H

#include "LinkedList.h"
#include <iostream>
using namespace std;

namespace vcn {

class Persona
{
private:
    string nombre;
    string apellido;
    int edad;
    string fechaNacimiento;

public:
    Persona(string _nombre, string _apellido, int _edad, string _fechaNacimiento):nombre(_nombre), apellido(_apellido), edad(_edad), fechaNacimiento(_fechaNacimiento)
    {

    }

    string getNombre()
    {
        return nombre;
    }
    string getApellido()
    {
        return apellido;
    }
    friend ostream & operator <<(ostream & os, Persona &);
};

}
#endif // PERSONA_H
