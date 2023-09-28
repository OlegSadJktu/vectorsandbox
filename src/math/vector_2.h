#ifndef VECTOR_2_H
#define VECTOR_2_H

#include <math.h>

class Vector2 {

	private:

		double x, y;
		int pow() const;

	public:

		Vector2(int _x = 0, int _y = 0); 

		Vector2(const Vector2& vec) ;
		int getX() ;
		int getY() ;
		double length() const ;
		bool operator<(const Vector2 &other) const ;
		bool operator>(const Vector2 &other) const ;
		Vector2 operator+(const Vector2 &other) const ;
		Vector2 operator-(const Vector2 &other) const ;
		Vector2 operator*(int a) const ;
		Vector2 operator/(int a) const ;
		bool operator==(const Vector2 &other) const ;
		Vector2 nor() const ;
		bool intersect(const Vector2 &other, double rad) const ;

};

#endif
