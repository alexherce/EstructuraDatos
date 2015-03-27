//
//  Pila.h
//  Pilas
//
//  Created by Alejandro Herce on 09/10/14.
//  Copyright (c) 2014 Alejandro Herce. All rights reserved.
//

#ifndef __Pilas__Pila__
#define __Pilas__Pila__

#include <iostream>
#include "ListaEnlazada.h"
using namespace std;

template <class T>
class Pila: protected ListaEnlazada<T>
{
public:
    Pila();
    ~Pila();
    
    void push(T value);
    Nodo<T> * pop();
    Nodo<T> * top();
    
    int size() override;
    bool empty() override;
    
    template <class Tn>
    friend std::ostream & operator <<(std::ostream &, Pila<Tn> &);
    
    
};

template <class T>
Pila<T>::Pila():ListaEnlazada<T>()
{
    
}

template <class T>
Pila<T>::~Pila()
{
    this->clear();
}

template <class T>
void Pila<T>::push(T value)
{
    this->insertFront(value);
}

template <class T>
Nodo<T> * Pila<T>::pop()
{
    return this->deleteFront();
}

template <class T>
Nodo<T> * Pila<T>::top()
{
    return this->start();
}

template <class T>
int Pila<T>::size()
{
    return ListaEnlazada<T>::size();
}

template <class T>
bool Pila<T>::empty()
{
    return ListaEnlazada<T>::empty();
}

template <class T>
ostream & operator <<(ostream & os, Pila<T> & pila)
{
    Nodo<T> * aux = pila.inicio;
    
    while (aux) {
        os << *aux << endl;
        aux = aux->getSiguiente();
    }
    
    return os;
}


#endif /* defined(__Pilas__Pila__) */
