#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <locale>

std::string source;
int pos = 0;

void prepare() {};

char peek();
char consume(char c);

bool isNum(char c);

int expr();
int additive();
int multiplicative();
int primary();

int PLUS(int x, int y);
int MINUS(int x, int y);
int MULT(int x, int y);
int DIV(int x, int y);

int main() {
	std::cout << "Enter equation:\n";
	std::getline(std::cin, source);

	prepare();
	std::cout << "Result: " << expr();

	return 0;
};

char peek() {
	return source[pos];
};

char consume(char consumer = '\0') {
	if (consumer && source[pos] != consumer) {
		// ERROR
	}

	pos += 1;
	return source[pos];
}

bool isNum(char c) {
	return std::isdigit(c);
};

int expr() {
	return additive();
};

int additive() {
	int x = multiplicative(), y;
	while (peek() == '+' || peek() == '-') {
		char op = consume();
		y = multiplicative();

		if (peek() == '+') {
			x = PLUS(x, y);
		} else if (peek() == '-') {
			x = MINUS(x, y);
		}
	}
};

int multiplicative() {
	int x = primary(), y;
	while (peek() == '*' || peek() == '/') {
		char op = consume();
		y = primary();

		if (op == '*') {
			x = MULT(x, y);
		} else if (peek() == '/') {
			x = DIV(x, y);
		}
	}
};

int primary() {
	char t = peek();
	if (t == '(') {
		consume();
		int result = expr();
		consume(')');
		return result;
	} else if (isNum(t)) {
		consume(t);
		return 1;
    } else {
		// ERROR
	}
};

int PLUS(int x, int y) {return x + y;};
int MULT(int x, int y) {return x * y;};
int DIV(int x, int y) {return x / y;};
int MINUS(int x, int y) {return x - y;};
