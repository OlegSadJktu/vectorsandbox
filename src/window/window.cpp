#include "window.h"
#include <SDL2/SDL_image.h>

#define IMG_NAME "hand.png"

Window::Window(const char *name, int w, int h) {
	window = SDL_CreateWindow(name, 0, 0, w, h, SDL_WINDOW_SHOWN);
	renderer = new Renderer(window);
	/* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC); */
}

void Window::clear() {
	unsigned char r,g,b,a;
	SDL_GetRenderDrawColor(renderer->get(), &r, &g, &b, &a);
	renderer->setColor(255, 255, 255);
	SDL_RenderClear(renderer->get());
	renderer->setColor(r,g,b,a);
}

void Window::update() {
	SDL_UpdateWindowSurface(window);
}

void Window::updateRender() {
	SDL_RenderPresent(renderer->get());
}

void Window::drawPixel(int x, int y) {
	SDL_RenderDrawPoint(renderer->get(), x, y);
}

void Window::createButton(const char *name, const char *selected) {
	ImageButton *button = new ImageButton(renderer->get(), name, buttonSize, buttonSize);
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
		ent->draw(renderer);
	}
	delete iter;
	Iterator<ImageButton> *but_iter = buttons.iterator();
	ImageButton *but;
	while (iter->hasNext()) {
		but = but_iter->getNext();
		but->show();
	}

	updateRender();
}

Window::~Window() {
	SDL_DestroyWindow(window);
	delete renderer;
}

