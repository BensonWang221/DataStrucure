#ifndef PLAYER_INCLUDED
#define PLAYER_INCLUDED

struct player
{
    int id, key;

    operator int() const { return key; }
};

#endif