//
//  Trabajador.h
//  ProyectoFinal
//
//  Created by Alejandro Herce on 24/11/14.
//  Copyright (c) 2014 Alejandro Herce. All rights reserved.
//

#ifndef ProyectoFinal_Trabajador_h
#define ProyectoFinal_Trabajador_h

#include <sstream>

class Trabajador{
    
private:
    
    int numeroTrabajador;
    std::string nombreTrabajador;
    std::string contrasenaTrabajador;
    
public:
    
    Trabajador();
    Trabajador(int, std::string, std::string);
    
    void setNumeroTrabajador(int);
    void setNombreTrabajador(std::string);
    void setContrasenaTrabajador(std::string);
    
    int getNumeroTrabajador();
    std::string getNombreTrabajador();
    std::string getContrasenaTrabajador();
    
    friend std::ostream & operator << (std::ostream &, Trabajador &);
    bool operator == (const Trabajador & ) const;
    
};

Trabajador::Trabajador(){
    
    numeroTrabajador = -1;
    nombreTrabajador = "####";
    contrasenaTrabajador = "####";
    
}

Trabajador::Trabajador(int _numeroTrabajador, std::string _nombreTrabajador, std::string _contrasenaTrabajador){
    
    numeroTrabajador = _numeroTrabajador;
    nombreTrabajador = _nombreTrabajador;
    contrasenaTrabajador = _contrasenaTrabajador;
    
}

void Trabajador::setNumeroTrabajador(int _numeroTrabajador){
    
    numeroTrabajador = _numeroTrabajador;
    
}

void Trabajador::setNombreTrabajador(std::string _nombreTrabajador){
    
    nombreTrabajador = _nombreTrabajador;
    
}

void Trabajador::setContrasenaTrabajador(std::string _contrasenaTrabajador){
    
    contrasenaTrabajador = _contrasenaTrabajador;
    
}

int Trabajador::getNumeroTrabajador(){
    
    return numeroTrabajador;
    
}

std::string Trabajador::getNombreTrabajador(){
    
    return nombreTrabajador;
    
}

std::string Trabajador::getContrasenaTrabajador(){
    
    return contrasenaTrabajador;
    
}

std::ostream & operator << (std::ostream & os, Trabajador & trabajador){
    
    os << trabajador.numeroTrabajador << " " << trabajador.nombreTrabajador << " " << trabajador.contrasenaTrabajador;
    
    return os;
    
}

bool Trabajador :: operator == (const Trabajador & trabajador) const{
    
    return trabajador.numeroTrabajador == numeroTrabajador && trabajador.nombreTrabajador == nombreTrabajador && trabajador.contrasenaTrabajador == contrasenaTrabajador;
    
}

#endif
