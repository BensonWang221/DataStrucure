#ifndef AVLTREE_INCLUDED
#define AVLTREE_INCLUDED

#include <iostream>

template <class T>
struct AVLTreeNode
{
    T value;
    int height;
    AVLTreeNode<T> *right;
    AVLTreeNode<T> *left;

    AVLTreeNode(const T &v, AVLTreeNode *l, AVLTreeNode *r) : value(v), height(0), left(l), right(r) {}
};

template <class T>
class AVLTree
{
private:
    AVLTreeNode<T> *mRoot = nullptr;
    int mSize = 0;

public:
    AVLTree() = default;
    ~AVLTree() {}

    int height() const { return height(mRoot); }

    bool empty() const { return mSize == 0; }

    AVLTreeNode<T> *search(const T &val) const;

    AVLTreeNode<T> *iterativeSearch(const T &val) const;

    void preOrder() const;

    void inOrder() const;

    void postOrder() const;

    void insert(const T &val);

    void erase(const T &val);

    T &maximum() const;
    T &minimum() const;

private:
    AVLTreeNode<T> *search(AVLTreeNode<T> *node, const T &val) const;

    AVLTreeNode<T> *iterativeSearch(AVLTreeNode<T> *node, const T &val) const;

    int height(AVLTreeNode<T> *node) const;

    void preOrder(AVLTreeNode<T> *node) const;

    void inOrder(AVLTreeNode<T> *node) const;

    void postOrder(AVLTreeNode<T> *node) const;

    AVLTreeNode<T> *maximum(AVLTreeNode<T> *node) const;
    AVLTreeNode<T> *minimum(AVLTreeNode<T> *node) const;

    AVLTreeNode<T> *leftLeftRotation(AVLTreeNode<T> *node);

    AVLTreeNode<T> *leftRightRotation(AVLTreeNode<T> *node);

    AVLTreeNode<T> *rightRightRotation(AVLTreeNode<T> *node);

    AVLTreeNode<T> *rightLeftRotation(AVLTreeNode<T> *node);

    AVLTreeNode<T> *insert(AVLTreeNode<T> *node, const T &val);

    AVLTreeNode<T> *erase(AVLTreeNode<T> *node, AVLTreeNode<T> *target);
};

template <class T>
void AVLTree<T>::preOrder(AVLTreeNode<T> *node) const
{
    if (node)
    {
        std::cout << node->value << " ";
        preOrder(node->left);
        preOrder(node->right);
    }
}
template <class T>
void AVLTree<T>::preOrder() const
{
    if (empty())
    {
        std::cout << "Empty" << std::endl;
        return;
    }
    preOrder(mRoot);
    std::cout << std::endl;
}

template <class T>
void AVLTree<T>::inOrder(AVLTreeNode<T> *node) const
{
    if (node)
    {
        inOrder(node->left);
        std::cout << node->value << " ";
        inOrder(node->right);
    }
}
template <class T>
void AVLTree<T>::inOrder() const
{
    if (empty())
    {
        std::cout << "Empty" << std::endl;
        return;
    }
    inOrder(mRoot);
    std::cout << std::endl;
}

template <class T>
void AVLTree<T>::postOrder(AVLTreeNode<T> *node) const
{
    if (node)
    {
        postOrder(node->left);
        postOrder(node->right);
        std::cout << node->value << " ";
    }
}
template <class T>
void AVLTree<T>::postOrder() const
{
    if (empty())
    {
        std::cout << "Empty" << std::endl;
        return;
    }
    postOrder(mRoot);
    std::cout << std::endl;
}

template <class T>
int AVLTree<T>::height(AVLTreeNode<T> *node) const
{
    if (node)
        return node->height;
    return 0;
}

template <class T>
AVLTreeNode<T> *AVLTree<T>::leftLeftRotation(AVLTreeNode<T> *node)
{
    auto temp = node->left;
    node->left = temp->right;
    temp->right = node;

    node->height = std::max(height(node->left), height(node->right)) + 1;
    temp->height = std::max(height(temp->left), height(temp->right)) + 1;
    return temp;
}

template <class T>
AVLTreeNode<T> *AVLTree<T>::rightRightRotation(AVLTreeNode<T> *node)
{
    auto temp = node->right;
    node->right = temp->left;
    temp->left = node;

    temp->height = std::max(height(temp->left), height(temp->right)) + 1;
    node->height = std::max(height(node->left), height(node->right)) + 1;

    return temp;
}

template <class T>
AVLTreeNode<T> *AVLTree<T>::leftRightRotation(AVLTreeNode<T> *node)
{
    node->left = rightRightRotation(node->left);
    return leftLeftRotation(node);
}

