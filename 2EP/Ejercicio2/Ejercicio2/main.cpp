//
//  main.cpp
//  Ejercicio2
//
//  Created by Alejandro Herce on 09/04/15.
//  Copyright (c) 2015 Alejandro Herce. All rights reserved.
//

#include <iostream>
#include "LinkedList.h"

using namespace vcn;
using namespace std;

LinkedList<int> listL;
LinkedList<int> listR;
void listaRepetida();

int main(int argc, const char * argv[]) {
    
    listL.insertBack(5);
    listL.insertBack(2);
    listL.insertBack(7);
    listL.insertBack(2);
    listL.insertBack(5);
    listL.insertBack(5);
    listL.insertBack(1);
    
    cout << listL << endl;
    
    listaRepetida();
    
    cout << endl << endl;
    
    cout << listR << endl;
    
    
    listL.clear();
    listR.clear();
    
    return 0;
}


void listaRepetida()
{
    int temp1;
    int temp2;
    int contVar = 0;
    for (int i = 0; i < listL.size(); i++)
    {
        contVar = 0;
        temp1 = listL.at(i)->getInfo();
        for(int j = 0; j < listL.size(); j++)
        {
            temp2 = listL.at(j)->getInfo();
            if (temp1 == temp2)
            {
                if (contVar == 1)
                {
                    if(listR.search(temp1) == false)
                    {
                    listR.insertBack(temp1);
                    contVar++;
                    }
                }
                contVar++;
            }
        }
    }
}