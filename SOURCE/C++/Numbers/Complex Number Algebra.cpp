/**
 * Complex Number Algebra: Show addition, multiplication, negation, and inversion of complex numbers in separate functions.
 */
#include <iostream>
#include <string>
#include <cmath>

class Complex {
public:
	float a; // real
	float b; // imaginary
	
	Complex(float a, float b) : a(a), b(b) {};
    Complex() {
    	a = 0;
    	b = 0;
    };

    Complex operator+(const Complex& rhs) {
    	Complex c;
    	c.a = a + rhs.a;
    	c.b = b + rhs.b;
        return c;
    };

    Complex operator-(const Complex& rhs) {
        Complex c;
    	c.a = a - rhs.a;
    	c.b = b - rhs.b;
        return c;
    };

    Complex operator*(const Complex& rhs) {
		Complex c;
    	c.a = a * rhs.a;
    	c.b = b * rhs.b;
        return c;
	};

    Complex operator/(const Complex& rhs) {
		Complex c;
    	c.a = a / rhs.a;
    	c.b = b / rhs.b;
        return c;
	};

	Complex inverse() {
		float n = sqrt(a * a + b * b);
		Complex c;
		c.a = a / n;
		c.b = b / n;
		return c;
	};

    std::string representation() {
    	if (b >= 0) {
			return std::to_string(a) + "+" + std::to_string(b) + "i";
    	} else {
    		return std::to_string(a) + "-" + std::to_string(b) + "i";
    	}
    };
};

int main() {
	Complex a, b;

	std::cout << "Enter 1st number: ";
	std::cin >> a.a >> a.b;

	std::cout << "Enter 2nd number: ";
	std::cin >> b.a >> b.b;

	std::cout << "1st number: " << a.representation() << "\n2nd number: " << b.representation() << "\n";
	std::cout << a.representation() << " + " << b.representation() << " = " << (a + b).representation() << "\n";
	std::cout << a.representation() << " - " << b.representation() << " = " << (a - b).representation() << "\n";
	std::cout << a.representation() << " * " << b.representation() << " = " << (a * b).representation() << "\n";
	std::cout << a.representation() << " / " << b.representation() << " = " << (a / b).representation() << "\n";
	
	std::cout << "1st number's inverse: " << a.inverse().representation() << "\n";
	std::cout << "2nd number's inverse: " << b.inverse().representation() << "\n";

	return 0;
}
