#ifndef VECTOR_SANDBOX_WINDOW_H
#define VECTOR_SANDBOX_WINDOW_H

#include <SDL2/SDL.h>
#include "../collections/double_list.cpp"
#include <entities/entity.h>
#include <ui/image_button.cpp>
#include <window/renderer.h>


class Window {

	private:
		static const int buttonSize = 64;

	public:
		SDL_Window *window;
		DoubleLinkedList<class Entity> entities;
		DoubleLinkedList<class ImageButton> buttons;
		Renderer *renderer;

		Window(const char *name, int width, int height);
		void clear();
		void update();
		void updateRender();
		void drawLine(int x1, int y1, int x2 = 0, int y2 = 0);
		void drawPixel(int x = 0, int y = 0);
		void setColor(int r = 0, int g = 0, int b = 0, int a = 0xff);
		void createButton(const char *name, const char *selected);
		void addEntity(Entity*);
		void addButton(ImageButton*);
		void mouseMoved(int, int);
		void frame();

		~Window();
};

#endif
