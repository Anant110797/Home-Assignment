#ifndef CACHE_H
#define CACHE_H

#include <map>
#include <string>
using namespace std;

enum eviction_policy {
	FIFO, 
	LIFO, 
	LRU, 
	CUSTOM,
};

class cache {
	public:
		// Default constructor
		cache();

		// Constructor
		cache(int size, eviction_policy type);

		// Destructor
		~cache();

		// Function to insert (key, value) pair in cache
		void insert(int key, string value);

		// Function to get value corresponding to key from cache
		string get(int key);

	private:
		int cache_size;
		eviction_policy cache_type;
		map <int, string> store;

		// Eviction function
		void evict();
};

#endif