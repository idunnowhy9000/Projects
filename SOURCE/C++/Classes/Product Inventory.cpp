/**
 * Product Inventory: Create an application which manages an inventory of products.
 */
#include <iostream>
#include <string>
#include <vector>

class Product {
private:
	float price;
	int id;
	int quantity;
	std::string name;
public:
	Product(int a, std::string b, float c, int d) : id(a), name(b), price(c), quantity(d) {};

	float get_price() {return price;};
	int get_id() {return id;};
	int get_quantity() {return quantity;};
	std::string get_name() {return name;};

	void add(int count = 1) {
		quantity += count;
	};

	void remove(int count = 1) {
		quantity -= count;
	};

	void setPrice(float value) {
		price = value;
	};
};

class Inventory {
private:
	std::vector<Product> items;
public:
	Inventory() {};
	Inventory(std::vector<Product> a): items(a) {};

	void add(Product item) {
		items.push_back(item);
	};

	float getTotalPrice() {
		float sum = 0;
		for (int i = 0; i < items.size(); i++) {
			sum += items[i].get_price() * items[i].get_quantity();
		}

		return sum;
	};

	int size() {
		return items.size();
	};
};

int main() {
	Inventory inventory;
	Product apple(0, "Apple", 1.15, 1);
	Product orange(0, "Orange", 1.3, 1);

	inventory.add(apple);
	inventory.add(orange);
	std::cout << inventory.size() << " item(s) in inventory.\n";
	std::cout << "Costs a total of " << inventory.getTotalPrice() << ".\n";
}
