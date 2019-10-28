#ifndef CHESSPIECE_H_INCLUDED
#define CHESSPIECE_H_INCLUDED

#include "Sprite.h"
#include "util.h"


class ChessPiece: public Sprite


{
    friend class Sprite;
    public:
        ChessPiece(SDL_Renderer* const renderer, const string &imagePath);
        virtual void move(int dx, int dy);
        virtual ~ChessPiece();
        int type;
        bool white;
    protected:
        bool dead;

        int x;
        int y;



};


#endif // CHESSPIECE_H_INCLUDED
