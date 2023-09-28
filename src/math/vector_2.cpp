#include "vector_2.h"

#include <map>



int Vector2::pow() const {
	return x*x + y*y;
}

Vector2::Vector2(int _x, int _y) {
	x = _x;
	y = _y;
}

Vector2::Vector2(const Vector2& vec) {
	x = vec.x;
	y = vec.y;
}

int Vector2::getX() {return x;}
int Vector2::getY() {return y;}

double Vector2::length() const {
	return sqrt(pow());
}

bool Vector2::operator<(const Vector2 &other) const {
	return pow() < other.pow();
}

bool Vector2::operator>(const Vector2 &other) const {
	return pow() > other.pow();
}

Vector2 Vector2::operator+(const Vector2 &other) const {
	return Vector2(x + other.x, y + other.y);
}

Vector2 Vector2::operator-(const Vector2 &other) const {
	return Vector2(x - other.x, y - other.y);
}

Vector2 Vector2::operator*(int a) const {
	return Vector2(x * a, y * a);
}

Vector2 Vector2::operator/(int a) const {
	return Vector2(x / a, y / a);
}

bool Vector2::operator==(const Vector2 &other) const {
	return x == other.x && y == other.y;
}

Vector2 Vector2::nor() const {
	return *this / length();
}

bool Vector2::intersect(const Vector2 &other, double rad) const {
	if (rad == 0) {
		return *this == other;
	}
	Vector2 res = *this - other;
	if (res.length() < rad) {
		return true;
	}
	return false;
}


