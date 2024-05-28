#include <iostream>
#include "cache.hpp"

using namespace std;

int main() {
	cache* c = new cache(10, FIFO);
	
	c->insert(1, "Hello");
	c->insert(3, "World");
	
	cout << c->get(3) << "\n";
}
