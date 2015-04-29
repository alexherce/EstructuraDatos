//
//  FuncionesProductos.h
//  ProyectoFinal
//
//  Created by Alejandro Herce on 24/11/14.
//  Copyright (c) 2014 Alejandro Herce. All rights reserved.
//

#ifndef ProyectoFinal_FuncionesProductos_h
#define ProyectoFinal_FuncionesProductos_h


#include "Producto.h"
#include <list>
#include <fstream>
#include <iostream>

//DefiniciÛn.

void almacenarInformacionProductosEnLista(std::list <Producto> *, std::string);
void agregarProductoEnLista(std::list <Producto> *, Producto);
void eliminarProductoEnLista(std::list <Producto> *, int);
void reasignarNumeroProductoEnLista(std::list <Producto> *);
void imprimirInformacionProductos(std::list <Producto> *);
void almacenarInformacionProductosEnArchivoTxt(std::list <Producto> *, std::string);

Producto ingresarInformacionProducto();

double obtenerPrecioProducto(std::list <Producto> *, int);
void actualizarPrecioProducto(std::list <Producto> *, int, double);
int obtenerCantidadProducto(std::list <Producto> *, int);
void actualizarCantidadProducto(std::list <Producto> *, int);
void actualizarCantidadProducto(std::list <Producto> *, int, int);

void cobrarProductos(std::list <Producto> *, std::list <Cliente> *);

Producto buscarProductoPorNumero(std::list <Producto> *, int);
Producto buscarProductoPorNombre(std::list <Producto> *, std::string);
std::list <Producto> buscarProductosPorCategoria(std::list <Producto> *, std::string);
std::list <Producto> buscarProductosAgotados(std::list <Producto> *);

//DefiniciÛn.


//Almacenar la informaciÛn de los productos que se encuentran en un archivo de texto, en una lista enlazada.
void almacenarInformacionProductosEnLista(std::list <Producto> * _listaProductos, std::string _nombreArchivo){
    
    std::string lineaDeTexto, concatenacionNombreProducto, concatenacionCategoriaProducto, concatenacionCantidadProducto, concatenacionPrecioProducto;
    int $concatenacionCantidadProducto;
    double $concatenacionPrecioProducto;
    std::ifstream archivoProductos("/Users/Herce/" + _nombreArchivo + ".txt");
    int numLineas = 0;
    
    while(getline(archivoProductos, lineaDeTexto)){
        
        int indiceNombre, indiceCategoria, indiceCantidad, indicePrecio;
        
        concatenacionNombreProducto = "";
        concatenacionCategoriaProducto = "";
        concatenacionCantidadProducto = "";
        concatenacionPrecioProducto = "";
        
        numLineas += 1;
        
        for(int i = 0; lineaDeTexto[i] != ' '; i++)
            indiceNombre = (i + 2);
        
        for(int i = indiceNombre; i < lineaDeTexto.length() && lineaDeTexto[i] != ' '; i++){
            
            concatenacionNombreProducto += lineaDeTexto[i];
            indiceCategoria = (i + 2);
            
        }
        
        for(int i = indiceCategoria; i < lineaDeTexto.length() && lineaDeTexto[i] != ' '; i++){
            
            concatenacionCategoriaProducto += lineaDeTexto[i];
            indiceCantidad = (i + 2);
            
        }
        
        for(int i = indiceCantidad; i < lineaDeTexto.length() && lineaDeTexto[i] != ' '; i++){
            
            concatenacionCantidadProducto += lineaDeTexto[i];
            indicePrecio = (i + 2);
            
        }
        
        for(int i = indicePrecio; i < lineaDeTexto.length(); i++)
            concatenacionPrecioProducto += lineaDeTexto[i];
        
        $concatenacionCantidadProducto = atoi(concatenacionCantidadProducto.c_str());
        $concatenacionPrecioProducto = atof(concatenacionPrecioProducto.c_str());
        
        Producto productoTemp = Producto(numLineas, concatenacionNombreProducto, concatenacionCategoriaProducto, $concatenacionCantidadProducto, $concatenacionPrecioProducto);
        
        if(concatenacionNombreProducto != "" && concatenacionCategoriaProducto != "" && concatenacionCantidadProducto != "" && concatenacionPrecioProducto != "")
            _listaProductos->push_back(productoTemp);
        
    }
				
    archivoProductos.close();
    
}
//Almacenar la informaciÛn de los productos que se encuentran en un archivo de texto, en una lista enlazada.


