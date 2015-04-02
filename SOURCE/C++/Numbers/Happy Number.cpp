/**
 * Happy Numbers (WIP): A happy number is defined by the following process.
 * Starting with any positive integer, replace the number by the sum of the squares of its digits, and repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1.
 * Those numbers for which this process ends in 1 are happy numbers, while those that do not end in 1 are unhappy numbers. Display an example of your output here. Find first 8 happy numbers.
 */

#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
#include <map>

std::map<char, int> initMap() {
	std::map<char, int> m;
	std::string n = "0123456789";
    for (unsigned int i = 0; i < n.length(); i++) {
		m[n[i]] = pow(stoi(std::string(1, n[i])), 2);
    }
    return m;
};
std::map<char, int> SQUARE = initMap();
bool isHappy(int n) {
    std::string s;
	while ((n > 1) && (n != 4)) {
		s = std::to_string(n);
		n = 0;
		for (unsigned int i = 0; i < s.length(); i++) {
            n += SQUARE[s[i]];
		}
	}
	return n == 1;
};

int main () {
	std::cout << "Happy numbers until 100:\n";
    for (int i = 0; i < 100; i++) {
        if (isHappy(i)) {
			std::cout << i << " / ";
        }
    }

	return 0;
};
