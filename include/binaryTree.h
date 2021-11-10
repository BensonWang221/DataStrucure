#ifndef BINARY_TREE_INCLUDED
#define BINARY_TREE_INCLUDED
#include <functional>
template <class T>
class binaryTree
{
public:
    using Visit_t = std::function<void(T *)>;
    virtual ~binaryTree() {}
    virtual bool empty() const = 0;
    virtual int size() const = 0;
    virtual void preOrder(Visit_t) = 0;
    virtual void inOrder(Visit_t) = 0;
    virtual void postOrder(Visit_t) = 0;
    virtual void levelOrder(Visit_t) = 0;
};
#endif