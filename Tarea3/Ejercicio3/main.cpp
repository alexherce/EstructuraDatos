#include <iostream>
#include "LinkedList.h"
#include "Persona.h"
using namespace std;
using namespace vcn;

void functionAdd();
void functionSearch();
void functionDelete();
void functionPrint();
void functionDeleteAll();
void functionSize();

 LinkedList<Persona> * personas = new LinkedList<Persona>();

int main()
{
    int menuOption = 1;

    while(menuOption < 7)
    {
        cout << "Ingresa la opcion deseada:" << endl;
        cout << "1.- Añadir una persona." << endl;
        cout << "2.- Buscar una persona." << endl;
        cout << "3.- Borrar una persona." << endl;
        cout << "4.- Ver datos de todas las personas." << endl;
        cout << "5.- Borrar todas las personas." << endl;
        cout << "6.- Determinar numero de personas en la lista" << endl;
        cout << "7.- Salir." << endl;
        cin >> menuOption;

        switch(menuOption)
        {
        case 1:
            functionAdd();
            break;

        case 2:
            functionSearch();
            break;

        case 3:
            functionDelete();
            break;

        case 4:
            functionPrint();
            break;

        case 5:
            functionDeleteAll();
            break;

        case 6:
            functionSize();
            break;
        }
    }
    return 0;
}

void functionAdd()
{
    string nameTemp, lastNameTemp, dateTemp;
    int ageTemp;

    cout << "Ingresa el nombre y apellido de la persona separado por un espacio:" << endl;
    cin >> nameTemp >> lastNameTemp;

    cout << "Ingresa la edad: " << endl;
    cin >> ageTemp;

    cout << "Ingresa la fecha de nacimiento: (DD/MM/AAAA)" << endl;
    cin >> dateTemp;

    personas->insertBack(Persona(nameTemp, lastNameTemp, ageTemp, dateTemp));

    cout << "Persona añadida." << endl << endl;
}

void functionSearch()
{
    string nameSearch, lastNameSearch;

    cout << "Ingresa el nombre y apellido de la persona a buscar separados por un espacio:" << endl;
    cin >> nameSearch >> lastNameSearch;

    for(int i = 0; i < personas->size(); i++)
    {
        if (personas->at(i)->getInfo().getNombre() == nameSearch && personas->at(i)->getInfo().getApellido() == lastNameSearch)
        {
            cout << "Se encontro a la persona en el indice: " << i << endl;
        } else {
            cout << "No existe " << nameSearch << " " << lastNameSearch << " en la lista." << endl << endl;
        }
    }
}

void functionDelete()
{
    int indexDelete;
    string nameTemp, lastNameTemp;

    cout << "Ingresa el indice de la persona a borrar (si no lo conoces, busca primero a la persona): " << endl;
    cin >> indexDelete;

    nameTemp = personas->at(indexDelete)->getInfo().getNombre();
    lastNameTemp = personas->at(indexDelete)->getInfo().getApellido();

    personas->remove(indexDelete);

    cout << nameTemp << " " << lastNameTemp << " ha sido borrado." << endl << endl;

}

void functionPrint()
{
   cout << "Personas en la lista: " << endl;
   cout << *personas << endl << endl;
}

void functionDeleteAll()
{
    cout << "Eliminando a todas las personas en la lista." << endl << endl;
    personas->clear();
}

void functionSize()
{
    cout << "La lista tiene a: " << personas->size() << " miembros." << endl << endl;
}

