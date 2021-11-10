#ifndef BSTREE_INCLUDED
#define BSTREE_INCLUDED

#include "dictionary.h"

template <class K, class E>
class bsTree : public dictionary<const K, E>
{
public:
    virtual void ascend() = 0;
};

#endif