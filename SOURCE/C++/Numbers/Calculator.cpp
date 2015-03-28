#include <iostream>
#include <string>
#include <ctype.h>
#include <cstdlib>
#include <stdexcept>

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
		return std::isdigit(ch);
	};

	bool eof () {
		return (unsigned int)pos >= source.length();
	};

	char consume(char ch) {
		if (peek() != ch) {
			throw std::runtime_error("Expected " + ch);
		}
		return source[pos++];
	};

	char consume() {
		return source[pos++];
	};

	void consumeWhitespace() {
		while (!eof()) {
			if ( peek() == ' ' || peek() == '	' || peek() == '\n' || peek() == '\r' ) {
				pos++;
			} else {
				break;
			}
		}
	};

	// Parser
	float parseAdditive() {
		float first = parseMultiplicative(), next;
		char op;

		consumeWhitespace();

		while (peek() == '+' || peek() == '-') {
			op = consume();
			consumeWhitespace();

			next = parseMultiplicative();

			if (op == '+') first = first + next;
			if (op == '-') first = first - next;

			consumeWhitespace();
		}
		return first;
	};

	float parseMultiplicative() {
		float first = parsePrimary(), next;
		char op;

		consumeWhitespace();

		while (peek() == '*' || peek() == '/') {
			op = consume();
			consumeWhitespace();

			next = parsePrimary();

			if (op == '*') first = first * next;
			if (op == '/') first = first / next;

			consumeWhitespace();
		}

		return first;
	};

	float parsePrimary() {
		if (peek() == '(') {
			consume();

			consumeWhitespace();

			int expr = parseExpression();

			consumeWhitespace();

			consume(')');
			return expr;
		} else if (isNumber(peek())) {
			return parseNum();
		} else {
			throw std::runtime_error("Unexpected token.");
		}

		return 0;
	};

	float parseNum() {
		std::string source;
		float value;

		while (!eof()) {
			if (isNumber(peek())) {
				source += this->source[pos++];
			} else {
				break;
			}
		}

		if (peek() == '.') {
			source += consume();
			while (!eof()) {
				if (isNumber(peek())) {
					source += consume();
				} else {
					break;
				}
			}
		}

		value = atof(source.c_str());
		return value;
	};

	float parseExpression() {
		return parseAdditive();
	};
};

int main() {
	std::string source;

	std::cout << "Enter equation: ";
	std::getline(std::cin, source);

	Calculator calc(source);
	std::cout << "Result: " << calc.parseExpression();

	return 0;
};
