#include "Persona.h"

namespace vcn {

ostream & operator <<(ostream & os, vcn::Persona & c)
{
    os << "Nombre: " << c.nombre <<  endl;
    os << "Apellido: " << c.apellido << endl;
    os << "Edad: " << c.edad << endl;
    os << "Fecha Nacimiento: " << c.fechaNacimiento << endl;

    return os;
}

}
