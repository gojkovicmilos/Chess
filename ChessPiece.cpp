#include "ChessPiece.h"

ChessPiece::ChessPiece(SDL_Renderer* const renderer, const string &imagePath): Sprite(imagePath, renderer)
{
    dead = 0;
}

void ChessPiece::move(int dx, int dy)
{

    if(spriteRect.x>=120 && spriteRect.x<=420 && spriteRect.y>=120 && spriteRect.y<=420)
    {

    spriteRect.x+=dx*60;
    spriteRect.y+= dy*60;
    }
}

ChessPiece::~ChessPiece()
{
    SDL_DestroyTexture(texture);
}
