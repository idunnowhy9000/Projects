/**
 * Pig Latin: Form a "Pig Latin"-ified word from a regular word.
 */
#include <iostream>
#include <string>

std::string pigLatin(std::string str) {
	std::string pig(str);

	if (pig == "a" || pig == "e" || pig == "i" || pig == "o" || pig == "u") {
		pig += "way";
	} else {
		pig += str.substr(0, 1) + "ay";
		pig.erase(0, 1);
	}
	
	return pig;
};

int main(){
	std::string str;

	std::cout << "Enter string: ";
	std::getline(std::cin, str);

	std::cout << "\nPigified \"" << str << "\": " << pigLatin(str);
	return 0;
}
