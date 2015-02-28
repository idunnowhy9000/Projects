/**
 * Word Counter (WIP): Counts the number of individual words in a string. Generates a summary of words to a CSV file.
 */
#include <iostream>
#include <vector>
#include <string>
#include <fstream>

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

std::map<std::string, int> countWords(std::string str) {
	std::map<std::string, int> map;
	std::vector<std::string> words = split(str, " ");
	
	for (std::string i = words.begin(); i != words.end(); i++) {
		map[*i]++;
	}
	
	return map;
}

std::string mapToCSV(std::map<std::string, int> map) {
	return map;
}

int main() {
	std::string str, file;
	
	std::cout << "Enter string: ";
	std::getline(std::cin, str);
	
	std::map<std::string, int> words = countWords(str);
	
	std::cout << "\nEnter file to write to: ";
	std::getline(std::cin, file);
	
	std::fstream fs;
	fs.open(file, std::fstream::in | std::fstream::out | std::fstream::app);
	
	fs << mapToCSV(words);
	
	fs.close();
}