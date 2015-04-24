#ifndef BinaryTree_BinaryTree_h
#define BinaryTree_BinaryTree_h

#include "BNode.h"

namespace ahb {

    template <class T>
    class BinaryTree {
    private:
        BNode<T> * root = nullptr;

    public:
        BinaryTree() {}
        virtual ~BinaryTree();

        bool empty();

        void clear();
        void clear(BNode<T> * node);

        BNode<T> * getRoot() const;
        void setRoot(BNode<T> * node);

        bool insert(BNode<T> * parent, T value);
        bool insert(BNode<T> * parent, BNode<T> * value);

        void preOrder() const;
        void preOrder(BNode<T> * node) const;

        void inOrder() const;
        void inOrder(BNode<T> * node) const;

        void postOrder() const;
        void postOrder(BNode<T> * node) const;

        void isLeaf() const;
        void isLeaf(BNode<T> * node) const;

        void ancestors(BNode<T> * node) const;

        /* Nuevas funciones */

        bool brothers(BNode<T> * node, BNode<T> * nodeTwo);

        void printDescendants(BNode<T> * node) const;

        void printBrothers(BNode<T> * node) const;

        void printCousins(BNode<T> * node) const;

        void printAncestors(BNode<T> * node) const;

    };

    template <class T>
    BinaryTree<T>::~BinaryTree()
    {
        clear();
    }

    template <class T>
    bool BinaryTree<T>::empty()
    {
        return root == nullptr;
    }

    template <class T>
    void BinaryTree<T>::clear()
    {
        clear(root);
    }

    template <class T>
    void BinaryTree<T>::clear(BNode<T> * node)
    {
        if (node) {
            clear(node->getLeft());
            clear(node->getRight());

            delete node;
        }
    }

    template <class T>
    BNode<T> * BinaryTree<T>::getRoot() const
    {
        return root;
    }

    template <class T>
    void BinaryTree<T>::setRoot(BNode<T> * node)
    {
        if (!empty()) {
            node->setLeft(root);
            root->setParent(node);
            root = node;
        }
        else {
            root = node;
        }
    }

    template <class T>
    bool BinaryTree<T>::insert(BNode<T> * parent, T value)
    {
        BNode<T> * node = new BNode<T>(value);
        bool inserted = insert(parent, node);

        if (!inserted) delete node;

        return inserted;
    }

    template <class T>
    bool BinaryTree<T>::insert(BNode<T> * parent, BNode<T> * value)
    {
        bool inserted = false;

        if (empty() || !parent) {
            setRoot(value);
            inserted = true;
        }
        else {
            if (!parent->getLeft()) {
                parent->setLeft(value);
                value->setParent(parent);
                inserted = true;
            }
            else if (!parent->getRight()) {
                parent->setRight(value);
                value->setParent(parent);
                inserted = true;
            }
        }

        return inserted;
    }

    template <class T>
    void BinaryTree<T>::preOrder() const
    {
        preOrder(root);
    }

    template <class T>
    void BinaryTree<T>::preOrder(BNode<T> * node) const
    {
        if (node) {
            /* Procesar el nodo */
            std::cout << *node << std::endl;

            /* Invocar a los hijos */
            preOrder(node->getLeft());
            preOrder(node->getRight());

        }
    }

    template <class T>
    void BinaryTree<T>::inOrder() const
    {
        inOrder(root);
    }

    template <class T>
    void BinaryTree<T>::inOrder(BNode<T> * node) const
    {
        if (node) {

            /* Invocar al hijo izquierdo */
            inOrder(node->getLeft());

            /* Procesar el nodo */
            std::cout << *node << std::endl;

            /* Invocar al hijo derecho */
            inOrder(node->getRight());
        }
    }

    template <class T>
    void BinaryTree<T>::postOrder() const
    {
        postOrder(root);
    }

    template <class T>
    void BinaryTree<T>::postOrder(BNode<T> * node) const
    {
        if (node) {
            /* Invocar a los hijos */
            postOrder(node->getLeft());
            postOrder(node->getRight());

            /* Procesar el nodo */
            std::cout << *node << std::endl;
        }
    }

    template <class T>
    void BinaryTree<T>::isLeaf() const
    {
        isLeaf(root);
    }

    template <class T>
    void BinaryTree<T>::isLeaf(BNode<T> * node) const
    {
        if (node) {
            if (!node->getLeft() && !node->getRight()) {
                std::cout << *node << std::endl;
            }
            else {
                isLeaf(node->getLeft());
                isLeaf(node->getRight());
            }
        }
    }

    template <class T>
    void BinaryTree<T>::ancestors(BNode<T> * node) const
    {
        if (node) {
            std::cout << *node << " -> ";
            ancestors(node->getParent());
        }
    }


    template <class T>
    bool BinaryTree<T>::brothers(BNode<T> * node, BNode<T> * nodeTwo)
    {

        if (node->getParent() == nodeTwo->getParent())
        {
            return true;
        }

        return false;
    }

    template <class T>
    void BinaryTree<T>::printDescendants(BNode<T> * node) const
    {
        if (node) {
            /* Invocar a los hijos */
            printDescendants(node->getLeft());
            printDescendants(node->getRight());

            /* Procesar el nodo */
            std::cout << *node << std::endl;
        }
    }

    template <class T>
    void BinaryTree<T>::printBrothers(BNode<T> * node) const
    {
        BNode<T> * temp = new BNode<T>();

        temp = node->getParent();
        if(temp->getRight() != node)
        {
            temp = temp->getRight();
            std::cout << *temp << std::endl;
        } else if(temp->getLeft() != node){
            temp = temp->getLeft();
             std::cout << *temp << std::endl;
        }
    }

    template <class T>
    void BinaryTree<T>::printCousins(BNode<T> * node) const
    {
        BNode<T> * father = new BNode<T>();
        father = node->getParent();

        BNode<T> * grandpa = new BNode<T>();
        grandpa = father->getParent();

        BNode<T> * tempSon = new BNode<T>();

        if(grandpa->getRight() != father)
        {
            tempSon = grandpa->getRight();
            tempSon = tempSon->getRight();
            if(tempSon)
            std::cout << *tempSon << std::endl;
            tempSon = grandpa->getRight();
            tempSon = tempSon->getLeft();
            if(tempSon)
            std::cout << *tempSon << std::endl;

        } else if(grandpa->getLeft() != father){
            tempSon = grandpa->getLeft();
            tempSon = tempSon->getRight();
            if(tempSon)
            std::cout << *tempSon << std::endl;
            tempSon = grandpa->getLeft();
            tempSon = tempSon->getLeft();
            if(tempSon)
            std::cout << *tempSon << std::endl;
        }
    }

     template <class T>
    void BinaryTree<T>::printAncestors(BNode<T> * node) const
    {
        BNode<T> * temp = new BNode<T>();
        temp = node;
        temp = temp->getParent();

        while(temp != nullptr)
        {
            std::cout << *temp << std::endl;
            temp = temp->getParent();
        }
    }
}

#endif
