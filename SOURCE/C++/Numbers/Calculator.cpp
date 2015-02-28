#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>

/**
 * Token Classes:
 * Represents a token
 */
class Token {
private:
	std::string source, type;
};

/**
 * OPToken:
 * Represents an operator token
 */
class OPToken: public Token {
public:
	OPToken(std::string s): source(s), type("OP") {};
}

/**
 * NumToken:
 * Represents an number token
 */
class NumToken: public Token {
private:
	int source, type;
public:
	NumToken(std::string s) {
		source = atoi(s.c_str());
		type = "NUM";
	};
}

/**
 * Lexer Class:
 * Lexes a string of source and returns a vector of tokens
 */
class Lexer {
private:
	std::string source;
	std::vector
public:
	Lexer(std::string s): source(s) {};
	
	void parse() {
		
	};
};

/**
 * Parser Class:
 * Uses the Shunting-yard algorithm to parse a stream of tokens.
 */
class Parser {
	
};

/**
 * ReversePolish Class:
 * Parses a Token stream
 */
class ReversePolish {
private:
	std::vector<Token> input_tokens;
	int pos;
	
	std::vector<int> stack;
	int result;
public:
	ReversePolish(std::vector<Token> t): input_tokens(t) {};
	
	void parse() {
		while (pos < input_tokens.size()) {
			Token cur_token = input_tokens.at(pos++);
			
			if (cur_token.type == "NUM") {
				stack.push_back(cur_token.source);
			} else {
				int arg2 = stack.back();
				stack.pop_back();
				int arg1 = stack.back();
				stack.pop_back();
				
				if (cur_token.source == "+") {
					stack.push_back(arg1 + arg2);
				} else if (cur_token.source == "-") {
					stack.push_back(arg1 - arg2);
				} else if (cur_token.source == "/") {
					stack.push_back(arg1 / arg2);
				} else if (cur_token.source == "*") {
					stack.push_back(arg1 * arg2);
				} else {
					std::cerr << "Error: Unknown operator \"" << cur_token.source << "\"\n";
				}
			}
		}
		
		if (stack.size() == 1) {
			result = stack.back();
		} else {
			std::cerr << "User input has too many values.\n";
		}
	};
};

int main() {
	
	ReversePolish rpolish;
}