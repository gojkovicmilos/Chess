#include "King.h"

King::King(SDL_Renderer *const renderer, const string &imagePath, bool isWhite, int x, int y) : ChessPiece(renderer, imagePath)
{
    spriteRect.x = x;
    spriteRect.y = y;

    white = isWhite;
    dead = 0;
    type = 4;
}

void King::move(int dx, int dy)
{
    if( (dx == 0 && abs(dy) == 1) || (dy == 0 && abs(dx) == 1) || (dx == dy && abs(dy) ==1))

    {
        ChessPiece::move(dx, dy);
    }
}
