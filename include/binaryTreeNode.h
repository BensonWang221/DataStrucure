#ifndef BINARY_TREENODE_INCLUDED
#define BINARY_TREENODE_INCLUDED
template <class T>
struct binaryTreeNode
{
    T element;
    binaryTreeNode<T> *leftChild = nullptr;
    binaryTreeNode<T> *rightChild = nullptr;

    binaryTreeNode() = default;

    binaryTreeNode(const T &element) : element(element), leftChild(nullptr), rightChild(nullptr) {}

    binaryTreeNode(const T &element, binaryTreeNode<T> *left, binaryTreeNode<T> *right) : element(element), leftChild(left), rightChild(right) {}
};
#endif