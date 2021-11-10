enum RBTColor
{
    RED,
    BLACK
};

template <class T>
struct RBTNode
{
    RBTColor color = RED;
    T key;
    RBTNode *left = nullptr;
    RBTNode *right = nullptr;
    RBTNode *parent = nullptr;

    RBTNode(T theKey, RBTNode *theLeft, RBTNode *theRight, RBTNode *theParent, RBTColor theColor = RED) : key(theKey), left(theLeft), right(theRight), parent(theParent), color(theColor)
    {
    }
};

template <class T>
class RBTree
{
public:
private:
    // root node
    RBTNode<T> *mRoot = nullptr;
};