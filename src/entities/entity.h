#ifndef ENTITY_H
#define ENTITY_H


#include <window/window.h>
#include <window/renderer.h>
#include <math/vector_2.h>

class Renderer;


class Entity {
	protected:
		Vector2 pos;

	public: 
		Entity(int x, int y): pos(x, y) {};

		virtual void draw(Renderer*) = 0;
		virtual ~Entity() {};
};

class Dot: public Entity {

	void draw(Renderer*);
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

		void draw(Renderer *ren) {
			ren->drawRect(&rect);
			/* SDL_RenderDrawRect(renderer, &rect); */
		}
		
};

#endif
