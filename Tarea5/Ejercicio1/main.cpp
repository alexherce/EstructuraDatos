#include <iostream>
#include "BinaryTree.h"

using namespace std;
using namespace ahb;
 BinaryTree<int> * arbolBinario = new BinaryTree<int>();

void sumarArbolDes(BNode<int> * nodo);

int main()
{

    BNode<int> * uno = new BNode<int>(1);
    arbolBinario->insert(nullptr, uno);

    BNode<int> * dos = new BNode<int>(2);
    arbolBinario->insert(uno, dos);

    arbolBinario->insert(nullptr, 0);

    BNode<int> * tres = new BNode<int>(3);
    arbolBinario->insert(uno, tres);

    BNode<int> * cuatro = new BNode<int>(4);
   arbolBinario->insert(dos, cuatro);

    BNode<int> * cinco = new BNode<int>(5);
    arbolBinario->insert(arbolBinario->getRoot(), cinco);

    /* Mostrar el árbol en postOrder */
    std::cout << " ---- postOrder ----" << std::endl;
    arbolBinario->postOrder();
    std::cout << std::endl;

    sumarArbolDes(arbolBinario->getRoot());

    /* Mostrar el árbol en postOrder */
    std::cout << " ---- postOrder ----" << std::endl;
    arbolBinario->postOrder();
    std::cout << std::endl;

    delete arbolBinario;

    return 0;
}

void sumarArbolDes(BNode<int> * nodo){

        if (nodo){
            nodo->setInfo(arbolBinario->sumDescendants(nodo));
            sumarArbolDes(nodo->getLeft());
            sumarArbolDes(nodo->getRight());
        }
    }
