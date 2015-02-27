/**
 * Tile Cost: Find Cost of Tile to Cover W x H Floor
 */
#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>

float calcCost (float cost, float width, float height) {
	return cost*width*height;
}

int main() {
	float width;
	std::string str_width;
	float height;
	std::string str_height;
	float cost;
	std::string str_cost;
	float total;

	std::cout << "Cost per tile: ";
	std::getline(std::cin, str_cost);

	cost = std::atof(str_cost.c_str());

	std::cout << "Width of room: ";
	std::getline(std::cin, str_width);

	width = std::atof(str_width.c_str());

	std::cout << "Height of room: ";
	std::getline(std::cin, str_height);

	height = std::atof(str_height.c_str());

	total = calcCost(cost, width, height);

	std::cout << "Total cost of tiling is " << "$" << (int)round(total);
}
