#ifndef WINNER_TREE_INCLUDED
#define WINNER_TREE_INCLUDED
template <class T>
class winnerTree
{
public:
    winnerTree() {}
    virtual void initialize(T *thePlayer, int theNumberOfPlayers) = 0;
    virtual int winner() const = 0;
    virtual void rePlay(int thePlayer) = 0;
};
#endif