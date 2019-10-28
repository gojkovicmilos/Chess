#ifndef KNIGHT_H_INCLUDED
#define KNIGHT_H_INCLUDED

#include "ChessPiece.h"

class Knight: public ChessPiece
{
    friend class Sprite;

    public:

        Knight(SDL_Renderer * const renderer, const string &imagePath, bool isWhite, int x, int y);
        virtual void move(int dx, int dy);




};

#endif // KNIGHT_H_INCLUDED
