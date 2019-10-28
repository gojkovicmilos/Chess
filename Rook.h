#ifndef ROOK_H_INCLUDED
#define ROOK_H_INCLUDED

#include "ChessPiece.h"

class Rook: public ChessPiece
{
    friend class Sprite;

    public:

        Rook(SDL_Renderer * const renderer, const string &imagePath, bool isWhite, int x, int y);
        virtual void move(int dx, int dy);




};


#endif // ROOK_H_INCLUDED
