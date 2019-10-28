#include "Pawn.h"

Pawn::Pawn(SDL_Renderer *const renderer, const string &imagePath, bool isWhite, int x, int y) : ChessPiece(renderer, imagePath)
{
    spriteRect.x = x;
    spriteRect.y = y;

    white = isWhite;
    dead = 0;
    type = 6;
}

void Pawn::move(int dx, int dy)
{
        if( (dx == 0 && dy == -1) || (dx == 0 && dy == -2) || (abs(dx) == 1 && dy == -1 ) || (dx == 0 && dy == 1) || (dx == 0 && dy == 2) || (abs(dx) == 1 && dy == 1 ))
        {
          ChessPiece::move(dx, dy);
        }



}
