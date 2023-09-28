#include <string.h>

class Paths {

	private: 
		static Paths *paths;

		char *root;
		const char *assets;
		const int size = 128;

		Paths() {
			assets = "assets/";
		}

	public: 
		
		static Paths *instance() {
			if (paths == 0) {
				paths = new Paths();
			}
			return paths;
		}

		const char *asset(const char *name) const {
			char *buf = new char[size];
			strcpy(buf, assets);
			strcat(buf, name);
			return buf;


		}

};
