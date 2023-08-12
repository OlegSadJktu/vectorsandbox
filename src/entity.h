#ifndef ENTITY_H
#define ENTITY_H


#include "window.h"

class Window;

class Position {

	public:
		int x, y;
		Position(int _x = 0, int _y = 0) {
			x = _x;
			y = _y;
		}
};

class Entity {
	protected:
		Position pos;

	public: 
		Entity(int x, int y): pos(x, y) {};

		virtual void show(Window*) = 0;
		virtual ~Entity() {};
};

class Dot: public Entity {

	void show(Window *window);
	~Dot();

};

class Square : public Entity {
		SDL_Rect rect;

	public: 

		Square(int x, int y, int _width, int _height ) : Entity(x,y) {
			rect.x = x;
			rect.y = y;
			rect.h = _height;
			rect.w = _width;
		}

		void show(Window *window);
		
};

#endif
