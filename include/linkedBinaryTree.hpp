#ifndef LINKED_BINARYTREE_INCLUDED
#define LINKED_BINARYTREE_INCLUDED
#include "binaryTree.h"
#include "binaryTreeNode.h"
#include <queue>
#include <iostream>

template <class T>
class linkedBinaryTree : public binaryTree<binaryTreeNode<T>>
{
    using Node_t = binaryTreeNode<T>;
    using BaseClass = binaryTree<Node_t>;
    using Visit_t = std::function<void(Node_t *)>;

public:
    linkedBinaryTree() = default;
    linkedBinaryTree(Node_t *node) : root(node) {}

    ~linkedBinaryTree() { erase(); }

    bool empty() const override
    {
        return treeSize == 0;
    }

    int size() const override
    {
        return treeSize;
    }

    void preOrder(Visit_t theVisit) override
    {
        visit = theVisit;
        preOrder(root);
    }

    void inOrder(Visit_t theVisit) override
    {
        visit = theVisit;
        inOrder(root);
    }

    void postOrder(Visit_t theVisit) override
    {
        visit = theVisit;
        postOrder(root);
    }

    void erase()
    {
        postOrder(dispose);
        root = nullptr;
        treeSize = 0;
    }

    void levelOrder(Visit_t theVisit);

    int height() const;

protected:
    binaryTreeNode<T> *root = nullptr;
    int treeSize = 0;
    std::function<void(binaryTreeNode<T> *)> visit;

    void preOrder(Node_t *node);
    void inOrder(Node_t *node);
    void postOrder(Node_t *node);
    static void dispose(binaryTreeNode<T> *node) { delete node; }
    int height(Node_t *node) const;
};

template <class T>
void linkedBinaryTree<T>::levelOrder(Visit_t theVisit)
{
    visit = theVisit;
    std::queue<Node_t *> q;
    Node_t *node = root;
    while (node)
    {
        visit(node);
        if (node->leftChild)
            q.push(node->leftChild);

        if (node->rightChild)
            q.push(node->rightChild);

        if (q.empty())
            return;
        node = q.front();
        q.pop();
    }
}

template <class T>
void linkedBinaryTree<T>::preOrder(Node_t *node)
{
    if (node)
    {
        visit(node);
        preOrder(node->leftChild);
        preOrder(node->rightChild);
    }
}

template <class T>
void linkedBinaryTree<T>::inOrder(Node_t *node)
{
    if (node)
    {
        inOrder(node->leftChild);
        visit(node);
        inOrder(node->rightChild);
    }
}

template <class T>
void linkedBinaryTree<T>::postOrder(Node_t *node)
{
    if (node)
    {
        postOrder(node->leftChild);
        postOrder(node->rightChild);
        visit(node);
    }
}

template <class T>
int linkedBinaryTree<T>::height() const
{
    return height(root);
}

template <class T>
int linkedBinaryTree<T>::height(Node_t *node) const
{
    if (!node)
        return 0;

    return (std::max(height(node->leftChild), height(node->rightChild)) + 1);
}

template <class T>
void Visit(binaryTreeNode<T> *node)
{
    std::cout << node->element << '\t';
}
#endif