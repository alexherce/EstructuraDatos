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

        int sumDescendants() const;
        int sumDescendants(const BNode<T> * node) const;

        void reflection();
        void reflection(BNode<T> * node);

        bool treeEqual(const BinaryTree<T> * a, const BinaryTree<T> * b) const;
        bool nodeEqual(const BNode<T> *nodeA,   const BNode<T> *nodeB)   const;
        bool operator==(const BinaryTree<T> & a) const;

        BinaryTree<T> * copyTree();
        BNode<T> * copyNode(const BNode<T> * node);

        bool symmetric();

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
    int BinaryTree<T>::sumDescendants() const{
        return sumDescendants(root);
    }

    template <class T>
    int BinaryTree<T>::sumDescendants(const BNode<T> * node)const{

        int temp = 0;
        if (node){
            temp = temp + node->getInfo();
            temp = temp + sumDescendants(node->getLeft());
            temp = temp + sumDescendants(node->getRight());
        }
        return temp;
    }


    template <class T>
    void BinaryTree<T>::reflection(){
        reflection(root);
    }

    template <class T>
    void BinaryTree<T>::reflection(BNode<T> * node){
        if (node){
            BNode<T> * temp = node->getLeft();
            node->setLeft(node->getRight());
            node->setRight(temp);

            reflection(node->getLeft());
            reflection(node->getRight());
        }
    }


    template <class T>
    bool BinaryTree<T>::treeEqual(const BinaryTree<T> * treeA, const BinaryTree<T> * treeB) const{
        return nodeEqual( treeA->getRoot(), treeB->getRoot());
    }


    template <class T>
    bool BinaryTree<T>::nodeEqual(const BNode<T> * node, const BNode<T> * nodeTwo) const{
        bool temp = false;
        if (node && nodeTwo){
            temp = (*node == *nodeTwo);
            temp = temp && nodeEqual(node->getLeft(),  nodeTwo->getLeft());
            temp = temp && nodeEqual(node->getRight(), nodeTwo->getRight());
        } else if(!node && !nodeTwo){
            temp = true;
        }
        return temp;
    }


    template <class T>
    bool BinaryTree<T>::operator == (const BinaryTree<T> & tree) const{
        return treeEqual(this, &tree);
    }


    template <class T>
    BinaryTree<T> * BinaryTree<T>::copyTree(){
        BinaryTree<T> * temp = new BinaryTree<T>();
        BNode<T> * node = new BNode<T>();
        node = copyNode(this->getRoot());
        temp->insert(nullptr, node);
        return temp;
    }


    template <class T>
    BNode<T> * BinaryTree<T>::copyNode(const BNode<T> * node){
        if (node){
            BNode<T> * temp = new BNode<T>();
            temp->setInfo(node->getInfo());
            temp->setRight(copyNode(node->getRight()));
            temp->setLeft(copyNode(node->getLeft()));
            return temp;
        }
        return nullptr;
    }

    template <class T>
    bool BinaryTree<T>::symmetric(){
        BinaryTree<T> * mirror = this->copyTree();
        mirror->reflection();
        if(this == mirror)
        {
           return true;
        } else {
            return false;
        }
    }

}

#endif
