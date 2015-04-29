//
//  FuncionesClientes.h
//  ProyectoFinal
//
//  Created by Alejandro Herce on 24/11/14.
//  Copyright (c) 2014 Alejandro Herce. All rights reserved.
//

#ifndef ProyectoFinal_FuncionesClientes_h
#define ProyectoFinal_FuncionesClientes_h


#include "Cliente.h"
#include <list>
#include <fstream>
#include <iostream>

//DefiniciÛn.

void almacenarInformacionClientesEnLista(std::list <Cliente> *, std::string);
void agregarClienteEnLista(std::list <Cliente> *, Cliente);
void eliminarClienteEnLista(std::list <Cliente> *, int);
void reasignarNumeroClienteEnLista(std::list <Cliente> *);
void imprimirInformacionClientes(std::list <Cliente> *);
void almacenarInformacionClientesEnArchivoTxt(std::list <Cliente> *, std::string);

Cliente ingresarInformacionCliente();

bool verificarExistenciaCliente(std::list <Cliente> *, Cliente);
int obtenerNumeroCompras(std::list <Cliente> *, int);
void actualizarNumeroCompras(std::list <Cliente> *, int);
double obtenerMontoTotalGastado(std::list <Cliente> *, int);
void actualizarMontoTotalGastado(std::list <Cliente> *, int, double);

Cliente obtenerClienteLeal(std::list <Cliente> *);
Cliente obtenerClientePrometedor(std::list <Cliente> *);

//DefiniciÛn.


//Almacenar la informaciÛn de los clientes que se encuentra en un archivo de texto, en una lista enlazada.
void almacenarInformacionClientesEnLista(std::list <Cliente> * _listaClientes, std::string _nombreArchivo){
    
    std::string lineaDeTexto, concatenacionNombreCliente, concatenacionNumCompras, concatenacionMontoTotalGastado;
    std::ifstream archivoClientes("/Users/Herce/" + _nombreArchivo + ".txt");
    double $concatenacionMontoTotalGastado;
    int $concatenacionNumCompras;
    int numLineas = 0;
    
    while(getline(archivoClientes, lineaDeTexto)){
        
        int indiceNombre, indiceNumProductos, indiceMonto;
        
        concatenacionNombreCliente = "";
        concatenacionNumCompras = "";
        concatenacionMontoTotalGastado = "";
        
        numLineas += 1;
        
        for(int i = 0; lineaDeTexto[i] != ' '; i++)
            indiceNombre = (i + 2);
        
        for(int i = indiceNombre; i < lineaDeTexto.length() && lineaDeTexto[i] != ' '; i++){
            
            concatenacionNombreCliente += lineaDeTexto[i];
            indiceNumProductos = (i + 2);
            
        }
        
        for(int i = indiceNumProductos; i < lineaDeTexto.length() && lineaDeTexto[i] != ' '; i++){
            
            concatenacionNumCompras += lineaDeTexto[i];
            indiceMonto = (i + 2);
            
        }
        
        for(int i = indiceMonto; i < lineaDeTexto.length(); i++)
            concatenacionMontoTotalGastado += lineaDeTexto[i];
        
        $concatenacionNumCompras = atoi(concatenacionNumCompras.c_str());
        $concatenacionMontoTotalGastado = atof(concatenacionMontoTotalGastado.c_str());
        
        Cliente clienteTemp = Cliente(numLineas, concatenacionNombreCliente, $concatenacionNumCompras, $concatenacionMontoTotalGastado);
        
        if(concatenacionNombreCliente != "" && concatenacionNumCompras != "" && concatenacionMontoTotalGastado != "")
            _listaClientes->push_back(clienteTemp);
        
    }
				
    archivoClientes.close();
    
}
//Almacenar la informaciÛn de los clientes que se encuentra en un archivo de texto, en una lista enlazada.


//Agregar un cliente a la lista.
void agregarClienteEnLista(std::list <Cliente> * _listaClientes, Cliente _cliente){
    
    _cliente.setNumeroCliente(_listaClientes->size() + 1);
    _listaClientes->push_back(_cliente);
    
}
//Agregar un cliente a la lista.


//Eliminar un cliente de la lista.
void eliminarClienteEnLista(std::list <Cliente> * _listaClientes, int _numeroCliente){
    
    std::list <Cliente> :: iterator it = _listaClientes->begin();
    
    for(int i = 1; i < _numeroCliente; ++i)
        ++it;
    
    _listaClientes->erase(it);
    
}
//Eliminar un cliente de la lista.


//Reasignar n˙mero de cliente a los clientes de la lista.
void reasignarNumeroClienteEnLista(std::list <Cliente> * _listaClientes){
    
    std::list <Cliente> :: iterator it = _listaClientes->begin();
    
    for(int i = 0; i < _listaClientes->size(); ++i){
        
        it->setNumeroCliente(i + 1);
        
        ++it;
        
    }
}
//Reasignar n˙mero de cliente a los clientes de la lista.


