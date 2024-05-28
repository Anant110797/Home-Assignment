#include <iostream>
#include "cache.hpp"

using namespace std;

int main() {
	cache* c = new cache(4, LRU);
	
	c->insert(12, "Hello");
	c->insert(24, "World");
	
	c->insert(35, "This");
	c->insert(42, "is");
	c->insert(35, "(update) This");

	c->print();
	
	c->insert(54, "my");
	c->insert(65, "home");
	c->insert(76, "assignment");
	
	cout << c->get(35) << "\n";
	cout << c->get(12) << "\n";

	c->insert(12, "Hello");

	cout << c->get(12) << "\n";

	c->print();
}
