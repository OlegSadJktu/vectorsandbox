#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "window.h"
#include "list.cpp"
#include <iostream>
#include "double_list.cpp"
#include "logger.h"
#include <memory>



int main(int argc, char **argv) {
	Window win("Hello world", 900, 640);
	bool quit = false;
	SDL_Event event;
	int w, h;
	win.createButton("assets/hand.png", "assets/hand_selected.png");
	win.createButton("assets/add.png", "assets/add_selected.png");
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
		int x,y;
		switch(event.type) {
			case SDL_MOUSEMOTION:
				x = event.motion.x;
				y = event.motion.y;
				win.mouseMoved(x, y);
				break;
			case SDL_MOUSEBUTTONDOWN:
				x = event.button.x;
				y = event.button.y;
				Entity *ent = new Square(x,y,10, 10);
				win.addEntity(ent);
				SDL_Rect rect;
				rect.h = 10; rect.w = 10; rect.x = x; rect. y = y;
				win.frame();
				break;
		}
		if (event.type == SDL_MOUSEBUTTONDOWN) {
		}

	}

}
