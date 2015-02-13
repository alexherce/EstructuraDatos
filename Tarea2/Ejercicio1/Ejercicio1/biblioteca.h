#include <stdio.h>
#pragma once
#include "libro.h"

class Biblioteca
{
protected:
	Libro* libro;
	int tamBiblioteca;
	int cantLibros = 0;

public:
	Biblioteca(int tamano);
	void addLibro(string nombre, string author, string edit, int date);
	void deleteLibro(string nombre);
	void buscarFecha(int fecha, bool antesDespues);
	void buscarPeriodo(int fechaUno, int fechaDos);
	void buscarAutor(string author);
	void buscarEditorial(string edit);
	void printBiblioteca();
	void getTam();
};
