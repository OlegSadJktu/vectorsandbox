#ifndef VECTOR_SANDBOX_RENDERER_H
#define VECTOR_SANDBOX_RENDERER_H

#include <SDL2/SDL.h>

class Renderer {

		SDL_Renderer *renderer;

	public:

		Renderer(SDL_Window *window) {
			renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
		}
		~Renderer() {
			SDL_DestroyRenderer(renderer);
		}

		SDL_Renderer *get() {return renderer;}
		void update();
		void drawLine(int x1, int y1, int x2 = 0, int y2 = 0);
		void drawPixel(int x = 0, int y = 0);
		void setColor(int r = 0, int g = 0, int b = 0, int a = 0xff);
		void drawRect(SDL_Rect *rect);
		
		operator SDL_Renderer*() const {
			return renderer;
		}

};

#endif
