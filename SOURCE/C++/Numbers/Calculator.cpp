/**
 * Calculator: A simple calculator to do basic operators.
 * Make it a scientific calculator for added complexity.
 *
 * Whitespace is ignored by the parser.
 * EBNF Grammar of Calculator:

Expression
	= Additive;

Additive
	= Multiplicative, { ( '+' | '-' ), Multiplicative };

Multiplicative
	= Primary, { ( '+' | '-' ), Primary };

Primary
	= Number | ( '-', Expression ) | ( '(', Expression, ')' ) | Function;

Function
	= (Variable, '()') | (Variable, '(', Arguments, ')');

Arguments
	= Expression, {',', Expression};

Number = { DecimalDigit }, ['.', { DecimalDigit }];

Variable = Letter, { Letter | DecimalDigit };

DecimalDigit = '0' | ... | '9';

Letter = 'a' | ... | 'z' | 'A' | ... | 'z';

 */
#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>
#include <vector>

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
		return 48 <= ch && ch <= 57;
	};

	bool isLetter (char ch) {
		return (97 <= ch && ch <= 122) || (65 <= ch && ch <= 90);
	};

	bool eof () {
		return pos >= (int)source.length();
	};

	char consume(char ch) {
		if (peek() != ch) {
			std::cout << "Expected " << ch << ".\n";
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

			if (op == '+') first += next;
			if (op == '-') first -= next;

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

			if (op == '*') first *= next;
			if (op == '/') first /= next;

			consumeWhitespace();
		}

		return first;
	};

	float parsePrimary() {
		char p = peek();
		if (isNumber(p)) { // Numbers
			return parseNum();
		} else if (p == '-') { // Negative numbers
			consume();
			return -parseExpression();
		} else if (p == '(') { // Enclosed primaries
			consume();

			consumeWhitespace();

			float expr = parseExpression();

			consumeWhitespace();

			consume(')');
			return expr;
		} else if (isLetter(p)) { // Variables
			std::string var_name;
			var_name += consume();

			while (!eof()) {
				if (isLetter(peek()) || isNumber(peek())) {
					var_name += consume();
				} else {
					break;
				}
			}

			if (peek() == '(') { // functions
				return parseFunction(var_name);
			}
		}

		return 0;
	};

	float parseFunction(std::string var_name) {
		std::vector<float> arguments;

		consumeWhitespace();
		consume('(');
		
		consumeWhitespace();
		
		if (peek() == ')') {
			consume();
		} else { // arguments
			arguments.push_back(parseExpression());
			consumeWhitespace();

			if (peek() != ')') {
				while (peek() == ',') {
					consume();
					consumeWhitespace();

					arguments.push_back(parseExpression());

					consumeWhitespace();
				}
			}

			consumeWhitespace();
			consume(')');
		}

		if (var_name == "cos") {
			return cos(arguments.front());
		} else if (var_name == "sin") {
			return sin(arguments.front());
		} else if (var_name == "tan") {
			return tan(arguments.front());
		} else if (var_name == "acos") {
			return acos(arguments.front());
		} else if (var_name == "asin") {
			return asin(arguments.front());
		} else if (var_name == "atan") {
			return atan(arguments.front());
		} else if (var_name == "atan2") {
			float a2 = arguments.back();
			arguments.pop_back();

			float a1 = arguments.back();
			arguments.pop_back();

			return atan2(a1, a2);
		} else if (var_name == "cosh") {
			return cosh(arguments.front());
		} else if (var_name == "sinh") {
			return sinh(arguments.front());
		} else if (var_name == "tanh") {
			return tanh(arguments.front());
		} else if (var_name == "acosh") {
			return acosh(arguments.front());
		} else if (var_name == "asinh") {
			return asinh(arguments.front());
		} else if (var_name == "atanh") {
			return atanh(arguments.front());
		} else if (var_name == "exp") {
			return exp(arguments.front());
		} else if (var_name == "log") {
			return log(arguments.front());
		} else if (var_name == "log10") {
			return log10(arguments.front());
		} else if (var_name == "pow") {
			float a2 = arguments.back();
			arguments.pop_back();

			float a1 = arguments.back();
			arguments.pop_back();

			return pow(a1, a2);
		} else if (var_name == "sqrt") {
			return sqrt(arguments.front());
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
