/**
 * Inverted Index (WIP): Implement the Inverted Index data structure.
 */
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>

const char* SEPERATOR = " 	\r\n.,!:;\'\"-()[]";

void filterDuplicates(std::vector<std::string> &v) {
	std::vector<std::string> vec(v);
	std::set<std::string> s( vec.begin(), vec.end() );
	vec.assign( s.begin(), s.end() );
	v = vec;
}

std::vector<std::string> splitWords(std::string str) {
	std::vector<std::string> vec;
	std::string word;

	char *c_str = new char [str.length()];
	std::strcpy(c_str, str.c_str());

	char *p = strtok(c_str, SEPERATOR);
	while (p) {
		vec.assign(p);
		p = strtok(NULL, SEPERATOR);
	}

	filterDuplicates(vec);
	return vec;
}

class InvertedIndex {
private:
	std::map<std::string, std::vector<int>> word_map;
	std::vector<std::string> texts;
public:
	InvertedIndex() {};
	
	void addText(std::string _text) {
		texts.assign(_text);
		int pos = texts.length();
		
		std::vector<std::string> words = splitWords(texts);
		for (auto const &i : words) {
			word_map[i];
		}
	};
};

int main() {
	InvertedIndex index;
	
	return 0;
}