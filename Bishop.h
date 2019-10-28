#ifndef BISHOP_H_INCLUDED
#define BISHOP_H_INCLUDED

#include "ChessPiece.h"

class Bishop: public ChessPiece
{
    friend class Sprite;

    public:

        Bishop(SDL_Renderer * const renderer, const string &imagePath, bool isWhite, int x, int y);
        virtual void move(int dx, int dy);




};



#endif // BISHOP_H_INCLUDED
