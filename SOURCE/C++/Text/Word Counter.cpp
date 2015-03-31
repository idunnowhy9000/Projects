/**
 * Word Counter: Counts the number of individual words in a string. Generates a summary of words to a CSV file.
 */
#include <iostream>
#include <map>
#include <string>
#include <fstream>

bool isspace(char ch) {
	return ch == ' ' || ch == '	' || ch == '\r' || ch == '\n';
};

std::map<std::string, int> countWords(std::string str) {
	std::map<std::string, int> map;
	std::string word;
	unsigned int i = 0;

	for (; i < str.length(); i++) {
		if (isspace(str[i]) || str[i] == '\0') {
			map[word]++;
			word = "";
		} else {
			word += str[i];
		}
	}
	if (i == str.length()) {
		map[word]++; // final word
	}

	return map;
};

std::string mapToCSV(std::map<std::string, int> m) {
	std::string out;
	for (auto const &it : m) {
		out += it.first + "," + std::to_string(it.second) + "\n";
	}
	return out;
};

int main(int argc, char *argv[]) {
	if (argc < 2 || argc > 3) {
		std::cout << "Usage:\n";
		std::cout << "	'Word Counter' <arg>\n";
		std::cout << "		<argv>: Words to map to CSV.\n\n";

		std::cout << "Examples:\n";
		std::cout << "	'Word Counter' \"Hello World\" > words.csv\n";
		std::cout << "	cat file.txt | 'Word Counter' > words.csv\n";

		return 0;
	}

	std::string str = argv[1];
	std::cout << mapToCSV(countWords(str));

	return 0;
};
