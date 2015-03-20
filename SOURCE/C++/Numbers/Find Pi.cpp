/**
 * Pi Finder: Enter a number and have the program generate PI up to that many decimal places.
 */
#include <iostream>
#include <cmath>
#include <stdlib.h>
#include <string>
#include <cstdlib>
#include <iomanip>

float piFind(int len) {
	float pi;
	for (int k = 0; k < len; k++) {
		pi += pow(-1, k) / (2 * k + 1);
	}
	pi *= 4;
	
	return pi;
}

int main(){
	std::string str_x;
	int x;

	std::cout << "Enter length: ";
	std::getline(std::cin, str_x);

	x = atoi(str_x.c_str());

	std::cout << "\nPi calculated:\n";
	std::cout << std::fixed << std::setprecision(a) << piFind(x);
}
