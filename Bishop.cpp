#include "Bishop.h"

Bishop::Bishop(SDL_Renderer *const renderer, const string &imagePath, bool isWhite, int x, int y) : ChessPiece(renderer, imagePath)
{
    spriteRect.x = x;
    spriteRect.y = y;

    white = isWhite;
    dead = 0;
    type = 3;
}

void Bishop::move(int dx, int dy)
{
    if( dx != 0 && dx == dy)
    {
        ChessPiece::move(dx, dy);
    }
}