template <class T>
AVLTreeNode<T> *AVLTree<T>::rightLeftRotation(AVLTreeNode<T> *node)
{
    node->right = leftLeftRotation(node->right);
    return rightRightRotation(node);
}

template <class T>
AVLTreeNode<T> *AVLTree<T>::search(AVLTreeNode<T> *node, const T &val) const
{
    if (node == nullptr || node->value == val)
        return node;
    if (node->value < val)
        return search(node->right, val);
    return search(node->left, val);
}

template <class T>
AVLTreeNode<T> *AVLTree<T>::search(const T &val) const
{
    return search(mRoot, val);
}

template <class T>
AVLTreeNode<T> *AVLTree<T>::iterativeSearch(AVLTreeNode<T> *node, const T &val) const
{
    while (node && node->value != val)
    {
        if (node->value < val)
            node = node->right;
        else
            node = node->left;
    }
    return node;
}

template <class T>
AVLTreeNode<T> *AVLTree<T>::iterativeSearch(const T &val) const
{
    return iterativeSearch(mRoot, val);
}

template <class T>
AVLTreeNode<T> *AVLTree<T>::insert(AVLTreeNode<T> *node, const T &val)
{
    if (node == nullptr)
        node = new AVLTreeNode<T>(val, nullptr, nullptr);
    else if (node->value < val)
    {
        node->right = insert(node->right, val);
        if (height(node->left) - height(node->right) == -2)
        {
            if (node->right->value < val)
                node = rightRightRotation(node);
            else
                node = rightLeftRotation(node);
        }
    }
    else if (node->value > val)
    {
        node->left = insert(node->left, val);
        if (height(node->left) - height(node->right) == 2)
        {
            if (node->left->value > val)
                node = leftLeftRotation(node);
            else
                node = leftRightRotation(node);
        }
    }
    else
        std::cout << "Do not allow insert value existed!" << std::endl;

    node->height = std::max(height(node->left), height(node->right)) + 1;
    return node;
}

template <class T>
void AVLTree<T>::insert(const T &val)
{
    mRoot = insert(mRoot, val);
    mSize++;
}

template <class T>
AVLTreeNode<T> *AVLTree<T>::erase(AVLTreeNode<T> *node, AVLTreeNode<T> *target)
{
    if (node == nullptr || target == nullptr)
        return nullptr;

    if (node->value < target->value)
    {
        node->right = erase(node->right, target);

        if (height(node->left) - height(node->right) == 2)
        {
            auto left = node->left;
            // 这里不能再判断value了，因为erase以后有子树可能是空!
            if (height(left->left) > height(left->right))
                node = leftLeftRotation(node);
            else
                node = leftRightRotation(node);
        }
    }
    else if (node->value > target->value)
    {
        node->left = erase(node->left, target);

        if (height(node->left) - height(node->right) == -2)
        {
            auto right = node->right;
            if (height(right->left) > height(right->right))
                node = rightLeftRotation(node);
            else
                node = rightRightRotation(node);
        }
    }
    else
    {
        if (node->left && node->right)
        {
            if (height(node->left) > height(node->right))
            {
                auto maxNode = maximum(node->left);
                node->value = maxNode->value;
                node->left = erase(node->left, maxNode);
            }
            else
            {
                auto minNode = minimum(node->right);
                node->value = minNode->value;
                node->right = erase(node->right, minNode);
            }
        }
        else
        {
            auto temp = node;
            node = node->left ? node->left : node->right;
            delete temp;
        }
    }
    if (node)
        node->height = std::max(height(node->left), height(node->right)) + 1;
    return node;
}

template <class T>
void AVLTree<T>::erase(const T &val)
{
    AVLTreeNode<T> *target;
    if ((target = search(val)) != nullptr)
    {
        mRoot = erase(mRoot, target);
        mSize--;
    }
}

template <class T>
AVLTreeNode<T> *AVLTree<T>::maximum(AVLTreeNode<T> *node) const
{
    if (node)
    {
        while (node->right)
            node = node->right;
    }
    return node;
}

template <class T>
AVLTreeNode<T> *AVLTree<T>::minimum(AVLTreeNode<T> *node) const
{
    if (node)
    {
        while (node->left)
            node = node->left;
    }
    return node;
}

template <class T>
T &AVLTree<T>::maximum() const
{
    return maximum(mRoot)->value;
}

template <class T>
T &AVLTree<T>::minimum() const
{
    return minimum(mRoot)->value;
}

#endif