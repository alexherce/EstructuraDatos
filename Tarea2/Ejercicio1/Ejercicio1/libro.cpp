#include "libro.h"

void Libro::setTitulo(string title)
{
	titulo = title;
}

void Libro::setAutor(string author)
{
	autor = author;
}

void Libro::setEditorial(string edit)
{
	editorial = edit;
}

void Libro::setAno(int anioPublicacion)
{
	fechaPublicacion = anioPublicacion;
}

void Libro::setVacio(bool vacioLleno)
{
	vacio = vacioLleno;
}

string Libro::getNombre()
{
	return titulo;
}

string Libro::getAutor()
{
	return autor;
}

string Libro::getEditorial()
{
	return editorial;
}

int Libro::getFecha()
{
	return fechaPublicacion;
}

bool Libro::getVacio()
{
	return vacio;
}
