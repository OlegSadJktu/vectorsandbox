#include "renderer.h"

void Renderer::update() {
	SDL_RenderPresent(renderer);
}

void Renderer::drawLine(int x1, int y1, int x2, int y2) {
	SDL_RenderDrawLine(renderer, x1, y1, x2, y2);
}

void Renderer::setColor(int r, int g, int b, int a) {
	SDL_SetRenderDrawColor(renderer, r,g,b,a);
}

void Renderer::drawPixel(int x, int y) {
	SDL_RenderDrawPoint(renderer, x, y);
}

void Renderer::drawRect(SDL_Rect *rect) {
	SDL_RenderDrawRect(renderer, rect);
}
