#ifndef CURSOR_H_INCLUDED
#define CURSOR_H_INCLUDED

#include "Sprite.h"
#include "util.h"
#include "ChessPiece.h"


class Cursor: public Sprite
{
    public:
        Cursor(SDL_Renderer* const renderer, const string &imagePath, int x, int y);
        virtual void move(int dx, int dy);
        virtual void moveTo(int dx, int dy);
        virtual ~Cursor();
        int startX;
        int startY;
        int endX;
        int endY;
        virtual void select();
        virtual void execute(ChessPiece  cp);




};


#endif // Cursor_H_INCLUDED
