#include "window.h"
#include <SDL2/SDL_image.h>

#define IMG_NAME "hand.png"

Window::Window(const char *name, int w, int h) {
	window = SDL_CreateWindow(name, 0, 0, w, h, SDL_WINDOW_SHOWN);
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
}

void Window::clear() {
	unsigned char r,g,b,a;
	SDL_GetRenderDrawColor(renderer, &r, &g, &b, &a);
	setColor(255, 255, 255);
	SDL_RenderClear(renderer);
	setColor(r,g,b,a);
}

void Window::update() {
	SDL_UpdateWindowSurface(window);
}

void Window::updateRender() {
	SDL_RenderPresent(renderer);
}

void Window::drawLine(int x1, int y1, int x2, int y2) {
	SDL_RenderDrawLine(renderer, x1, y1, x2, y2);
/* SDL_Rect *rect = new SDL_Rect; */
/* 	rect->h = 200, */
/* 	rect->w = 200, */
/* 	rect->x = 20, */
/* 	rect->y = 20, */
/* 	SDL_RenderFillRect(renderer, rect); */
/* 	delete rect; */
}

void Window::setColor(int r, int g, int b, int a) {
	SDL_SetRenderDrawColor(renderer, r,g,b,a);
}

void Window::drawPixel(int x, int y) {
	SDL_RenderDrawPoint(renderer, x, y);
}

void Window::createButton(const char *name, const char *selected) {
	ImageButton *button = new ImageButton(renderer, name, buttonSize, buttonSize);
	button->addSelected(selected);
	button->move(buttons.size() * buttonSize, 0);
	addButton(button);
}

void Window::addEntity(Entity *ent) {
	entities.addToEnd(ent);
}

void Window::addButton(ImageButton *but) {
	buttons.addToEnd(but);
}

void Window::mouseMoved(int curx, int cury) {
	Iterator<ImageButton> *iter = buttons.iterator();
	ImageButton *but;
	bool intersect;
	while (iter->hasNext()) {
		but = iter->getNext();
		intersect = but->checkCursor(curx, cury);
		if (intersect) break;
	}
	delete iter;
	if (intersect) {
		frame();
	}

}

void Window::frame() {
	clear();
	Iterator<Entity> *iter = entities.iterator();
	Entity *ent;
	while (iter->hasNext()) {
		ent = iter->getNext();
		ent->show(this);
	}
	delete iter;
	Iterator<ImageButton> *but_iter = buttons.iterator();
	ImageButton *but;
	while (iter->hasNext()) {
		but = but_iter->getNext();
		but->show();
	}

	/* SDL_Rect img_rect; */
	/* img_rect.h = 64; */
	/* img_rect.w = 64; */
	/* img_rect.x = 0; */
	/* img_rect.y = 0; */
	/* SDL_Texture *img = IMG_LoadTexture(renderer, IMG_NAME); */
	/* SDL_RenderCopy(renderer, img, 0, &img_rect); */
	updateRender();
}

Window::~Window() {
	/* SDL_FreeSurface(surface); */
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
}

