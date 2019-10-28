#include "Board.h"

Board::Board(SDL_Renderer* const renderer, const string& imagePath)
{
    SDL_Surface *surface = IMG_Load(imagePath.c_str());
    boardRect.x = 0;
    boardRect.y = 0;
    boardRect.w = surface->w;
    boardRect.h = surface->h;

    texture = SDL_CreateTextureFromSurface(renderer, surface);

    SDL_FreeSurface(surface);

}


void Board::draw(SDL_Renderer* renderer)
{
    SDL_RenderCopy(renderer, texture, NULL, &boardRect);
}

Board::~Board()
{

}
