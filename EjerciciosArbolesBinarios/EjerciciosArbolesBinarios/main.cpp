//
//  main.cpp
//  EjerciciosArbolesBinarios
//
//  Created by Alejandro Herce on 13/04/15.
//  Copyright (c) 2015 Alejandro Herce. All rights reserved.
//

#include <iostream>
#include "BinaryTree.h"
using namespace std;
using namespace ahb;

int main(int argc, const char * argv[]) {
    
    /* Crear un árbol binario */
    BinaryTree<int> numeros;
    
    /* Insertar nodos */
    
    BNode<int> * uno = new BNode<int>(1);
    numeros.insert(nullptr, uno);
    
    BNode<int> * dos = new BNode<int>(2);
    numeros.insert(uno, dos);
    
    numeros.insert(nullptr, 0);
    
    BNode<int> * tres = new BNode<int>(3);
    numeros.insert(uno, tres);
    
    BNode<int> * cuatro = new BNode<int>(4);
    numeros.insert(dos, cuatro);
    
    BNode<int> * cinco = new BNode<int>(5);
    numeros.insert(numeros.getRoot(), cinco);
    
    numeros.insert(numeros.getRoot(), 100);
    
    /* Mostrar el árbol en preOrder */
    cout << " ---- preOrder ----" << endl;
    numeros.preOrder();
    cout << endl;
    
    /* Mostrar el árbol en inOrder */
    cout << " ---- inOrder ----" << endl;
    numeros.inOrder();
    cout << endl;
    
    /* Mostrar el árbol en postOrder */
    cout << " ---- postOrder ----" << endl;
    numeros.postOrder();
    cout << endl;
    
    /* Mostrar los nodos hojas */
    cout << " ---- Hojas del árbol ----" << endl;
    numeros.isLeaf();
    cout << endl;
    
    /* Mostrar los ancestros de un nodo */
    BNode<int> * node = numeros.getRoot();
    cout << " ---- Ancestros de " << *node << " ----" << endl;
    numeros.ancestors(node);
    cout << endl;
    cout << endl;
    
    /* Mostrar si dos nodos son hermanos */
    cout << " ---- Comprobar si dos y tres son hermanos ---- " << endl;
    if(numeros.brothers(dos, tres) == true)
    {
        cout << "Son hermanos!" << endl;
    } else {
        cout << "No son hermanos!" << endl;
    }
    cout << endl;
    
    
}
