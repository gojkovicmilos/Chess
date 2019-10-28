#ifndef BOARD_H_INCLUDED
#define BOARD_H_INCLUDED

#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

using namespace std;

class Board
{
    public:
        Board(SDL_Renderer *const renderer, const string &imagePath);
        void draw(SDL_Renderer *renderer);
        virtual ~Board();
        virtual int width() {return boardRect.w;};
        virtual int height() {return boardRect.h;};
        virtual void width(int w) {boardRect.w = w;};
        virtual void height(int h) {boardRect.h = h;};

    protected:
        SDL_Rect boardRect;
        SDL_Texture *texture;


};




#endif // BOARD_H_INCLUDED
