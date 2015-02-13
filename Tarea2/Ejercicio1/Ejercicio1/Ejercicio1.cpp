// Ejercicio1.cpp : Defines the entry point for the console application.
//


#include <iostream>
#include "biblioteca.h"
#include "ordenamiento.h"
using namespace std;


int main()
{
	int opcion = 0;
	Biblioteca books(10);

	while (opcion < 10)
	{
		cout << "Ingrese la opcion deseada:" << endl;
		cout << " 1.- Añadir un libro" << endl;
		cout << " 2.- Borrar un libro" << endl;
		cout << " 3.- Buscar un libro antes de una fecha" << endl;
		cout << " 4.- Buscar un libro despues de una fecha" << endl;
		cout << " 5.- Buscar un libro en un periodo" << endl;
		cout << " 6.- Buscar un libro por autor" << endl;
		cout << " 7.- Buscar un libro por editorial" << endl;
		cout << " 8.- Imprimir la biblioteca" << endl;
		cout << " 9.- Capacidad de la biblioteca" << endl;
		cout << " 10.- Salir" << endl;
		cin >> opcion;

		switch (opcion) {
		case 1:
		{
			string nombreAdd, autorAdd, editorialAdd;
			int fechaAdd;
			cout << "AÑADIR UN LIBRO: " << endl;
			cout << "Ingrese el titulo: " << endl;
			cin >> nombreAdd;
			cout << "Ingrese el autor: " << endl;
			cin >> autorAdd;
			cout << "Ingrese la editorial: " << endl;
			cin >> editorialAdd;
			cout << "Ingrese el año de publicacion: " << endl;
			cin >> fechaAdd;
			books.addLibro(nombreAdd, autorAdd, editorialAdd, fechaAdd);
			break;
		}

		case 2:
		{
			string nombreBorrar;
			cout << "BORRAR UN LIBRO: " << endl;
			cout << "Ingrese el titulo del libro a borrar: " << endl;
			cin >> nombreBorrar;
			books.deleteLibro(nombreBorrar);
			break;
		}

		case 3:
		{
			int fechaAntes;
			cout << "BUSCAR UN LIBRO ANTES DE UNA FECHA: " << endl;
			cout << "Ingrese la fecha: " << endl;
			cin >> fechaAntes;
			books.buscarFecha(fechaAntes, true);
			break;
		}
		case 4:
		{
			int fechaDespues;
			cout << "BUSCAR UN LIBRO DESPUES DE UNA FECHA: " << endl;
			cout << "Ingrese la fecha: " << endl;
			cin >> fechaDespues;
			books.buscarFecha(fechaDespues, false);
			break;
		}
		case 5:
		{
			int fechaUno, fechaDos;
			cout << "BUSCAR UN LIBRO EN UN PERIODO: " << endl;
			cout << "Ingrese la fecha mas chica: " << endl;
			cin >> fechaUno;
			cout << "Ingrese la fecha mas grande: " << endl;
			cin >> fechaDos;
			books.buscarPeriodo(fechaUno, fechaDos);
			break;
		}
		case 6:
		{
			string buscarAutor;
			cout << "BUSCAR LIBRO POR AUTOR: " << endl;
			cout << "Ingrese el autor: " << endl;
			cin >> buscarAutor;
			books.buscarAutor(buscarAutor);
			break;
		}
		case 7:
		{
			string buscarEditorial;
			cout << "BUSCAR LIBRO POR EDITORIAL: " << endl;
			cout << "Ingrese la editorial: " << endl;
			cin >> buscarEditorial;
			books.buscarEditorial(buscarEditorial);
			break;
		}
		case 8:
		{
			books.printBiblioteca();
		}
		case 9:
		{
			books.getTam();
		}

		default:
		{
			cout << "Ingrese una opcion valida" << endl;
			break;
		}
		}
	}


	return 0;
}

