#include <iostream>
#include <string>
#include <ctype.h>

class Calculator {
private:
	std::string source;
	int pos;
public:
	Calculator(std::string s) {
		source = s;
		pos = 0;
	};
	
	// Utilities
	char peek() {
		return source[pos];
	};
	
	bool isNumber (char ch) {
		return isdigit(ch);
	};
	
	bool eof () {
		return pos > source.length();
	};
	
	// Parser
	int parseAdditive() {
		
	};
	
	int parseMultiplicative() {
		
	};
	
	int parsePrimary() {
		if (peek() == "(") {
			int expr = parse();
			consume(')');
			return expr;
		} else if (isNumber(peek())) {
			return parseNum();
		} else {
			throw "Unexpected token.";
		}
	};
	
	int parseNum() {
		std::string source;
		int value;
		
		while (!eof()) {
			if (isNumber(peek())) {
				source += source[pos++];
			}
		}
		
		value = atoi(source.c_str());
		return value;
	};
	
	int parse() {
		return parseAdditive();
	};
};

int main() {
	std::string source;
	
	std::cout << "Enter equation:\n";
	std::getline(std::cin, source);

	Calculator calc(source);

	return 0;
};