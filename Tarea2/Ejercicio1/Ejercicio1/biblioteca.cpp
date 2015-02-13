using namespace std;
#include "biblioteca.h"

Biblioteca::Biblioteca(int tamano)
{
	tamBiblioteca = tamano;
	libro = new Libro[tamBiblioteca];
	cantLibros = 0;

	for (int i = 0; i < tamBiblioteca; i++)
	{
		libro[i].setTitulo(" ");
		libro[i].setAutor(" ");
		libro[i].setEditorial(" ");
		libro[i].setAno(0);
		libro[i].setVacio(true);
	}
}

void Biblioteca::addLibro(string nombre, string author, string edit, int date)
{

	if (cantLibros > 10)
	{
		cout << "La biblioteca ya esta llena. Intenta borrando libros." << endl;
	}
	else {
		for (int i = 0; i < tamBiblioteca; i++)
		{
			if (libro[i].getVacio() == true)
			{
				libro[i].setTitulo(nombre);
				libro[i].setAutor(author);
				libro[i].setEditorial(edit);
				libro[i].setAno(date);
				libro[i].setVacio(false);
				cantLibros = cantLibros + 1;
				cout << "Libro añadido a la base de datos." << endl << endl;
				break;
			}
		}
	}

}

void Biblioteca::deleteLibro(string nombre)
{
	if (cantLibros == 0)
	{
		cout << "La biblioteca esta vacia. Intenta añadiendo libros." << endl;
	}
	else {
		for (int i = 0; i < tamBiblioteca; i++)
		{
			if (nombre == libro[i].getNombre())
			{
				libro[i].setTitulo(" ");
				libro[i].setAutor(" ");
				libro[i].setEditorial(" ");
				libro[i].setAno(-1);
				libro[i].setVacio(true);
				cantLibros = cantLibros - 1;
				cout << "Libro borrado de la base de datos." << endl << endl;
			}
		}
	}
}

void Biblioteca::buscarFecha(int fecha, bool antesDespues)
{

	for (int i = 0; i < tamBiblioteca; i++)
	{
		if (antesDespues == false)
		{
			if (fecha < libro[i].getFecha() && libro[i].getFecha() > 0)
			{
				cout << "Titulo: " << libro[i].getNombre() << endl;
				cout << "Autor: " << libro[i].getAutor() << endl;
				cout << "Editorial: " << libro[i].getEditorial() << endl;
				cout << "Año: " << libro[i].getFecha() << endl << endl;
			}
		}
		else {
			if (fecha > libro[i].getFecha() && libro[i].getFecha() > 0)
			{
				cout << "Titulo: " << libro[i].getNombre() << endl;
				cout << "Autor: " << libro[i].getAutor() << endl;
				cout << "Editorial: " << libro[i].getEditorial() << endl;
				cout << "Año: " << libro[i].getFecha() << endl;
			}
		}
	}
}

void Biblioteca::buscarPeriodo(int fechaUno, int fechaDos)
{
	for (int i = 0; i < tamBiblioteca; i++)
	{
		if (fechaUno > libro[i].getFecha() && fechaDos < libro[i].getFecha())
		{
			cout << "Titulo: " << libro[i].getNombre() << endl;
			cout << "Autor: " << libro[i].getAutor() << endl;
			cout << "Editorial: " << libro[i].getEditorial() << endl;
			cout << "Año: " << libro[i].getFecha() << endl;
		}
	}
}

void Biblioteca::buscarAutor(string author)
{
	for (int i = 0; i < tamBiblioteca; i++)
	{
		if (author == libro[i].getAutor())
		{
			cout << "Titulo: " << libro[i].getNombre() << endl;
			cout << "Autor: " << libro[i].getAutor() << endl;
			cout << "Editorial: " << libro[i].getEditorial() << endl;
			cout << "Año: " << libro[i].getFecha() << endl;
		}
	}
}

void Biblioteca::buscarEditorial(string edit)
{
	for (int i = 0; i < tamBiblioteca; i++)
	{
		if (edit == libro[i].getEditorial())
		{
			cout << "Titulo: " << libro[i].getNombre() << endl;
			cout << "Autor: " << libro[i].getAutor() << endl;
			cout << "Editorial: " << libro[i].getEditorial() << endl;
			cout << "Año: " << libro[i].getFecha() << endl;
		}
	}
}

void Biblioteca::printBiblioteca()
{
	if (cantLibros > 0)
	{
		for (int i = 0; i < cantLibros; i++)
		{
			cout << "LIBRO #" << i + 1 << endl << endl;
			cout << "-----------" << endl;
			cout << "Titulo: " << libro[i].getNombre() << endl;
			cout << "Autor: " << libro[i].getAutor() << endl;
			cout << "Editorial: " << libro[i].getEditorial() << endl;
			cout << "Año: " << libro[i].getFecha() << endl;
			cout << "----------------------------------------" << endl;
		}
	}
	else {
		cout << "La biblioteca esta vacia." << endl;
	}
}

void Biblioteca::getTam()
{
	cout << tamBiblioteca << endl;
}