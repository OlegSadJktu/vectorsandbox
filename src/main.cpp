#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "module.h"
#include "window.h"
#include "list.cpp"
#include <iostream>
#include "vector.cpp"
#include "logger.h"



int main(int argc, char **argv) {
	Window win("Hello world", 900, 640);
	bool quit = false;
	SDL_Event event;
	int pos = 0;
	/* win.clear(); */
	int w, h;
	pos = 0;
	win.frame();
	while (!quit) {
		win.setColor();
		if (SDL_WaitEvent(&event) && event.type == SDL_QUIT) {
			quit = true;
		}
		/* switch (event.type) { */
		/* 	case SDL_KEYDOWN: */
		/* 		break; */
		/* for (int i = 0; i < 10; i++) { */
		/* 	win.frame(); */
		/* } */
		/* 	case SDL_MOUSEMOTION: */
		if (event.type == SDL_MOUSEBUTTONDOWN) {
			int x = event.button.x;
			int y = event.button.y;
			Entity *ent = new Square(x,y,10, 10);
			win.addEntity(ent);
			pos += 1;
			SDL_Rect rect;
			rect.h = 10; rect.w = 10; rect.x = x; rect. y = y;
			for (int i = 0; i < pos; i++) {
				SDL_RenderDrawRect(win.renderer, &rect);
			}
			/* SDL_Delay(30); */
			win.frame();

		}

	}

}
