//
//  FuncionesTrabajadores.h
//  ProyectoFinal
//
//  Created by Alejandro Herce on 24/11/14.
//  Copyright (c) 2014 Alejandro Herce. All rights reserved.
//

#ifndef ProyectoFinal_FuncionesTrabajadores_h
#define ProyectoFinal_FuncionesTrabajadores_h


#include "Trabajador.h"
#include <list>
#include <fstream>
#include <iostream>

//DefiniciÛn.

void almacenarInformacionTrabajadoresEnLista(std::list <Trabajador> *, std::string);
void agregarTrabajadorEnLista(std::list <Trabajador> *, Trabajador);
void eliminarTrabajadorEnLista(std::list <Trabajador> *, int);
void reasignarNumeroTrabajadorEnLista(std::list <Trabajador> *);
void imprimirInformacionTrabajadores(std::list <Trabajador> *);
void almacenarInformacionTrabajadoresEnArchivoTxt(std::list <Trabajador> *, std::string);

Trabajador ingresarInformacionTrabajador();

Trabajador ingresarInformacionInicioSesion();
bool validarInicioSesion(std::list <Trabajador> *, Trabajador);

//DefiniciÛn.


//Almacenar la informaciÛn de los trabajadores que se encuentra en un archivo de texto, en una lista enlazada.
void almacenarInformacionTrabajadoresEnLista(std::list <Trabajador> * _listaTrabajadores, std::string _nombreArchivo){
    
    std::string lineaDeTexto, concatenacionNombre, concatenacionContrasena;
    std::ifstream archivoTrabajadores("/Users/Herce/" + _nombreArchivo + ".txt");
    int numLineas = 0;
    
    while(getline(archivoTrabajadores, lineaDeTexto)){
        
        int indiceNombre, indiceContrasena = 0;
        
        concatenacionNombre = "";
        concatenacionContrasena = "";
        
        numLineas += 1;
        
        for(int i = 0; lineaDeTexto[i] != ' '; i++)
            indiceNombre = (i + 2);
        
        for(int i = indiceNombre; i < lineaDeTexto.length() && lineaDeTexto[i] != ' '; i++){
            
            concatenacionNombre += lineaDeTexto[i];
            indiceContrasena = (i + 2);
            
        }
        
        for(int i = indiceContrasena; i < lineaDeTexto.length(); i++)
            concatenacionContrasena += lineaDeTexto[i];
        
        Trabajador trabajadorTemp = Trabajador(numLineas, concatenacionNombre, concatenacionContrasena);
        
        if(concatenacionNombre != ""  && concatenacionContrasena != "")
            _listaTrabajadores->push_back(trabajadorTemp);
        
    }
				
    archivoTrabajadores.close();
    
}
//Almacenar la informaciÛn de los trabajadores que se encuentra en un archivo de texto, en una lista enlazada.


//Agregar un trabajador a la lista.
void agregarTrabajadorEnLista(std::list <Trabajador> * _listaTrabajadores, Trabajador _trabajador){
    
    _trabajador.setNumeroTrabajador((int)_listaTrabajadores->size() + 1);
    _listaTrabajadores->push_back(_trabajador);
    
}
//Agregar un trabajador a la lista.


//Eliminar un trabajador de la lista.
void eliminarTrabajadorEnLista(std::list <Trabajador> * _listaTrabajadores, int _numeroTrabajador){
    
    std::list <Trabajador> :: iterator it = _listaTrabajadores->begin();
    
    for(int i = 1; i < _numeroTrabajador; ++i)
        ++it;
    
    _listaTrabajadores->erase(it);
    
}
//Eliminar un trabajador de la lista.


//Reasignar n˙mero de trabajador a los trabajadores en la lista.
void reasignarNumeroTrabajadorEnLista(std::list <Trabajador> * _listaTrabajadores){
    
    std::list <Trabajador> :: iterator it = _listaTrabajadores->begin();
    
    for(int i = 0; i < _listaTrabajadores->size(); ++i){
        
        it->setNumeroTrabajador(i + 1);
        
        ++it;
        
    }
}
//Reasignar n˙mero de trabajador a los trabajadores en la lista.


//Imprimir la informaciÛn de todos los trabajadores.
void imprimirInformacionTrabajadores(std::list <Trabajador> * _listaTrabajadores){
    
    for(std::list <Trabajador> :: iterator it = _listaTrabajadores->begin(); it != _listaTrabajadores->end(); ++it)
        std::cout << "\n\t\t" << *it;
    
}
//Imprimir la informaciÛn de todos los trabajadores.


//Almacenar la informaciÛn de los trabajadores de la lista en un archivo txt.
void almacenarInformacionTrabajadoresEnArchivoTxt(std::list <Trabajador> * _listaTrabajadores, std::string _nombreArchivo){
    
    std::ofstream entradaTrabajador;
    
    entradaTrabajador.open("/Users/Herce/" + _nombreArchivo + ".txt", std::ios::out);
    
    for(std::list<Trabajador>::iterator it = _listaTrabajadores->begin(); it != _listaTrabajadores->end(); ++it)
        entradaTrabajador << *it << std::endl;
    
    entradaTrabajador.close();
    
}
//Almacenar la informaciÛn de los trabajadores de la lista en un archivo txt.


//Ingresar la informaciÛn de un trabajador.
Trabajador ingresarInformacionTrabajador(){
    
    std::string nombreTrabajadorIngreso;
    std::string contrasenaTrabajadorIngreso;
    
    std::cout << "\n\t\tIngrese el nombre del trabajador: ";
    std::cin >> nombreTrabajadorIngreso;
    
    std::cout << "\n\t\tIngrese la contrasena del trabajador: ";
    std::cin >> contrasenaTrabajadorIngreso;
    
    return Trabajador(-1, nombreTrabajadorIngreso, contrasenaTrabajadorIngreso);
    
}
//Ingresar la informaciÛn de un trabajador.


//Ingresar la informaciÛn para poder iniciar sesion.
Trabajador ingresarInformacionInicioSesion(){
    
    std::string numeroTrabajadorIngreso;
    std::string nombreTrabajadorIngreso;
    std::string contrasenaTrabajadorIngreso;
    
    int $numeroTrabajadorIngreso;
    
    std::cout << "\n\t\tIngrese el numero de trabajador: ";
    std::cin >> numeroTrabajadorIngreso;
    $numeroTrabajadorIngreso = atoi(numeroTrabajadorIngreso.c_str());
    
    std::cout << "\n\t\tIngrese el nombre: ";
    std::cin >> nombreTrabajadorIngreso;
    
    std::cout << "\n\t\tIngrese la contrasena: ";
    std::cin >> contrasenaTrabajadorIngreso;
    
    return Trabajador($numeroTrabajadorIngreso, nombreTrabajadorIngreso, contrasenaTrabajadorIngreso);
    
}
//Ingresar la informaciÛn para poder iniciar sesion


//Verificar que el trabajador exista en la lista.
bool validarInicioSesion(std::list <Trabajador> *_listaTrabajadores, Trabajador _trabajador){
    
    for(std::list<Trabajador>::iterator it = _listaTrabajadores->begin(); it != _listaTrabajadores->end(); ++it)
        if(_trabajador == *it)
            return true;
    
    return false;
    
}
//Verificar que el trabajador exista en la lista.

#endif
