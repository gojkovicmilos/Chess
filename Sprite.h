#ifndef SPRITE_H_INCLUDED
#define SPRITE_H_INCLUDED

#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class ChessPiece;

using namespace std;

class Sprite {
    friend class Engine;
    friend class ChessPiece;
    public:
        //Referenca na const string omogucuje da se konstruktoru prosledi
        //string literal. Konstantni pokazivac na SDL_Renderer.
        Sprite(const string &imagePath, SDL_Renderer * const renderer);
        //Virtualne metode, odnosno metode koje ce se redefinisati u klasama
        //naslednicama.
        virtual void draw(SDL_Renderer * const renderer);
        virtual void move(int dx, int dy);
        virtual void moveTo(int dx, int dy);

        virtual void left(){move(-1, 0);};
        virtual void right(){move(1, 0);};
        virtual void up(){move(0, -1);};
        virtual void down(){move(0, 1);};

        virtual int width() {return spriteRect.w;};
        virtual int height() {return spriteRect.h;};
        virtual void width(int w) {spriteRect.w = w;};
        virtual void height(int h) {spriteRect.h = h;};

        virtual void select();
        virtual void execute(ChessPiece *  cp);

        bool white;
        int type;

        //Virtualni destruktor omogucuje da se destruktor
        //pozove iz klasa naslednica.
        virtual ~Sprite();
    protected:
        SDL_Rect spriteRect;
        SDL_Texture *texture;
};

//Definise se novi tip SpriteFunction koji je pokazivac na
//funkciju clanicu iz klase Sprite koja ima tip povratne vrednosti
//void i pri tome ne prima ni jedan argument.
typedef void (Sprite::*SpriteFunction)();

#endif // SPRITE_H_INCLUDED
