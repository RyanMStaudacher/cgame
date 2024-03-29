#include <iostream>
#include <stdio.h>
#include <SDL.h>

void ProcessEvents(SDL_Window* window, SDL_Renderer* renderer, SDL_Rect* gremlinRect);
SDL_Rect InitRect(int xPos, int yPos, int width, int height);

int FPS = 60;
int FrameStartTimeMS = 0;

float spriteDstY = 0.0f;
float spriteDstX = 0.0f;


int main(int argc, char* argv[])
{
	SDL_Window* window;
	SDL_Renderer* renderer;

	SDL_Init(SDL_INIT_EVERYTHING);

	window = SDL_CreateWindow("Happy Birthday", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1920, 1080, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC | SDL_RENDERER_ACCELERATED);

	SDL_Surface* gremlinSurface = SDL_LoadBMP("../Images/gremlin.bmp");

	if (!gremlinSurface)
	{
		std::cout << "Error loading gremlin surface.";
	}

	SDL_Texture* gremlinTexture = SDL_CreateTextureFromSurface(renderer, gremlinSurface);
	SDL_FreeSurface(gremlinSurface);
	
	int done = 0;
	SDL_Rect gremlinRect = InitRect(0,0,200,200);

	while (!done)
	{
		SDL_RenderClear(renderer);

		/*gremlinRect.x = 0;
		gremlinRect.y = 0;
		gremlinRect.w = 100;
		gremlinRect.h = 100;*/

		ProcessEvents(window, renderer, &gremlinRect);

		SDL_RenderFillRect(renderer, &gremlinRect);

		SDL_RenderCopy(renderer, gremlinTexture, NULL, &gremlinRect);

		SDL_RenderPresent(renderer);

		while (SDL_GetTicks() - FrameStartTimeMS < 1000 / FPS);
	}

	SDL_DestroyTexture(gremlinTexture);
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);

	getchar();
	return 0;
}

void ProcessEvents(SDL_Window* window, SDL_Renderer* renderer, SDL_Rect* gremlinRect)
{
	SDL_Event event;
	float gSpeed = 5.0f;
	FrameStartTimeMS = SDL_GetTicks();

	while (SDL_PollEvent(&event))
	{
		if (SDL_KEYDOWN)
		{
			if (event.key.keysym.sym == SDLK_LEFT)
			{
				gremlinRect->x -= gSpeed;
			}
			else if (event.key.keysym.sym == SDLK_RIGHT)
			{
				gremlinRect->x += gSpeed;
			}
		}
	}
}

SDL_Rect InitRect(int xPos, int yPos, int width, int height)
{
	SDL_Rect iRect;
	iRect.x = 0;
	iRect.y = 0;
	iRect.w = 200;
	iRect.h = 200;
	return iRect;
}