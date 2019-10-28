#include "Knight.h"

Knight::Knight(SDL_Renderer *const renderer, const string &imagePath, bool isWhite, int x, int y) : ChessPiece(renderer, imagePath)
{
    spriteRect.x = x;
    spriteRect.y = y;

    white = isWhite;
    dead = 0;
    type = 2;
}

void Knight::move(int dx, int dy)
{
    if( (dx == 1 && dy == 2) || (dx == 1 && dy == -2)
    || (dx == -1 && dy == 2) || (dx == -1 && dy == -2)
    || (dx == 2 && dy == 1)  || (dx == 2 && dy == -1)
    || (dx == -2 && dy ==1 ) || (dx == -2 && dy == -1))


    {
        ChessPiece::move(dx, dy);
    }
}
