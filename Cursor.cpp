#include "Cursor.h"

Cursor::Cursor(SDL_Renderer* const renderer, const string &imagePath, int x, int y): Sprite(imagePath, renderer)
{

}

void Cursor::move(int dx, int dy)
{
    if(spriteRect.x<481 && spriteRect.y<481 && spriteRect.x>59 && spriteRect.y>59  )
    {
        spriteRect.x += dx*60;
        spriteRect.y += dy*60;
    }
    else
    {
        spriteRect.x -= dx*60;
        spriteRect.y -= dy*60;
    }
}

void Cursor::moveTo(int dx, int dy)
{
    spriteRect.x = dx;
    spriteRect.y = dy;
}

void Cursor::select()
{
    startX = spriteRect.x;
    startY = spriteRect.y;


}

void Cursor::execute(ChessPiece cp)
{
    endX = spriteRect.x;
    endY = spriteRect.y;

    cp.move((endX-startX)/60, (endY-startY)/60);


}

Cursor::~Cursor()
{

}
