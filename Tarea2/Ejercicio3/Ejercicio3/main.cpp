#include <iostream>
#include "Ordenamiento.h"
#include "Libro.h"

template <typename T>
void imprime(T [], int);

template <typename T>
void imprimeD(T * [], int);

int main(int argc, const char * argv[])
{
    
    const int nlibros = 6;
    
    Libro biblioteca[nlibros];
    
    biblioteca[0] =  Libro("Amanecer", "Juan", 250, 2010);
    biblioteca[1] =  Libro("Jaws", "Peter", 450, 1974);
    biblioteca[2] =  Libro("Crepúsculo", "Carlos", 300, 2012);
    biblioteca[3] =  Libro("Hobbit", "Tolkien", 1280, 2008);
    biblioteca[4] =  Libro("LOTR", "Tolkien", 4050, 1970);
    biblioteca[5] =  Libro("Spies", "Alex", 940, 2015);
    
    int opcionOrden;
    cout << "Ingrese la opcion deseada: " << endl;
    cout << " 1.- Ascendiente" << endl;
    cout << " 2.- Descendiente" << endl;
    cin >> opcionOrden;
    
    int opcionAlgoritmo;
    cout << "Ingrese la opcion deseada: " << endl;
    cout << " 1.- Burbuja" << endl;
    cout << " 2.- Insercion" << endl;
    cout << " 3.- Seleccion" << endl;
    cin >> opcionAlgoritmo;
    
    int opcionParam;
    cout << "Ingrese la opcion deseada: " << endl;
    cout << " 1.- Ordenar por titulo" << endl;
    cout << " 2.- Ordenar por autor" << endl;
    cout << " 3.- Ordenar por año de publicacion" << endl;
    cin >> opcionParam;

    if (opcionOrden == 1)
    {
        if(opcionAlgoritmo == 1)
        {
           if(opcionParam == 1)
           {
              Ordenamiento<Libro>::burbuja(biblioteca, nlibros, [](Libro a, Libro b){ return a.titulo > b.titulo;});
           } else if (opcionParam == 2)
           {
               Ordenamiento<Libro>::burbuja(biblioteca, nlibros, [](Libro a, Libro b){ return a.autor > b.autor;});
           } else if (opcionParam == 3)
           {
               Ordenamiento<Libro>::burbuja(biblioteca, nlibros, [](Libro a, Libro b){ return a.apublicacion > b.apublicacion;});
           }
        } else if (opcionAlgoritmo == 2)
        {
            if(opcionParam == 1)
            {
                Ordenamiento<Libro>::insercion(biblioteca, nlibros, [](Libro a, Libro b){ return a.titulo > b.titulo;});
            } else if (opcionParam == 2)
            {
                Ordenamiento<Libro>::insercion(biblioteca, nlibros, [](Libro a, Libro b){ return a.autor > b.autor;});
            } else if (opcionParam == 3)
            {
                Ordenamiento<Libro>::insercion(biblioteca, nlibros, [](Libro a, Libro b){ return a.apublicacion > b.apublicacion;});
            }
        } else if (opcionAlgoritmo == 3)
        {
            if(opcionParam == 1)
            {
                Ordenamiento<Libro>::seleccion(biblioteca, nlibros, [](Libro a, Libro b){ return a.titulo > b.titulo;});
            } else if (opcionParam == 2)
            {
                Ordenamiento<Libro>::seleccion(biblioteca, nlibros, [](Libro a, Libro b){ return a.autor > b.autor;});
            } else if (opcionParam == 3)
            {
                Ordenamiento<Libro>::seleccion(biblioteca, nlibros, [](Libro a, Libro b){ return a.apublicacion > b.apublicacion;});
            }
        }
    } else if (opcionOrden == 2)
    {
        if(opcionAlgoritmo == 1)
        {
            if(opcionParam == 1)
            {
                Ordenamiento<Libro>::burbuja(biblioteca, nlibros, [](Libro a, Libro b){ return a.titulo < b.titulo;});
            } else if (opcionParam == 2)
            {
                Ordenamiento<Libro>::burbuja(biblioteca, nlibros, [](Libro a, Libro b){ return a.autor < b.autor;});
            } else if (opcionParam == 3)
            {
                Ordenamiento<Libro>::burbuja(biblioteca, nlibros, [](Libro a, Libro b){ return a.apublicacion < b.apublicacion;});
            }
        } else if (opcionAlgoritmo == 2)
        {
            if(opcionParam == 1)
            {
                Ordenamiento<Libro>::insercion(biblioteca, nlibros, [](Libro a, Libro b){ return a.titulo < b.titulo;});
            } else if (opcionParam == 2)
            {
                Ordenamiento<Libro>::insercion(biblioteca, nlibros, [](Libro a, Libro b){ return a.autor < b.autor;});
            } else if (opcionParam == 3)
            {
                Ordenamiento<Libro>::insercion(biblioteca, nlibros, [](Libro a, Libro b){ return a.apublicacion < b.apublicacion;});
            }
        } else if (opcionAlgoritmo == 3)
        {
            if(opcionParam == 1)
            {
                Ordenamiento<Libro>::seleccion(biblioteca, nlibros, [](Libro a, Libro b){ return a.titulo < b.titulo;});
            } else if (opcionParam == 2)
            {
                Ordenamiento<Libro>::seleccion(biblioteca, nlibros, [](Libro a, Libro b){ return a.autor < b.autor;});
            } else if (opcionParam == 3)
            {
                Ordenamiento<Libro>::seleccion(biblioteca, nlibros, [](Libro a, Libro b){ return a.apublicacion < b.apublicacion;});
            }
        }
    }
    
    for(int i = 0; i < nlibros; i++)
    {
    cout << "Titulo: " << biblioteca[i].titulo << " | Autor: " << biblioteca[i].autor << " | Paginas: " << biblioteca[i].paginas << " | Año de publicacion: " << biblioteca[i].apublicacion << endl;
    }
    
    return 0;
}



