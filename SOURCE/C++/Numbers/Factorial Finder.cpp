/**
 * Factorial Finder: The Factorial of a positive integer, n, 
 * is defined as the product of the sequence n, n-1, n-2, ...1 and the factorial of zero, 0, is defined as being 1.
 * 
 * (TIL Looped factorials are better than recursion)
 */
#include <iostream>

int recursionFactorial(int n) {
	return ((n < 1) ? n : factorial(n)) * n;
}

int loopFactorial (int n) {
	int factor = 1;
	for (int i = 0; i <= n; i++) {
		factor *= i;
	}
	return factor;
}

int main() {
	std::string str_x;
	int x;

	std::cout << "Factorial up to: ";
	std::getline(std::cin, str_x);

	x = std::stoi(str_x);

	std::cout << "\nUsing loops:\n";
	loopedFact(x);

	std::cout << "\n\nUsing recursion:\n";
	recursionFact(x);
	return 0;
}