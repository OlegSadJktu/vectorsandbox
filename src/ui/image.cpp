#ifndef IMAGE_H
#define IMAGE_H

#include <SDL2/SDL.h>

class Image {

	private:
		SDL_Texture *texture;
		SDL_Rect rect;

	public:

		Image(const char *name) {

		}
		
		~Image() {

		}

};

#endif
