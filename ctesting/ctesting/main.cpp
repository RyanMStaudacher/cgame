#include <iostream>
#include <stdio.h>
#include <SDL.h>


int main(int argc, char* argv[])
{
	SDL_Window* window;

	SDL_Init(SDL_INIT_EVERYTHING);

	window = SDL_CreateWindow("Happy Birthday", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1920, 1080, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
	getchar();
	return 0;
}