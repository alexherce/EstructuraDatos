#pragma once
#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

class Libro {
protected:
	string titulo;
	string autor;
	string editorial;
	int fechaPublicacion;
	bool vacio;

public:
	void setTitulo(string title);
	void setAutor(string author);
	void setEditorial(string edit);
	void setAno(int anioPublicacion);
	void setVacio(bool vacioLleno);

	string getNombre();
	string getAutor();
	string getEditorial();
	int getFecha();
	bool getVacio();

};
