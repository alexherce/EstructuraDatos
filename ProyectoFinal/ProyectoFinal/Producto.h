//
//  Producto.h
//  ProyectoFinal
//
//  Created by Alejandro Herce on 24/11/14.
//  Copyright (c) 2014 Alejandro Herce. All rights reserved.
//

#ifndef ProyectoFinal_Producto_h
#define ProyectoFinal_Producto_h


#include <sstream>

class Producto{
    
private:
    
    int numeroProducto;
    int cantidadProducto;
    double precioProducto;
    std::string nombreProducto;
    std::string categoriaProducto;
    
public:
    
    Producto();
    Producto(int, std::string, std::string, int, double);
    
    void setNumeroProducto(int);
    void setCantidadProducto(int);
    void setPrecioProducto(double);
    void setNombreProducto(std::string);
    void setCategoriaProducto(std::string);
    
    int getNumeroProducto();
    int getCantidadProducto();
    double getPrecioProducto();
    std::string getNombreProducto();
    std::string getCategoriaProducto();
    
    friend std::ostream & operator << (std::ostream &, Producto &);
    bool  operator == (const Producto & ) const;
    
};

Producto::Producto(){
    
    numeroProducto = -1;
    nombreProducto = "####";
    categoriaProducto = "####";
    cantidadProducto = 0;
    precioProducto = 0.0;
    
}

Producto::Producto(int _numeroProducto, std::string _nombreProducto, std::string _categoriaProducto, int _cantidadProducto, double _precioProducto){
    
    numeroProducto = _numeroProducto;
    nombreProducto = _nombreProducto;
    categoriaProducto = _categoriaProducto;
    cantidadProducto = _cantidadProducto;
    precioProducto = _precioProducto;
    
}

void Producto::setNumeroProducto(int _numeroProducto){
    
    numeroProducto = _numeroProducto;
    
}

void Producto::setCantidadProducto(int _cantidadProducto){
    
    cantidadProducto = _cantidadProducto;
    
}

void Producto::setPrecioProducto(double _precioProducto){
    
    precioProducto = _precioProducto;
    
}

void Producto::setNombreProducto(std::string _nombreProducto){
    
    nombreProducto = _nombreProducto;
    
}

void Producto::setCategoriaProducto(std::string _categoriaProducto){
    
    categoriaProducto = _categoriaProducto;
    
}

int Producto::getNumeroProducto(){
    
    return numeroProducto;
    
}

int Producto::getCantidadProducto(){
    
    return cantidadProducto;
    
}

double Producto::getPrecioProducto(){
    
    return precioProducto;
    
}

std::string Producto::getNombreProducto(){
    
    return nombreProducto;
    
}

std::string Producto::getCategoriaProducto(){
    
    return categoriaProducto;
    
}

std::ostream & operator << (std::ostream & os, Producto & producto){
    
    os << producto.numeroProducto << " " << producto.nombreProducto << " " << producto.categoriaProducto << " " << producto.cantidadProducto << " " << producto.precioProducto;
    
    return os;
    
}

bool Producto :: operator == (const Producto & producto) const{
    
    return producto.numeroProducto == numeroProducto && producto.nombreProducto == nombreProducto && producto.categoriaProducto == categoriaProducto && producto.cantidadProducto == cantidadProducto && producto.precioProducto == precioProducto;
    
}

#endif
