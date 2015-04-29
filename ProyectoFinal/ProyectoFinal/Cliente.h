//
//  Cliente.h
//  ProyectoFinal
//
//  Created by Alejandro Herce on 24/11/14.
//  Copyright (c) 2014 Alejandro Herce. All rights reserved.
//

#ifndef ProyectoFinal_Cliente_h
#define ProyectoFinal_Cliente_h

#include <sstream>

class Cliente{
    
private:
    
    int	numeroCliente;
    int numeroCompras;
    double montoTotalGastado;
    std::string nombreCliente;
    
public:
    
    Cliente();
    Cliente(int, std::string, int, double);
    
    void setNumeroCliente(int);
    void setNumeroCompras(int);
    void setMontoTotalGastado(double);
    void setNombreCliente(std::string);
    
    int getNumeroCliente();
    int getNumeroCompras();
    double getMontoTotalGastado();
    std::string getNombreCliente();
    
    friend std::ostream & operator << (std::ostream &, Cliente &);
    bool operator == (const Cliente & ) const;
    
};

Cliente::Cliente(){
    
    numeroCliente = -1;
    nombreCliente = "####";
    numeroCompras = 0;
    montoTotalGastado = 0.0;
    
}

Cliente::Cliente(int _numeroCliente, std::string _nombreCliente, int _numeroCompras, double _montoTotalGastado){
    
    numeroCliente = _numeroCliente;
    nombreCliente = _nombreCliente;
    numeroCompras = _numeroCompras;
    montoTotalGastado = _montoTotalGastado;
    
}

void Cliente::setNumeroCliente(int _numeroCliente){
    
    numeroCliente = _numeroCliente;
    
}

void Cliente::setNumeroCompras(int _numeroCompras){
    
    numeroCompras = _numeroCompras;
    
}

void Cliente::setMontoTotalGastado(double _montoTotalGastado){
    
    montoTotalGastado = _montoTotalGastado;
    
}

void Cliente::setNombreCliente(std::string _nombreCliente){
    
    nombreCliente = _nombreCliente;
    
}

int Cliente::getNumeroCliente(){
    
    return numeroCliente;
    
}

int Cliente::getNumeroCompras(){
    
    return numeroCompras;
    
}

double Cliente::getMontoTotalGastado(){
    
    return montoTotalGastado;
    
}

std::string Cliente::getNombreCliente(){
    
    return nombreCliente;
    
}

std::ostream & operator << (std::ostream & os, Cliente & cliente){
    
    os << cliente.numeroCliente << " " << cliente.nombreCliente << " " << cliente.numeroCompras << " " << cliente.montoTotalGastado;
    
    return os;
    
}

bool Cliente :: operator == (const Cliente & cliente) const{
    
    return cliente.numeroCliente == numeroCliente && cliente.nombreCliente == nombreCliente && cliente.numeroCompras == numeroCompras && cliente.montoTotalGastado == montoTotalGastado;
    
}

#endif
