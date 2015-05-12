//
//  main.cpp
//  Ejercicio3
//
//  Created by Alejandro Herce on 12/05/15.
//  Copyright (c) 2015 Alejandro Herce. All rights reserved.
//

#include <iostream>
#include "BinaryTree.h"
using namespace vcn;
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;

vector<string> preorden;
vector<string> inorden;
BinaryTree<string> * arbolBinario = new BinaryTree<string>();

void createTree();


int main(int argc, const char * argv[]) {
    // insert code here...
    
    
    preorden.push_back("G");
    preorden.push_back("E");
    preorden.push_back("A");
    preorden.push_back("I");
    preorden.push_back("B");
    preorden.push_back("M");
    preorden.push_back("C");
    preorden.push_back("L");
    preorden.push_back("D");
    preorden.push_back("F");
    preorden.push_back("K");
    preorden.push_back("J");
    preorden.push_back("H");
    
    
    inorden.push_back("I");
    inorden.push_back("A");
    inorden.push_back("B");
    inorden.push_back("E");
    inorden.push_back("G");
    inorden.push_back("L");
    inorden.push_back("D");
    inorden.push_back("C");
    inorden.push_back("F");
    inorden.push_back("M");
    inorden.push_back("K");
    inorden.push_back("H");
    inorden.push_back("J");
    
    
    createTree();
    
    std::cout << " ---- preOrder ----" << std::endl;
    arbolBinario->preOrder();
    std::cout << std::endl << endl;
    
    std::cout << " ---- inOrder ----" << std::endl;
    arbolBinario->inOrder();
    std::cout << std::endl;
    
    
    
    return 0;
}

void createTree()
{
    int nextPreOrden = 0;
    int nextInOrden = 0;
    int directionInOrden = 0;
    BNode<string> * insert = new BNode<string>(preorden[0]);
    BNode<string> * previous = new BNode<string>(preorden[0]);
    
    //ROOT
    arbolBinario->insert(nullptr, insert);
    previous = insert;
    
    int rootPosInOrder = 0;
    for (int i = 0; i < inorden.size(); i++)
    {
        if (inorden[i] == preorden[0])
        {
            rootPosInOrder = i;
            break;
        }
        
    }
    
    nextInOrden = rootPosInOrder;
    
    for(int i = 0; i < preorden.size(); i++)
    {
        if (directionInOrden == 0)
        {
            nextInOrden--;
            nextPreOrden++;
            
            if(nextInOrden == 0)
            {
                directionInOrden = 1;
                nextInOrden = rootPosInOrder;
            }
            
            insert = new BNode<string>(preorden[nextPreOrden]);
            arbolBinario->insert(previous, insert);
            previous = insert;
            
            if(previous->getInfo() != preorden[nextInOrden - 1])
            {
                
            }
            
            
        } else {
            nextInOrden++;
            nextPreOrden++;
            
            if(nextInOrden == 0)
            {
                directionInOrden = 1;
                nextInOrden = rootPosInOrder;
            }
            
            insert = new BNode<string>(preorden[nextPreOrden]);
            arbolBinario->insert(previous, insert);
            previous = insert;
            
        }
        
        
    }
    
    
    
    
}