//Imprimir la informaciÛn de todos los clientes.
void imprimirInformacionClientes(std::list <Cliente> * _listaClientes){
    
    for(std::list <Cliente> :: iterator it = _listaClientes->begin(); it != _listaClientes->end(); ++it)
        std::cout << "\n\t\t" << *it;
    
}
//Imprimir la informaciÛn de todos los clientes.


//Almacenar la informaciÛn de los clientes en un archivo txt.
void almacenarInformacionClientesEnArchivoTxt(std::list <Cliente> * _listaClientes, std::string _nombreArchivo){
    
    std::ofstream entradaCliente;
    
    entradaCliente.open("/Users/Herce/" + _nombreArchivo + ".txt", std::ios::out);
    
    for(std::list <Cliente> :: iterator it = _listaClientes->begin(); it != _listaClientes->end(); ++it)
        entradaCliente << *it << std::endl;
    
    entradaCliente.close();
    
}
//Almacenar la informaciÛn de los clientes en un archivo txt.


//Ingresar la informaciÛn de un cliente.
Cliente ingresarInformacionCliente(){
    
    std::string nombreClienteIngreso;
    
    std::cout << "\n\t\tIngrese el nombre del cliente: ";
    std::cin >> nombreClienteIngreso;
    
    return Cliente(-1, nombreClienteIngreso, 0, 0.0);
    
}
//Ingresar la informaciÛn de un cliente.


//Verificar la existencia de un cliente de acuerdo con su n˙mero y nombre.
bool verificarExistenciaCliente(std::list <Cliente> * _listaClientes, std::string _nombreCliente, int _numeroCliente){
    
    std::list <Cliente> :: iterator it = _listaClientes->begin();
    
    for(int i = 0; i <= _listaClientes->size(); ++i, ++it)
        if(it->getNumeroCliente() == _numeroCliente && it->getNombreCliente() == _nombreCliente)
            return true;
    
    return false;
    
}
//Verificar la existencia de un cliente de acuerdo con su n˙mero y nombre.


//Obtener el n˙mero de compras que a realizado un cliente de acuerdo con su n˙mero.
int obtenerNumeroCompras(std::list <Cliente> * _listaClientes, int _numeroCliente){
    
    std::list <Cliente> :: iterator it = _listaClientes->begin();
    
    for(int i = 0; i < _numeroCliente; ++i)
        ++it;
    
    return it->getNumeroCompras();
    
}
//Obtener el n˙mero de compras que a realizado un cliente de acuerdo con su n˙mero.


//Actualizar el n˙mero de compras que a realizado un cliente de acuerdo con su n˙mero.
void actualizarNumeroCompras(std::list <Cliente> * _listaClientes, int _numeroCliente){
    
    std::list <Cliente> :: iterator it = _listaClientes->begin();
    
    for(int i = 1; i < _numeroCliente; ++i, ++it);
    
    return it->setNumeroCompras(it->getNumeroCompras() + 1);
    
}
//Actualizar el n˙mero de compras que a realizado un cliente de acuerdo con su n˙mero.


//Obtener el monto gastado por un cliente de acuerdo a su n˙mero.
double obtenerMontoTotalGastado(std::list <Cliente> * _listaClientes, int _numeroCliente){
    
    std::list <Cliente> :: iterator it = _listaClientes->begin();
    
    for(int i = 1; i < _numeroCliente; ++i, ++it);
    
    return it->getMontoTotalGastado();
    
}
//Obtener el monto gastado por un cliente de acuerdo a su n˙mero.


//Actualizar el monto gastado por un cliente de acuerdo a su n˙mero.
void actualizarMontoTotalGastado(std::list <Cliente> * _listaClientes, int _numeroCliente, double _montoTotalGastado){
    
    std::list <Cliente> :: iterator it = _listaClientes->begin();
    
    for(int i = 1; i < _numeroCliente; ++i, ++it);
    
    return it->setMontoTotalGastado(it->getMontoTotalGastado() + _montoTotalGastado);
    
}
//Actualizar el monto gastado por un cliente de acuerdo a su n˙mero.


//Obtener el cliente con mayor n˙mero de compras.
Cliente obtenerClienteLeal(std::list <Cliente> * _listaClientes){
    
    Cliente clienteRetorno = Cliente();
    int mayorNumeroCompras = 0;
    
    for(std::list <Cliente> :: iterator it = _listaClientes->begin(); it != _listaClientes->end(); ++it)
        if(it->getNumeroCompras() > mayorNumeroCompras){
            
            mayorNumeroCompras = it->getNumeroCompras();
            clienteRetorno = *it;
            
        }
    
    return clienteRetorno;
    
}
//Obtener el cliente con mayor n˙mero de compras.


//Obtener el cliente que a invertido m·s.
Cliente obtenerClientePrometedor(std::list <Cliente> * _listaClientes){
    
    Cliente clienteRetorno = Cliente();
    double mayorInversion = 0.0;
    
    for(std::list <Cliente> :: iterator it = _listaClientes->begin(); it != _listaClientes->end(); ++it)
        if(it->getMontoTotalGastado() > mayorInversion){
            
            mayorInversion = it->getMontoTotalGastado();
            clienteRetorno = *it;
            
        }
    
    return clienteRetorno;
    
}
//Obtener el cliente que a invertido m·s.

#endif
