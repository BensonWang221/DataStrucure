#ifndef INDEXED_BSTREE_INCLUDED
#define INDEXED_BSTREE_INCLUDED

#include "bsTree.h"
template <class K, class E>
class indexedBSTree : public bsTree<K, E>
{
public:
    virtual std::pair<const K, E> *get(int) const = 0;
    virtual void Delete(int) = 0;
};

#endif