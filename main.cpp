#include <iostream>
#include "cache.hpp"

using namespace std;

int main() {
	cache* c = new cache(10, FIFO);
	
	c->insert(1, 10102);
	c->insert(3, 13324);
	
	cout << c->get(3) << "\n";
}