//Agregar un producto a la lista.
void agregarProductoEnLista(std::list <Producto> * _listaProductos, Producto _producto){
    
    _producto.setNumeroProducto(_listaProductos->size() + 1);
    _listaProductos->push_back(_producto);
    
}
//Agregar un producto a la lista.


//Eliminar un producto de la lista.
void eliminarProductoEnLista(std::list <Producto> * _listaProductos, int _numeroProducto){
    
    std::list <Producto> :: iterator it = _listaProductos->begin();
    
    for(int i = 1; i < _numeroProducto; ++i)
        ++it;
    
    _listaProductos->erase(it);
    
}
//Eliminar un producto de la lista.


//Reasignar n˙mero de producto a los productos de la lista.
void reasignarNumeroProductoEnLista(std::list <Producto> * _listaProductos){
    
    std::list <Producto> :: iterator it = _listaProductos->begin();
    
    for(int i = 0; i < _listaProductos->size(); ++i){
        
        it->setNumeroProducto(i + 1);
        
        ++it;
        
    }
}
//Reasignar n˙mero de producto a los productos de la lista.


//Imprimir la informaciÛn de todos los productos.
void imprimirInformacionProductos(std::list <Producto> * _listaProductos){
    
    for(std::list <Producto> :: iterator it = _listaProductos->begin(); it != _listaProductos->end(); ++it)
        std::cout << "\n\t\t" << *it;
    
}
//Imprimir la informaciÛn de todos los productos.


//Almacenar la informaciÛn de los productos en un archivo txt.
void almacenarInformacionProductosEnArchivoTxt(std::list <Producto> * _listaProductos, std::string _nombreArchivo){
    
    std::ofstream entradaProducto;
    
    entradaProducto.open("/Users/Herce/" + _nombreArchivo + ".txt", std::ios::out);
    
    for(std::list <Producto> :: iterator it = _listaProductos->begin(); it != _listaProductos->end(); ++it)
        entradaProducto << *it << std::endl;
    
    entradaProducto.close();
    
}
//Almacenar la informaciÛn de los productos en un archivo txt.


//Ingresar la informaciÛn de un producto.
Producto ingresarInformacionProducto(){
    
    std::string nombreProductoIngreso;
    std::string categoriaProductoIngreso;
    std::string cantidadProductoIngreso;
    std::string precioProductoIngreso;
    
    int $cantidadProductoIngreso;
    double $precioProductoIngreso;
    
    std::cout << "\n\t\tIngrese el nombre del producto: ";
    std::cin >> nombreProductoIngreso;
    
    std::cout << "\n\t\tIngrese la categoria del producto: ";
    std::cin >> categoriaProductoIngreso;
    
    std::cout << "\n\t\tIngrese la catidad del producto: ";
    std::cin >> cantidadProductoIngreso;
    $cantidadProductoIngreso = atoi(cantidadProductoIngreso.c_str());
    
    std::cout << "\n\t\tIngrese el precio del producto: ";
    std::cin >> precioProductoIngreso;
    $precioProductoIngreso = atof(precioProductoIngreso.c_str());
    
    return Producto(-1, nombreProductoIngreso, categoriaProductoIngreso, $cantidadProductoIngreso, $precioProductoIngreso);
    
}
//Ingresar la informaciÛn de un producto.


//Obtener el precio de un producto de acuerdo con su n˙mero.
double obtenerPrecioProducto(std::list <Producto> * _listaProductos, int _numeroProducto){
    
    std::list <Producto> :: iterator it = _listaProductos->begin();
    
    for(int i = 1; i < _numeroProducto; ++i, ++it);
    
    return it->getPrecioProducto();
    
}
//Obtener el precio de un producto de acuerdo con su n˙mero.


//Actualizar el precio de un producto de acuerdo con su n˙mero.
void actualizarPrecioProducto(std::list <Producto> * _listaProductos, int _numeroProducto, double _precioProducto){
    
    std::list <Producto> :: iterator it = _listaProductos->begin();
    
    for(int i = 1; i < _numeroProducto; ++i, ++it);
    
    return it->setPrecioProducto(_precioProducto);
    
}
//Actualizar el precio de un producto de acuerdo con su n˙mero.


//Obtener la cantidad de un producto de acuerdo con su n˙mero.
int obtenerCantidadProducto(std::list <Producto> * _listaProductos, int _numeroProducto){
    
    std::list <Producto> :: iterator it = _listaProductos->begin();
    
    for(int i = 1; i < _numeroProducto; ++i, ++it);
    
    return it->getCantidadProducto();
    
}
//Obtener la cantidad de un producto de acuerdo con su n˙mero.


