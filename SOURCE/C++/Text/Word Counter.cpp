/**
 * Word Counter: Counts the number of individual words in a string. Generates a summary of words to a CSV file.
 */
#include <iostream>
#include <map>
#include <string>
#include <cstring>

const char* SEPERATOR = " 	\r\n.,!:;\'\"-()[]";

std::map<std::string, int> countWords(std::string str) {
	std::map<std::string, int> map;
	std::string word;

	char *c_str = new char [str.length()];
	std::strcpy(c_str, str.c_str());

	char *p = strtok(c_str, SEPERATOR);
	while (p) {
		map[p]++;
		p = strtok(NULL, SEPERATOR);
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
