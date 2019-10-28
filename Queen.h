#ifndef QUEEN_H_INCLUDED
#define QUEEN_H_INCLUDED

#include "ChessPiece.h"


class Queen: public ChessPiece
{
    friend class Sprite;

    public:

        Queen(SDL_Renderer * const renderer, const string &imagePath, bool isWhite, int x, int y);
        virtual void move(int dx, int dy);




};


#endif // QUEEN_H_INCLUDED
