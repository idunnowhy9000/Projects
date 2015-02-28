/**
 * Coin Flip Simulation: Write some code that simulates flipping a single coin however many times the user decides.
 */
#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>

int heads = 0, tails = 0;

void flip (int count) {
	heads = 0;
	tails = 0;
	
	for (int i = 0; i < count; i++) {
		if (rand() % 2 == 0) heads++;
		else tails++;
	}
}

int main() {
	srand(time(NULL));
	
	int coinflip;
	std::string str_coinflip;
	
	std::cout << "Enter coin flip times: ";
	std::getline(std::cin, str_coinflip);
	
	coinflip = atoi(str_coinflip.c_str());
	
	flip(coinflip);
	
	std::cout << "\nFlipped " << heads << " heads, " << tails << " tails.";
	std::cout << "\nTotal of " << (heads + tails) << " times.";
}