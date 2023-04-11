//#include <iostream>
//#include <stdio.h>
//#include "SDL.h"
//#include "SDL_image.h"
////#undef main
//
//typedef struct
//{
//    int x, y;
//    int life;
//    char *name;
//}Gremlin;
//
//typedef struct
//{
//    //Players
//    Gremlin player;
//
//    //Images
//    SDL_Texture* gremlin;
//
//}Gamestate;
//
////void structs()
////{
////    Dog dog, dog2;
////    dog.x = 2;
////    dog.y = 7;
////    dog.life = 15;
////    dog.name = "Skippy";
////
////    dog2.x = 34;
////    dog2.y = 534;
////    dog2.life = 2;
////    dog2.name = "Rover";
////
////    printf("Dog2's name is %s.", dog2.name);
////}
//
//int max(int thearray[], int n)
//{
//    int returnValue = 0;
//
//    for (size_t i = 0; i < n; i++)
//    {
//        if (thearray[i] > returnValue)
//        {
//            returnValue = thearray[i];
//        }
//    }
//
//    return returnValue;
//}
//
//int processEvents(SDL_Window* window, Gamestate* game)
//{
//    int done = 0;
//    SDL_Event event;
//
//    while (SDL_PollEvent(&event))
//    {
//        switch (event.type)
//        {
//        case SDL_WINDOWEVENT_CLOSE:
//        {
//            if (window)
//            {
//                SDL_DestroyWindow(window);
//                window = NULL;
//                done = 1;
//            }
//        }
//        break;
//        case SDL_KEYDOWN:
//        {
//            switch (event.key.keysym.sym)
//            {
//            case SDLK_ESCAPE:
//                done = 1;
//                break;
//            /*case SDLK_RIGHT:
//                
//                break;
//            case SDLK_LEFT:
//                
//                break;
//            case SDLK_UP:
//                
//                break;
//            case SDLK_DOWN:
//                
//                break;*/
//            }
//        }
//        break;
//        case SDL_QUIT:
//            done = 1;
//            break;
//        }
//    }
//
//    const Uint8* state = SDL_GetKeyboardState(NULL);
//    const int speed = 5;
//    if (state[SDL_SCANCODE_RIGHT])
//    {
//        game->player.x += speed;
//    }
//    
//    if (state[SDL_SCANCODE_LEFT])
//    {
//        game->player.x -= speed;
//    }
//    
//    if (state[SDL_SCANCODE_UP])
//    {
//        game->player.y -= speed;
//    }
//
//    if (state[SDL_SCANCODE_DOWN])
//    {
//        game->player.y += speed;
//    }
//
//    return done;
//}
//
//void doRender(SDL_Renderer* theRenderer, Gamestate *game)
//{
//    //SDL_SetRenderDrawColor(theRenderer, 149, 82, 81, 255);
//
//    SDL_RenderClear(theRenderer);
//
//    //SDL_SetRenderDrawColor(theRenderer, 255, 255, 255, 255);
//
//    SDL_Rect rect = { game->player.x, game->player.y, 200, 200 };
//    SDL_RenderFillRect(theRenderer, &rect);
//
//    //game->gremlin = IMG_LoadTexture(theRenderer, "gremlin.png");
//
//    SDL_RenderCopy(theRenderer, game->gremlin, NULL, &rect);
//
//    SDL_RenderPresent(theRenderer);
//}
//
//void SDLFirstPass()
//{
//    Gamestate gameState;
//    SDL_Window* window = NULL;
//    SDL_Renderer* renderer = NULL;
//    SDL_Surface* gremlinSurface = NULL;
//
//    SDL_Init(SDL_INIT_VIDEO);
//
//    gameState.player.x = 220;
//    gameState.player.y = 140;
//
//    window = SDL_CreateWindow("Game Window", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1920, 1080, 0);
//    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
//
//    //SDL_Texture* gremlin = IMG_LoadTexture(renderer, "gremlin.png");
//
//    gremlinSurface = IMG_Load("gremlin.png");
//    if (gremlinSurface == NULL)
//    {
//        printf("Can't find the image.\n\n");
//        SDL_Quit();
//    }
//
//    SDL_SetRenderDrawColor(renderer, 149, 82, 81, 255);
//
//    gameState.gremlin = SDL_CreateTextureFromSurface(renderer, gremlinSurface);
//    SDL_FreeSurface(gremlinSurface);
//
//    int done = 0;
//
//    while (!done)
//    {
//        
//        done = processEvents(window, &gameState);
//
//        doRender(renderer, &gameState);
//
//        
//
//        //SDL_Delay(1);
//    }
//
//    SDL_DestroyTexture(gameState.gremlin);
//    SDL_DestroyWindow(window);
//    SDL_DestroyRenderer(renderer);
//    //SDL_Quit();
//}
//
//
//
//
//
//int main(int argc, char * argv[])
//{
//    //int thearray[10] = { 100,2,3,4,5,6,7,8,9,10 };
//
//    ///*for (size_t i = 0; i < 10; i++)
//    //{
//    //    printf("%d\n", thearray[i]);
//    //}
//
//    //printf("The first number in the array is: %d", thearray[0]);*/
//
//    //printf("The max number of the array is: %d\n\n", max(thearray, 10));
//
//    //structs();
//
//    //getchar();
//
//    SDLFirstPass();
//    return 0;
//}
//
