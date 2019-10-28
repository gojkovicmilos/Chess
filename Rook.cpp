#include "Rook.h"

Rook::Rook(SDL_Renderer *const renderer, const string &imagePath, bool isWhite, int x, int y) : ChessPiece(renderer, imagePath)
{
    spriteRect.x = x;
    spriteRect.y = y;
    white = isWhite;
    dead = 0;
    type = 1;
}

void Rook::move(int dx, int dy)
{
    if( (dx == 0 && dy != 0) || (dx !=0 && dy == 0))
    {
        ChessPiece::move(dx, dy);
    }
}
