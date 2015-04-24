#include <iostream>
#include "BinaryTree.h"

using namespace std;
using namespace ahb;
 BinaryTree<int> * arbolBinario = new BinaryTree<int>();

int main()
{

    BNode<int> * uno = new BNode<int>(1);
    arbolBinario->insert(nullptr, uno);

    BNode<int> * dos = new BNode<int>(2);
    arbolBinario->insert(uno, dos);

    arbolBinario->insert(nullptr, 0);

    BNode<int> * tres = new BNode<int>(3);
    arbolBinario->insert(uno, tres);

    BNode<int> * uno2 = new BNode<int>(1);
    arbolBinario->insert(arbolBinario->getRoot(), uno2);

    BNode<int> * dos2 = new BNode<int>(2);
    arbolBinario->insert(uno2, dos2);

    BNode<int> * tres2 = new BNode<int>(3);
    arbolBinario->insert(uno2, tres2);

    /* Mostrar el árbol en postOrder */
    std::cout << " ---- postOrder ----" << std::endl;
    arbolBinario->postOrder();
    std::cout << std::endl;

    if(arbolBinario->symmetric())
    {
        cout << "El arbol es simetrico." << endl;
    } else {
        cout << "El arbol no es simetrico." << endl;
    }

    delete arbolBinario;

    return 0;
}
