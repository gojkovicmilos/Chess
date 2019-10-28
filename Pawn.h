#ifndef PAWN_H_INCLUDED
#define PAWN_H_INCLUDED

#include "ChessPiece.h"


class Pawn: public ChessPiece
{
    friend class Sprite;

    public:

        Pawn(SDL_Renderer * const renderer, const string &imagePath, bool isWhite, int x, int y);
        virtual void move(int dx, int dy);




};



#endif // PAWN_H_INCLUDED
