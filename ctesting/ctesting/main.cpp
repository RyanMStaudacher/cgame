#include <iostream>
#include <stdio.h>
#include <SDL.h>


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

	while (!done)
	{
		SDL_RenderClear(renderer);

		SDL_Rect gremlinRect;
		gremlinRect.x = 0;
		gremlinRect.y = 0;
		gremlinRect.w = 200;
		gremlinRect.h = 200;

		SDL_RenderFillRect(renderer, &gremlinRect);

		SDL_RenderCopy(renderer, gremlinTexture, NULL, &gremlinRect);

		SDL_RenderPresent(renderer);
	}

	SDL_DestroyTexture(gremlinTexture);
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);

	getchar();
	return 0;
}