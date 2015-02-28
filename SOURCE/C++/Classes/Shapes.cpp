#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
#include <vector>

class Shape {
public:
	Shape() {};
	
	float area() {
		return 0;
	};
	
	float perimeter() {
		return 0;
	};
};

class Circle : public Shape {
private:
	float _radius;
public:
	Circle(float r): _radius(r) {};
	
	float radius() {
		return _radius;
	};
	
	float area() {
		return M_PI * _radius * _radius;
	};
	
	float perimeter() {
		return 2 * M_PI * _radius;
	};
};

class Rectangle : public Shape {
private:
	float _width, _height;
public:
	Rectangle(float w, float h): _width(w), _height(h) {};
	
	float width() {
		return _width;
	};
	
	float height() {
		return _height;
	};
	
	float area() {
		return _width * _height;
	};
	
	float perimeter() {
		return 2 * (_width + _height);
	};
};

class Triangle : public Shape {
private:
	float _side_a, _side_b, _side_c;
public:
	Triangle(float a, float b, float c): _side_a(a), _side_b(b), _side_c(c) {};
	
	std::vector<float> getSides() {
		std::vector<float> sides;
		sides.push_back(_side_a);
		sides.push_back(_side_b);
		sides.push_back(_side_c);
		
		return sides;
	};
	
	float area() {
		s = (_side_a + _side_b + _side_c);
		return sqrt(s * (s - _side_a) * (s - _side_b) * (s - _side_c));
	};
	
	float perimeter() {
		return _side_a + _side_b + _side_c;
	};
}

int main() {
	return 0;
}