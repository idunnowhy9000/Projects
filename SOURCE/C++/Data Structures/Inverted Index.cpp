/**
 * Inverted Index (WIP): Implement the Inverted Index data structure.
 */
#include <iostream>
#include <string>
#include <vector>
#include <map>

std::vector<std::string> &split(const std::string &s, char delim, std::vector<std::string> &elems) {
	std::stringstream ss(s);
	std::string item;
	while (std::getline(ss, item, delim)) {
		elems.push_back(item);
	}
	return elems;
};

std::vector<std::string> split(const std::string &s, char delim) {
	std::vector<std::string> elems;
	split(s, delim, elems);
	return elems;
};

class InvertedIndex {
private:
	std::map<std::string> word_map;
	std::vector<std::string> text;
public:
	InvertedIndex() {};
	InvertedIndex(std::map<std::string> a, std::vector<std::string>): word_map(text) {};
	
	void addText(std::string _text) {
		std::vector<std::string> words = split(_text, " ");
		
		text.push_back(_text);
		for (std::string i = words.begin(); i != words.end(); i++) {
			word_map[*i] = text.size();
		}
	};
};

int main() {
	InvertedIndex index;
	
	std::cout << "(Press Ctrl+C to exit)";
	
	while (true) {
		std::string text;
		
		std::cout << "\nEnter text to add: ";
		std::getline(std::cin, text);
		
		std::cout << "\nAdded text to database.";
	}
}