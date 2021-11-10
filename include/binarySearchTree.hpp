#ifndef BINARY_SERACHTREE_INCLUDED
#define BINARY_SERACHTREE_INCLUDED

#include "bsTree.h"
#include "linkedBinaryTree.hpp"

using namespace std;

namespace
{
    template <class K, class E>
    void output(binaryTreeNode<pair<const K, E>> *theNode)
    {
        cout << theNode->element.first << ": "
             << theNode->element.second << "\t";
    }
}
template <class K, class E>
class binarySearchTree : bsTree<K, E>,
                         linkedBinaryTree<pair<const K, E>>
{
public:
    bool empty() const { return this->treeSize == 0; }

    int size() const { return this->treeSize; }

    pair<const K, E> *find(const K &theKey) const;

    void insert(const pair<const K, E> &thePair);

    void erase(const K &theKey);

    void ascend() { this->inOrder(output<K, E>); }
};

template <class K, class E>
pair<const K, E> *binarySearchTree<K, E>::find(const K &theKey) const
{
    auto p = this->root;
    while (p)
    {
        if (p->element.first > theKey)
            p = p->leftChild;

        else if (p->element.first < theKey)
            p = p->rightChild;

        else
            return &p->element;
    }
    return nullptr;
}

template <class K, class E>
void binarySearchTree<K, E>::insert(const pair<const K, E> &thePair)
{
    binaryTreeNode<pair<const K, E>> *p = this->root, *pp = nullptr;
    while (p)
    {
        pp = p;
        if (thePair.first < p->element.first)
            p = p->leftChild;
        else if (thePair.first > p->element.first)
            p = p->rightChild;
        else
        {
            p->element.second = thePair.second;
            return;
        }
    }
    auto newNode = new binaryTreeNode<pair<const K, E>>(thePair);

    if (this->root != nullptr)
    {
        if (thePair.first < pp->element.first)
            pp->leftChild = newNode;
        else
            pp->rightChild = newNode;
    }
    else
        this->root = newNode;

    this->treeSize++;
}

template <class K, class E>
void binarySearchTree<K, E>::erase(const K &theKey)
{
    binaryTreeNode<pair<const K, E>> *p = this->root, *pp = nullptr;
    while (p && p->element.first != theKey)
    {
        pp = p;
        if (p->element.first < theKey)
            p = p->rightChild;
        else
            p = p->leftChild;
    }

    if (p == nullptr)
        return;

    if (p->leftChild && p->rightChild)
    {
        // find max key node in left child
        decltype(p) s = p->leftChild, ps = p;
        while (s->rightChild)
        {
            ps = p;
            s = s->rightChild;
        }
        auto q = new binaryTreeNode<pair<const K, E>>(s->element, p->leftChild, p->rightChild);

        if (pp == nullptr)
            this->root = q;

        else if (p == pp->leftChild)
            pp->leftChild = q;

        else
            pp->rightChild = q;

        if (ps == p)
            pp = q;
        else
            pp = ps;

        delete p;
        p = s;
    }
    binaryTreeNode<pair<const K, E>> *c = p->leftChild ? p->leftChild : p->rightChild;

    if (p == this->root)
        this->root = c;
    else if (p == pp->leftChild)
        pp->leftChild = c;
    else
        pp->rightChild = c;

    this->treeSize--;
    delete p;
}

#endif