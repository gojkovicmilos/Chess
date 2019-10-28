#include "Engine.h"

bool whiteMove = true;

Engine::Engine()
{
    gameTitle = "";
}

Engine::Engine(const string &gameTitle): gameTitle(gameTitle)
{
}

int roundUp(int numToRound, int multiple)
{
 if(multiple == 0)
 {
  return numToRound;
 }

 int remainder = numToRound % multiple;
 if (remainder == 0)
  {
    return numToRound;
  }

 return numToRound + multiple - remainder;
}

void Engine::init()
{
    SDL_Init(SDL_INIT_VIDEO);
    IMG_Init(IMG_INIT_PNG);
    window = SDL_CreateWindow(gameTitle.c_str(), SDL_WINDOWPOS_UNDEFINED,
                              SDL_WINDOWPOS_UNDEFINED, 600, 600, SDL_WINDOW_RESIZABLE);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
}

bool Engine::run()
{
    //Instanciranje objekta klase AnimatedSprite.
    Sprite *s = new AnimatedSprite("resources/creatures/human1_walk.png", 64, 64, 3, renderer);

    Board *b = new Board(renderer, "resources/creatures/Board.png");

    Sprite *wr1 = new Rook(renderer, "resources/creatures/WhiteRook.png", true, 60, 480);
    Sprite *wr2 = new Rook(renderer, "resources/creatures/WhiteRook.png", true, 480, 480);

    Sprite *wkn1 = new Knight(renderer, "resources/creatures/WhiteKnight.png", true, 120, 480);
    Sprite *wkn2 = new Knight(renderer, "resources/creatures/WhiteKnight.png", true, 420, 480);

    Sprite *wb1 = new Bishop(renderer, "resources/creatures/WhiteBishop.png", true, 180, 480);
    Sprite *wb2 = new Bishop(renderer, "resources/creatures/WhiteBishop.png", true, 360, 480);

    Sprite *wq = new Queen(renderer, "resources/creatures/WhiteQueen.png", true, 240, 480);

    Sprite *wk = new King(renderer, "resources/creatures/WhiteKing.png", true, 300, 480);

    Sprite *wp1 = new Pawn(renderer, "resources/creatures/WhitePawn.png", true, 60, 420);
    Sprite *wp2 = new Pawn(renderer, "resources/creatures/WhitePawn.png", true, 120, 420);
    Sprite *wp3 = new Pawn(renderer, "resources/creatures/WhitePawn.png", true, 180, 420);
    ChessPiece *wp4 = new Pawn(renderer, "resources/creatures/WhitePawn.png", true, 240, 420);
    Sprite *wp5 = new Pawn(renderer, "resources/creatures/WhitePawn.png", true, 300, 420);
    Sprite *wp6 = new Pawn(renderer, "resources/creatures/WhitePawn.png", true, 360, 420);
    Sprite *wp7 = new Pawn(renderer, "resources/creatures/WhitePawn.png", true, 420, 420);
    Sprite *wp8 = new Pawn(renderer, "resources/creatures/WhitePawn.png", true, 480, 420);

    Sprite *br1 = new Rook(renderer, "resources/creatures/BlackRook.png", false, 60, 60);
    Sprite *br2 = new Rook(renderer, "resources/creatures/BlackRook.png", false, 480, 60);

    Sprite *bkn1 = new Knight(renderer, "resources/creatures/BlackKnight.png", false, 120, 60);
    Sprite *bkn2 = new Knight(renderer, "resources/creatures/BlackKnight.png", false, 420, 60);

    Sprite *bb1 = new Bishop(renderer, "resources/creatures/BlackBishop.png", false, 180, 60);
    Sprite *bb2 = new Bishop(renderer, "resources/creatures/BlackBishop.png", false, 360, 60);

    Sprite *bk = new King(renderer, "resources/creatures/BlackKing.png", false, 240, 60);

    Sprite *bq = new Queen(renderer, "resources/creatures/BlackQueen.png", false, 300, 60);

    Sprite *bp1 = new Pawn(renderer, "resources/creatures/BlackPawn.png", false, 60, 120);
    Sprite *bp2 = new Pawn(renderer, "resources/creatures/BlackPawn.png", false, 120, 120);
    Sprite *bp3 = new Pawn(renderer, "resources/creatures/BlackPawn.png", false, 180, 120);
    ChessPiece *bp4 = new Pawn(renderer, "resources/creatures/BlackPawn.png", false, 240, 120);
    Sprite *bp5 = new Pawn(renderer, "resources/creatures/BlackPawn.png", false, 300, 120);
    Sprite *bp6 = new Pawn(renderer, "resources/creatures/BlackPawn.png", false, 360, 120);
    Sprite *bp7 = new Pawn(renderer, "resources/creatures/BlackPawn.png", false, 420, 120);
    Sprite *bp8 = new Pawn(renderer, "resources/creatures/BlackPawn.png", false, 480, 120);

    Sprite *cur = new Cursor(renderer, "resources/creatures/Selection.png", 1000, 1000);

    figures.push_back(wr1);
    figures.push_back(wr2);
    figures.push_back(wkn1);
    figures.push_back(wkn2);
    figures.push_back(wb1);
    figures.push_back(wb2);
    figures.push_back(wk);
    figures.push_back(wq);
    figures.push_back(wp1);
    figures.push_back(wp2);
    figures.push_back(wp3);
    figures.push_back(wp4);
    figures.push_back(wp5);
    figures.push_back(wp6);
    figures.push_back(wp7);
    figures.push_back(wp8);

    figures.push_back(br1);
    figures.push_back(br2);
    figures.push_back(bkn1);
    figures.push_back(bkn2);
    figures.push_back(bb1);
    figures.push_back(bb2);
    figures.push_back(bk);
    figures.push_back(bq);
    figures.push_back(bp1);
    figures.push_back(bp2);
    figures.push_back(bp3);
    figures.push_back(bp4);
    figures.push_back(bp5);
    figures.push_back(bp6);
    figures.push_back(bp7);
    figures.push_back(bp8);


    dynamic_cast<Cursor*>(cur);


    for(size_t i = 0; i<figures.size(); i++)
    {
        dynamic_cast<ChessPiece*>(figures[i]);
        switch (figures[i]->type)
        {
        case 1:
            dynamic_cast<Rook*>(figures[i]);
            break;
        case 2:
            dynamic_cast<Knight*>(figures[i]);
            break;
        case 3:
            dynamic_cast<Bishop*>(figures[i]);
            break;
        case 4:
            dynamic_cast<King*>(figures[i]);
            break;
        case 5:
            dynamic_cast<Queen*>(figures[i]);
            break;
        case 6:
            dynamic_cast<Pawn*>(figures[i]);
            break;
        }
    }




    //Pretplacivanje na dogadjaje, obratiti paznju da je moguce
    //pretplatiti vise obradjivaca na isti dogadjaj.
    observers.insert(std::make_pair(SDLK_LEFT, new KeyEventHandler(s, &Sprite::left)));
    observers.insert(std::make_pair(SDLK_RIGHT, new KeyEventHandler(s, &Sprite::right)));
    observers.insert(std::make_pair(SDLK_UP, new KeyEventHandler(s, &Sprite::up)));
    observers.insert(std::make_pair(SDLK_DOWN, new KeyEventHandler(s, &Sprite::down)));
    //observers.insert(std::make_pair(SDLK_q, new KeyEventHandler(wp1, &Pawn::move(0, 1))));


    bool running = true;
    SDL_Event event;
    uint32_t frameStart = 0;
    uint32_t frameEnd = 0;
    while(running) {
        frameStart = SDL_GetTicks();
        //SDL_PollEvent vadi dogadjaje iz reda cekanja.
        //Izmedju dva ciklusa obrade dogadjaja moze se nakupiti
        //proizvoljan broj dogadjaja stoga se pomocu while petlje
        //obradjuju svi neobradjeni dogadjaji.
        while(SDL_PollEvent(&event)) {
            switch(event.type) {
                case SDL_QUIT:
                    running = false;

                break;



                case SDL_MOUSEMOTION:
                    for(size_t i = 0; i<figures.size(); i++)
                    {
                        int leftA, leftB;
                        int rightA, rightB;
                        int topA, topB;
                        int bottomA, bottomB;


                        leftA = event.button.x;
                        rightA = event.button.x + 10;
                        topA = event.button.y;
                        bottomA = event.button.y + 10;


                        leftB = figures[i]->spriteRect.x+10;
                        rightB = figures[i]->spriteRect.x + figures[i]->spriteRect.w-10;
                        topB = figures[i]->spriteRect.y-10;
                        bottomB = figures[i]->spriteRect.y + figures[i]->spriteRect.h+10;



                        if(topA<=bottomB && bottomA>=topB && rightA>=leftB && leftA<=rightB)
                        {
                            cur->moveTo(figures[i]->spriteRect.x, figures[i]->spriteRect.y);

                            if(event.button.state == SDL_PRESSED)
                            {
                                figures[i]->move(((event.button.x-figures[i]->spriteRect.x)/60), ((event.button.y-figures[i]->spriteRect.y)/60) );


                            }

                        }

                    }




                case SDL_KEYDOWN:
                    if(observers.count(event.key.keysym.sym) > 0) {

                        pair<multimap<SDL_Keycode, KeyEventHandler*>::iterator, multimap<SDL_Keycode, KeyEventHandler*>::iterator> range = observers.equal_range(event.key.keysym.sym);
                        for(multimap<SDL_Keycode, KeyEventHandler*>::iterator it = range.first; it != range.second; it++) {
                            it->second->execute();
                        }
                    }
                    switch(event.key.keysym.sym) {
                        case SDLK_UP:
                            s->move(0, -2);
                        break;
                        case SDLK_DOWN:
                            s->move(0, 2);
                        break;
                        case SDLK_LEFT:
                            s->move(-2, 0);
                        break;
                        case SDLK_RIGHT:
                            s->move(2, 0);
                        break;
                        case SDLK_w:
                            cur->move(0, -1);

                            break;
                        case SDLK_s:

                            cur->move(0, 1);

                            break;
                        case SDLK_a:

                            cur->move(-1, 0);

                            break;
                        case SDLK_d:

                            cur->move(1, 0);

                            break;

                        case SDLK_o:

                            cur->select();
                            for(size_t i = 0; i<figures.size(); i++)
                            {

                                if(cur->spriteRect.x == figures[i]->spriteRect.x &&
                                   cur->spriteRect.x == figures[i]->spriteRect.y )
                                   {


                                    selFigure = figures[i];

                                    dynamic_cast<ChessPiece*>(selFigure);
                                   }

                            }



                            break;

                        case SDLK_p:
                            dynamic_cast<Cursor*>(cur);


                            for(size_t i=0; i<figures.size(); i++)
                            {
                                if(figures[i]->spriteRect.x == cur->spriteRect.x &&
                                   figures[i]->spriteRect.y == cur->spriteRect.y)
                                {
                                  //  ~figures[i]();
                                }
                            }


                            //cur->execute(selFigure);
                            whiteMove = !whiteMove;

                        case SDLK_n:
                            cout<<bp4->white<<endl;
                                cout<<whiteMove<<endl;

                            if (Validate(bp4))
                            {



                            bp4->move(0, 1);
                            whiteMove = true;
                            }

                            break;

                            case SDLK_m:
                                cout<<wp4->white<<endl;
                                cout<<whiteMove<<endl;

                            if (Validate(wp4))
                            {
                                wp4->move(0, -1);
                                whiteMove = false;


                            }

                            break;







                    }
                break;
            }
        }

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        //Iscrtavanje sprite-a.
        b->draw(renderer);

        cur->draw(renderer);


        s->draw(renderer);

        wr1->draw(renderer);
        wr2->draw(renderer);

        wkn1->draw(renderer);
        wkn2->draw(renderer);

        wb1->draw(renderer);
        wb2->draw(renderer);

        wk->draw(renderer);

        wq->draw(renderer);

        wp1->draw(renderer);
        wp2->draw(renderer);
        wp3->draw(renderer);
        wp4->draw(renderer);
        wp5->draw(renderer);
        wp6->draw(renderer);
        wp7->draw(renderer);
        wp8->draw(renderer);

        br1->draw(renderer);
        br2->draw(renderer);

        bkn1->draw(renderer);
        bkn2->draw(renderer);

        bb1->draw(renderer);
        bb2->draw(renderer);

        bk->draw(renderer);

        bq->draw(renderer);

        bp1->draw(renderer);
        bp2->draw(renderer);
        bp3->draw(renderer);
        bp4->draw(renderer);
        bp5->draw(renderer);
        bp6->draw(renderer);
        bp7->draw(renderer);
        bp8->draw(renderer);




        SDL_RenderPresent(renderer);

        frameEnd = SDL_GetTicks();

        //Ogranicavanje brzine iscrtavanja na frameRateCap FPS.
        if(frameEnd - frameStart < frameRateCap) {
            SDL_Delay(frameRateCap - (frameEnd - frameStart));
        }
    }

    return true;
}




bool Engine::Validate(ChessPiece* cp)
{
    int dx;

    if(cp->white == true)
         dx = -60;
    else
         dx = 60;



    for(size_t i = 0; i<figures.size(); i++)
    {
        if( figures[i]->white == whiteMove )
            return true;
    }

    return false;
}

Engine::~Engine()
{
    //Destruktor klase engine oslobadja sve resurse
    //koji su prethodno zauzeti.
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}
