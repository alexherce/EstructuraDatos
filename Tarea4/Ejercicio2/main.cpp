#include <iostream>

#include "CircularLinkedList.h"
using namespace std;
using namespace vcn;
CircularLinkedList<string> * tokenring = new CircularLinkedList<string>();

void editNode (int, string);

int main()
{

    int cantComp;
    cout << "Ingrese el numero de computadoras en la red:" << endl;
    cin >> cantComp;

    int compFuente;
    cout << "Ingrese la computadora de origen: " << endl;
    cin >> compFuente;

    int compDestino;
    cout << "Ingrese la computadora destino: " << endl;
    cin >> compDestino;

    string mensaje;
    cout << "Ingrese el mensaje a enviar: " << endl;
    cin >> mensaje;
    cout << mensaje << endl;

    for (int i = 0; i < cantComp; i++)
    {
            tokenring->insertBack("En espera...");
    }


    int contador = 0;
    while (tokenring->at(compDestino)->getInfo() != mensaje)
    {
        if(contador >= compFuente)
        {
            editNode(contador, mensaje);
            contador++;
        } else {
            contador++;
        }
    }

    for(int i = 0; i < cantComp; i++)
    {
        cout << "Computadora #" << i << ": " << tokenring->at(i)->getInfo() << endl;
    }


    return 0;
}

void editNode(int position, string mensaje)
{
    tokenring->remove(position);
    tokenring->LinkedList::insert(mensaje, position);
}
