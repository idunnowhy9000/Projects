#include <iostream>
#include <string>

unsigned long long squareExponent(int x, int n) {
	unsigned long long result = 1;
	while (n != 0) {
		if (n % 2 == 1) {
			result *= x;
			n--;
		}
		x *= x;
		n = n / 2;
	}
	return result;
};

int main() {
	std::string x_str, y_str;
	int x, y;

	std::cout << "Enter number x: ";
	std::getline(std::cin, x_str);

	std::cout << "Enter base y: ";
	std::getline(std::cin, y_str);

	x = std::stoi(x_str);
	y = std::stoi(y_str);

	std::cout << "Exponent: " << squareExponent(x, y);

	return 0;
};
