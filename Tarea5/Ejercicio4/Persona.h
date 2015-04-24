#ifndef PERSONA_H_INCLUDED
#define PERSONA_H_INCLUDED
#include <iostream>

using namespace std;

namespace ahb {

    class Persona {

private:
    string nombre;
    string fechaDefuncion;
    bool vivo;

public:

   Persona() : Persona(" ", true, " ") { }

   Persona(string _nombre, bool _vivo, string _fechaDefuncion) : nombre(_nombre), vivo(_vivo), fechaDefuncion(_fechaDefuncion) {}

    friend ostream & operator <<(ostream & os, const Persona &);

    void setFechaDefuncion(string);
    void setEstado(bool);

    string getNombre();
    string getFechaDefuncion();
    bool getEstado();

    };

void Persona::setFechaDefuncion(string fecha)
{
    fechaDefuncion = fecha;
}

void Persona::setEstado(bool estado)
{
    vivo = estado;
}

string Persona::getNombre()
{
    return nombre;
}

string Persona::getFechaDefuncion()
{
    return fechaDefuncion;
}

bool Persona::getEstado()
{
    return vivo;
}

ostream & operator <<(ostream & os, const Persona & c)
    {
        os << "Nombre: " << c.nombre << " | Vivo: " << (c.vivo? "Si" : "No") << " | Defuncion: " << c.fechaDefuncion << endl;

        return os;
    }

}
#endif // PERSONA_H_INCLUDED
