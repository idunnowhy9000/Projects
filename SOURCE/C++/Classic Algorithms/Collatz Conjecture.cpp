#include <iostream>
#include <vector>
#include <cstdlib>
#include <utility>
#include <string>

std::pair<int, std::vector<int>> collatz(int n) {
	if (n < 1) throw "Number must be more than 1";
	
	std::vector<int> seq;
	int j = 0;
	while (n > 1) {
		if (n % 2 == 0) {
			n /= 2;
			j++;
		} else {
			n = 3 * n + 1;
			j++;
		}
		seq.push_back(n);
	}
	
	std::pair<int, std::vector<int>> returnValue;
	std::get<0>(returnValue) = j;
	std::get<1>(returnValue) = seq;
	return returnValue;
};

int main() {
	std::string str;
	int n;

	std::cout << "Enter number: ";
	std::getline(std::cin, str);

	n = atoi(str.c_str());
	
	std::pair<int, std::vector<int>> extract = collatz(n);
	int j = std::get<0>(extract);
	std::vector<int> seq = std::get<1>(extract);
	
	std::cout << "Number " << str << " takes " << j << " steps.\n";
	std::cout << "Sequence: ";
	for (unsigned int i = 0; i < seq.size(); i++) {
		std::cout << seq[i] << " ";
	}

	return 0;
};
