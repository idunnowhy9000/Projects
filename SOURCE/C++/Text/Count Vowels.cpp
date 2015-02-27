/**
 * Count Vowels: Enter a string and the program counts the number of vowels in the text.
 */
#include <iostream>
#include <string>
#include <algorithm>
#include <iterator>

int main(){
	std::string word;
	int vowelsCount = 0;
	std::string[5] vowels = {"a","e","i","o","u", "A", "E", "I", "O", "U"};
	
	std::cout << "Enter a word: ";
	std::getline(std::cin, word);
	
	for(std::string::size_type i = 0; i < word.size(); ++i) {
		if (std::find(std::begin(vowels), std::end(vowels), x) != std::end(vowels)) {
			vowelsCount++;
		}
	}
	
	std::cout << "\nWord \"" << word << "\"" << " has " << vowelsCount << " vowels.";
}
