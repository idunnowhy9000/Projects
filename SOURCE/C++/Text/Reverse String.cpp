#include <iostream>
#include <algorithm>
#include <string>

int main() {
	std::string str;
	
	std::cout << "Enter a string to be reversed: ";
	std::getline(std::cin, str);
	
	std::cout << "\nReversed string: ";
	std::reverse(str.begin(), str.end());
	std::cout << str << "\n";
	
	return 0;
}