//Actualizar la cantidad de un producto de acuerdo con su n˙mero.
void actualizarCantidadProducto(std::list <Producto> * _listaProductos, int _numeroProducto){
    
    std::list <Producto> :: iterator it = _listaProductos->begin();
    
    for(int i = 1; i < _numeroProducto; ++i, ++it);
    
    return it->setCantidadProducto(it->getCantidadProducto() - 1);
    
}
//Actualizar la cantidad de un producto de acuerdo con su n˙mero.


//Actualizar la cantidad de un producto de acuerdo con su n˙mero. ()
void actualizarCantidadProducto(std::list <Producto> * _listaProductos, int _numeroProducto, int _cantidadProducto){
    
    std::list <Producto> :: iterator it = _listaProductos->begin();
    
    for(int i = 1; i < _numeroProducto; ++i, ++it);
    
    return it->setCantidadProducto(_cantidadProducto);
    
}
//Actualizar la cantidad de un producto de acuerdo con su n˙mero. ()


//Cobrar una lista de productos.
void cobrarProductos(std::list <Producto> * _listaProductos, std::list <Cliente> * _listaClientes, int _numeroCliente){
    
    std::string numeroProductoIngreso;
    int $numeroProductoIngreso = 1;
    double montoTotal = 0.0;
    bool compraRealizada = false;
    
    while(numeroProductoIngreso != "t"){
        
        std::cout << "\n\tIngrese el numero del producto: ";
        std::cin >> numeroProductoIngreso;
        $numeroProductoIngreso = atoi(numeroProductoIngreso.c_str());
        
        if($numeroProductoIngreso > 0 && $numeroProductoIngreso <= _listaProductos->size()){
            
            if(obtenerCantidadProducto(_listaProductos, $numeroProductoIngreso) > 0){
                
                montoTotal += obtenerPrecioProducto(_listaProductos, $numeroProductoIngreso);
                actualizarCantidadProducto(_listaProductos, $numeroProductoIngreso);
                compraRealizada = true;
                
            }
            
            else
                std::cout << "\n\t\t\tProducto agotado\n";
            
        }
        
        else
            std::cout << "\n\t\t\tProducto invalido\n";
        
    }
    
    if(compraRealizada){
        
        actualizarNumeroCompras(_listaClientes, _numeroCliente);
        actualizarMontoTotalGastado(_listaClientes, _numeroCliente, montoTotal);
        
    }
    
    std::cout << "\n\t\tTotal = " << montoTotal << "\n";
    
}
//Cobrar una lista de productos.


//Buscar producto por su n˙mero.
Producto buscarProductoPorNumero(std::list <Producto> * _listaProductos, int _numeroProducto){
    
    std::list <Producto> :: iterator it = _listaProductos->begin();
    
    for(int i = 1; i < _numeroProducto; ++i, ++it);
    
    return *it;
    
}
//Buscar producto por su n˙mero.


//Buscar producto por su nombre.
Producto buscarProductoPorNombre(std::list <Producto> * _listaProductos, std::string _nombreProducto){
    
    std::list <Producto> :: iterator it = _listaProductos->begin();
    
    for(int i = 1; i <= _listaProductos->size(); ++i, ++it)
        if(it->getNombreProducto() == _nombreProducto)
            return *it;
    
    return Producto();
    
}
//Buscar producto por su nombre.


//Buscar productos por su categoria.
std::list <Producto> buscarProductosPorCategoria(std::list <Producto> * _listaProductos, std::string _categoriaProducto){
    
    std::list <Producto> listaProductos = std::list <Producto>();
    std::list <Producto> :: iterator it = _listaProductos->begin();
    
    for(int i = 1; i <= _listaProductos->size(); ++i, ++it)
        if(it->getCategoriaProducto() == _categoriaProducto)
            listaProductos.push_back(*it);
    
    return listaProductos;
    
}
//Buscar productos por su categoria.


//Buscar productos agotados.
std::list <Producto> buscarProductosAgotados(std::list <Producto> * _listaProductos){
    
    std::list <Producto> listaProductos = std::list <Producto>();
    std::list <Producto> :: iterator it = _listaProductos->begin();
    
    for(int i = 1; i <= _listaProductos->size(); ++i, ++it)
        if(it->getCantidadProducto() == 0)
            listaProductos.push_back(*it);
    
    return listaProductos;
    
}
//Buscar productos agotados.

#endif
