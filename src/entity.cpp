
#include "entity.h"

void Dot::show(Window *window) {
	window->drawPixel(pos.x, pos.y);
}

Dot::~Dot() {

}

void Square::show(Window *window) {
	SDL_RenderDrawRect(window->renderer, &rect);
}
