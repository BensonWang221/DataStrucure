#ifndef COMPLETE_WINNER_TREE_INCLUDED
#define COMPLETE_WINNER_TREE_INCLUDED

#include "winnerTree.h"
#include <iostream>

template <class T>
class completeWinnerTree : public winnerTree<T>
{
public:
    completeWinnerTree(T *thePlayer, int theNumberOfPlayers)
    {
        tree = nullptr;
        initialize(thePlayer, theNumberOfPlayers);
    }

    ~completeWinnerTree()
    {
        delete[] tree;
    }

    void initialize(T *, int);

    int winner() const
    {
        return tree[1];
    }

    void rePlay(int thePlayer);

    void output() const;

private:
    int lowExt;
    int offset;
    int *tree;
    int numberOfPlayers;
    T *player;
    void play(int, int, int);
};

template <class T>
void completeWinnerTree<T>::initialize(T *thePlayer, int theNumberOfPlayers)
{
    this->player = thePlayer;
    this->numberOfPlayers = theNumberOfPlayers;
    delete[] tree;
    tree = new int[theNumberOfPlayers];
    int n = theNumberOfPlayers;

    int s = 1, i;
    for (; 2 * s <= n - 1; s += s)
        ;

    lowExt = 2 * (n - s);
    offset = 2 * s - 1;

    for (int i = 2; i <= lowExt; i += 2)
        play((offset + i) / 2, i - 1, i);

    if (n % 2)
    {
        play(n / 2, tree[n - 1], lowExt + 1);
        i = lowExt + 3;
    }
    else
        i = lowExt + 2;

    for (; i <= n; i += 2)
        play((i - lowExt + n - 1) / 2, i - 1, i);
}

template <class T>
void completeWinnerTree<T>::play(int p, int leftChild, int rightChild)
{
    tree[p] = (player[leftChild] <= player[rightChild] ? leftChild : rightChild);

    for (; p % 2 && p > 1; p /= 2)
        tree[p / 2] = player[tree[p - 1]] <= player[tree[p]] ? tree[p - 1] : tree[p];
}

template <class T>
void completeWinnerTree<T>::rePlay(int thePlayer)
{
    int matchNode, leftChild, rightChild;
    int n = this->numberOfPlayers;

    if (thePlayer <= this->lowExt)
    {
        matchNode = (thePlayer + offset) / 2;
        leftChild = 2 * matchNode - offset;
        rightChild = leftChild + 1;
    }
    else
    {
        matchNode = (thePlayer - lowExt + n - 1) / 2;
        if (matchNode * 2 == n - 1)
        {
            leftChild = tree[2 * matchNode];
            rightChild = thePlayer;
        }
        else
        {
            leftChild = matchNode * 2 - n + 1 + lowExt;
            rightChild = leftChild + 1;
        }
    }
    tree[matchNode] = player[leftChild] <= player[rightChild] ? leftChild : rightChild;

    if (matchNode == n - 1 && n % 2 == 1)
    {
        matchNode /= 2;
        tree[matchNode] = player[tree[n - 1]] <= player[lowExt + 1] ? tree[n - 1] : lowExt + 1;
    }

    matchNode /= 2;
    for (; matchNode >= 1; matchNode /= 2)
    {
        tree[matchNode] = player[tree[matchNode * 2]] <= player[tree[matchNode * 2 + 1]] ? tree[matchNode * 2] : tree[matchNode * 2 + 1];
    }
}

template <class T>
void completeWinnerTree<T>::output() const
{
    std::cout << "number of players: " << numberOfPlayers
              << ", lowExt: " << lowExt
              << ", offset: " << offset << std::endl;

    std::cout << "complete winner tree pointers are " << std::endl;
    for (int i = 1; i < numberOfPlayers; ++i)
        std::cout << tree[i] << ' ';
    std::cout << std::endl;
}

#endif