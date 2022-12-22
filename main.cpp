// Standard libraries
#include <stdio.h>
#include <cmath>

// Third party libraries
#include <SDL2/SDL.h>

// Screen (rendering/display surface) dimensions
const int SCREEN_WIDTH = 1280;
const float AR = 16.0/9.0;
const int SCREEN_HEIGHT = SCREEN_WIDTH / AR;

int main (int argc, char* args[]) {

	printf("W = %d, H = %d \n", SCREEN_WIDTH, SCREEN_HEIGHT);
	
	SDL_Window* window = NULL;
	SDL_Surface* screen = NULL;

	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
	} else {
		window = SDL_CreateWindow("SDL Tutorial",
			SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
			SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN
		);
		if (window == NULL) {
			printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
		} else {
			// Go fullscreen
			//SDL_SetWindowFullscreen(window, SDL_WINDOW_FULLSCREEN_DESKTOP);
			screen = SDL_GetWindowSurface(window);

			SDL_FillRect(screen, NULL,
				SDL_MapRGB(screen->format, 0x00, 0x00, 0x00)
			);
			SDL_UpdateWindowSurface(window);
			SDL_Delay(5000);
		}
	}

	SDL_DestroyWindow(window);
	SDL_Quit();
	return 0;
}
