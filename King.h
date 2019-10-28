#ifndef KING_H_INCLUDED
#define KING_H_INCLUDED

#include "ChessPiece.h"

class King: public ChessPiece
{
    friend class Sprite;

    public:

        King(SDL_Renderer * const renderer, const string &imagePath, bool isWhite, int x, int y);
        virtual void move(int dx, int dy);
        bool isChecked;
        bool isMated;




};

#endif // KING_H_INCLUDED
