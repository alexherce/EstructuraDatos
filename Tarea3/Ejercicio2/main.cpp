#include <iostream>
#include <string>
#include "LinkedList.h"
#include "Node.h"
using namespace std;

void funcionUnion();
void funcionNmenosM();
void funcionMmenosN();
void funcionMultiplicacion();
void funcionInterseccion();

using namespace vcn;
LinkedList<int> * M  = new LinkedList<int>();
LinkedList<int> * N  = new LinkedList<int>();
LinkedList<int> * P  = new LinkedList<int>();

int main() {

    int temp, index;

    // LLENAR LISTAS

    cout << "Ingrese la cantidad de numeros M a ingresar: " << endl;

    int tempM;
    cin >> tempM;

    cout << "Ingrese la cantidad de numeros N a ingresar: " << endl;

    int tempN;
    cin >> tempN;

    for (int i = 0; i < tempM; i++)
    {
        cout << "Ingrese un numero para M:" << endl;
        cin >> temp;
        M->insertBack(temp);
    }

    for (int i = 0; i < tempN; i++)
    {
        cout << "Ingrese un numero para N:" << endl;
        cin >> temp;
        N->insertBack(temp);
    }

    int option;
    cout << "Ingrese la opcion deseada: " << endl;
    cout << "1.- M U N" << endl;
    cout << "2.- N - M" << endl;
    cout << "3.- M - N" << endl;
    cout << "4.- M * N" << endl;
    cout << "5.- N interseccion M " << endl;
    cout << "6.- Salir " << endl;
    cin >> option;

        switch(option)
        {
        case 1:
            funcionUnion();
            break;
        case 2:
            funcionNmenosM();
            break;
        case 3:
            funcionMmenosN();
            break;
        case 4:
            funcionMultiplicacion();
            break;
        case 5:
            funcionInterseccion();
            break;
        }


    // IMPRIMIR LISTAS

    cout << endl << "-----------------" << endl << "LISTA M: " << endl;
    for (int i = 0; i < M->size(); i++)
    {
        index = M->at(i)->getInfo();
        if (index) {
            cout << "[" << i << "] = " << index << endl;
        }
    }

    cout << endl << "-----------------" << endl << "LISTA N: " << endl;
    for (int i = 0; i < N->size(); i++)
    {
        index = N->at(i)->getInfo();
        if (index) {
            cout << "[" << i << "] = " << index << endl;
        }
    }

    cout << endl << "-----------------" << endl << "LISTA P: " << endl;
    for (int i = 0; i < P->size(); i++)
    {
        index = P->at(i)->getInfo();
        if (index) {
            cout << "[" << i << "] = " << index << endl;
        }
    }

    return 0;
}


void funcionUnion()
{
    for (int i = 0; i < N->size(); ++i)
    {
        P->insertBack(N->at(i)->getInfo());
    }
    for (int i = 0; i < M->size(); ++i)
    {
        bool duplicado = false;
        for (int j = 0; j < N->size(); ++j)
        {
            if (N->at(j)->getInfo() == M->at(i)->getInfo()) duplicado = true;
        }
        if (duplicado == false)
        {
            P->insertBack(M->at(i)->getInfo());
        }
    }
}

void funcionMultiplicacion()
{
    for (int i = 0; i < M->size(); i++)
    {
        for(int j = 0; j < N->size(); j++)
        {
            P->insertBack( M->at(i)->getInfo()*N->at(j)->getInfo());
        }
    }
}

void funcionNmenosM()
{
    for (int i = 0; i < M->size(); ++i)
    {
        bool duplicado = false;
        for (int j = 0; j < N->size(); ++j)
        {
            if (M->at(i)->getInfo() == N->at(j)->getInfo())
            {
                duplicado = true;
                break;
            }
        }
        if (duplicado == false)
        {
            P->insertBack(M->at(i)->getInfo());
        }
    }
}
void funcionMmenosN()
{
    for (int i = 0; i < N->size(); ++i)
    {
            bool duplicado = false;
            for (int j = 0; j < M->size(); ++j)
            {
                if (M->at(i)->getInfo() == N->at(j)->getInfo())
                {
                    duplicado = true;
                    break;
                }
            }
            if (duplicado == false)
            {
                P->insertBack(N->at(i)->getInfo());
            }
    }
}

void funcionInterseccion()
{
    for (int i = 0; i < M->size(); ++i)
    {
        for (int j = 0; j < N->size(); ++j)
        {
            if (M->at(i)->getInfo() == N->at(j)->getInfo())
            {
                P->insertBack(M->at(i)->getInfo());
            }
        }
    }
}
