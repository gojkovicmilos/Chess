#ifndef ENGINE_H_INCLUDED
#define ENGINE_H_INCLUDED

#include <iostream>
#include <map>
#include <utility>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "Sprite.h"
#include "AnimatedSprite.h"
#include "KeyEventHandler.h"
#include "Board.h"
#include "Bishop.h"
#include "King.h"
#include "Knight.h"
#include "Pawn.h"
#include "Queen.h"
#include "Rook.h"
#include "Cursor.h"


using namespace std;

class Engine {
    friend class Sprite;
    public:
        Engine();
        Engine(const string &gameTitle);
        vector<Sprite*> figures;
        Sprite* selFigure;
        void init();
        bool run();
        virtual ~Engine();
        bool Validate(ChessPiece* cp);
        int RoundUp(int numToRound, int multiple);
        bool whiteMove;
    private:
        //16ms ~ 60FPS.
        float frameRateCap = 16;
        string gameTitle;
        SDL_Window *window;
        SDL_Renderer *renderer;
        multimap<SDL_Keycode, KeyEventHandler*> observers;

};

#endif // ENGINE_H_INCLUDED
