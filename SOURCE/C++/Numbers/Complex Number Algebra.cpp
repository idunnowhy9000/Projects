/**
 * Complex Number Algebra: Show addition, multiplication, negation, and inversion of complex numbers in separate functions.
 */
#include <iostream>
#include <string>

class Complex {
private:
    float a, b;
public:
	Complex(float a, float b) : a(a), b(b) {};
    Complex() {
    	a = 0;
    	b = 0;
    };

    Complex operator+(const Complex& rhs) {
        return new Complex(a + rhs.a, b + rhs.b);
    };

    Complex operator-(const Complex& rhs) {
        return new Complex(a - rhs.a, b - rhs.b);
    };

    Complex operator

    std::string representation() {
    	if (b >= 0) {
			return std::to_string(a) + "+" + std::to_string(b) + "i";
    	} else {
    		return std::to_string(a) + "-" + std::to_string(b) + "i";
    	}
    };
};

int main() {
	return 0;
}
