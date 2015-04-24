#include <iostream>
#include "BinaryTree.h"
#include "Persona.h"

using namespace std;
using namespace ahb;
 BinaryTree<Persona> * arbolFamiliar = new BinaryTree<Persona>();

 void printVivos(BNode<Persona> * nodo);
  void printMuertos(BNode<Persona> * nodo);


int main()
{
     BNode<Persona> * juan = new BNode<Persona>(Persona("Juan", true, ""));
    arbolFamiliar->insert(nullptr, juan);

    BNode<Persona> * pedro = new BNode<Persona>(Persona("Pedro", false, "1/1/1999"));
    arbolFamiliar->insert(juan, pedro);

     BNode<Persona> * maria = new BNode<Persona>(Persona("Maria", true, ""));
    arbolFamiliar->insert(juan, maria);

     BNode<Persona> * roberta = new BNode<Persona>(Persona("Roberta", true, ""));
    arbolFamiliar->insert(maria, roberta);

     BNode<Persona> * manuel = new BNode<Persona>(Persona("Manuel", true, ""));
    arbolFamiliar->insert(maria, manuel);

     BNode<Persona> * luis = new BNode<Persona>(Persona("Luis", true, ""));
    arbolFamiliar->insert(pedro, luis);

    BNode<Persona> * marcela = new BNode<Persona>(Persona("Marcela", true, ""));
    arbolFamiliar->insert(pedro, marcela);

    BNode<Persona> * miguel = new BNode<Persona>(Persona("Miguel", true, ""));
    arbolFamiliar->insert(marcela, miguel);

    /* Mostrar el árbol en postOrder */
    std::cout << " ---- postOrder ----" << std::endl;
    arbolFamiliar->postOrder();
    std::cout << std::endl;


    std::cout << " ---- Descendientes de pedro ----" << std::endl;
    arbolFamiliar->printDescendants(pedro);
    std::cout << std::endl;

    std::cout << " ---- Hermanos de Luis ----" << std::endl;
    arbolFamiliar->printBrothers(luis);
    std::cout << std::endl;

    std::cout << " ---- Primos de Marcela ----" << std::endl;
    arbolFamiliar->printCousins(marcela);
    std::cout << std::endl;

    std::cout << " ---- Ancestros de Miguel ----" << std::endl;
    arbolFamiliar->printAncestors(miguel);
    std::cout << std::endl;

     std::cout << " ---- Imprimir miembros vivos ----" << std::endl;
    printVivos(arbolFamiliar->getRoot());
    std::cout << std::endl;

     std::cout << " ---- Imprimir miembros muertos ----" << std::endl;
    printMuertos(arbolFamiliar->getRoot());
    std::cout << std::endl;


    return 0;
}


void printVivos(BNode<Persona> * nodo)
{
     BNode<Persona> * node = new BNode<Persona>();
     node = nodo;
    if (node) {
            /* Invocar a los hijos */
            printVivos(node->getLeft());
            printVivos(node->getRight());

            /* Procesar el nodo */
            if(node->getInfo().getEstado() == true)
            std::cout << *node << std::endl;
        }
}

void printMuertos(BNode<Persona> * nodo)
{
     BNode<Persona> * node = new BNode<Persona>();
     node = nodo;
    if (node) {
            /* Invocar a los hijos */
            printMuertos(node->getLeft());
            printMuertos(node->getRight());

            /* Procesar el nodo */
            if(node->getInfo().getEstado() == false)
            std::cout << *node << std::endl;
        }
}
