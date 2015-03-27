/**
 * Check if Palindrome: Checks if the string entered by the user is a palindrome.
 */
#include <iostream>
#include <string>
#include <algorithm>

bool isPalindrome (std::string str) {
	std::string reversed(str);
	std::reverse(reversed.begin(), reversed.end());
	return reversed.length() && str == reversed;
};

int main(){
	std::string str;

	std::cout << "Enter string: ";
	std::getline(std::cin, str);

	if (isPalindrome(str)) std::cout << "\n" << str << " is a palindrome.";
	else std::cout << "\n" << str << " isn't a palindrome";
	
	return 0;
};
