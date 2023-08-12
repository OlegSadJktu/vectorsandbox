#ifndef VECTOR_SANDBOX_WINDOW_H
#define VECTOR_SANDBOX_WINDOW_H

#include <SDL2/SDL.h>
#include "vector.cpp"
#include "entity.h"


class Window {

	private:

	public:
		SDL_Window *window;
		DoubleLinkedList<class Entity> entities;
		SDL_Renderer *renderer;

		Window(const char *name, int width, int height);
		void clear();
		void update();
		void updateRender();
		void drawLine(int x1, int y1, int x2 = 0, int y2 = 0);
		void drawPixel(int x = 0, int y = 0);
		void setColor(int r = 0, int g = 0, int b = 0, int a = 0xff);
		void addEntity(Entity*);
		void frame();

		~Window();
};

#endif
