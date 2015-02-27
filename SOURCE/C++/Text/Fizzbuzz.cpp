/**
 * Fizz Buzz: Write a program that prints the numbers from 1 to 100. But for multiples of three print “Fizz” instead of the number and for the multiples of five print “Buzz”. For numbers which are multiples of both three and five print “FizzBuzz”.
 */
#include <iostream>
#include <string>

int main(){
	for(int i = 0; i < 100; i++) {
		std::string str = "";
		if (i%3) str += "Fizz";
		if (i%5) str += "Buzz";
		
		std::cout << str << "\n";
	}
}
