#ifndef IMAGE_BUTTON_H
#define IMAGE_BUTTON_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class ImageButton {

	SDL_Rect rect;
	bool isSelected;

	SDL_Texture *texture;
	SDL_Texture *selected;
	SDL_Renderer *renderer;

	public:

	ImageButton(SDL_Renderer *_renderer,const char* img_name, int w, int h) {
		renderer = _renderer;
		texture = IMG_LoadTexture(renderer, img_name);
		rect.w = w;
		rect.h = h;
	}

	void addSelected(const char *img_name) {
		if (renderer == 0) return;
		selected = IMG_LoadTexture(renderer, img_name);
	}

	void move(int nx, int ny) {
		rect.x = nx;
		rect.y = ny;
	}

	bool checkCursor(int curx, int cury) {
		if (curx > rect.x && curx < rect.x + rect.w
				&& cury > rect.y && cury < rect.y +rect.h
		   ) {
			if (!isSelected) {
				isSelected = true;
				return true;
			}
		} else {
			if (isSelected) {
				isSelected = false;
				return true;
			}
		}
		return false;
	}

	void show() {
		SDL_Texture *show = isSelected ? selected : texture;
		SDL_RenderCopy(renderer, show, 0, &rect);
	} 

	~ImageButton() {
		SDL_DestroyTexture(texture);
	}

};

#endif
