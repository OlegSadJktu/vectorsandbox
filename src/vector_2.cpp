#ifndef VECTOR_2_H
#define VECTOR_2_H

#include <math.h>

class Vector2 {

		int x, y;

	private:

		int pow() const {
			return x*x + y*y;
		}

	public:
		Vector2(int _x = 0, int _y = 0) {
			x = _x;
			y = _y;
		}

		Vector2(const Vector2& vec) {
			x = vec.x;
			y = vec.y;
		}

		int getX() {return x;}
		int getY() {return y;}

		double length() const {
			return sqrt(x*x + y*y);
		}

		bool operator<(const Vector2 &other) {
			return pow() < other.pow();
		}

		Vector2 operator+(const Vector2 &other) {
			return Vector2(x + other.x, y + other.y);
		}

		bool intersect(const Vector2 &other, double rad = 0) const {
			return 0;
		}

};

#endif
