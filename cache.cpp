#include "cache.hpp"

cache::cache(int size, eviction_policy type) {
	cache_size = size;
	cache_type = type;
}

void cache::insert(int key, int value) {
	if(store.size() < cache_size) {
		store.insert(make_pair(key, value));
	} else {
		cache::evict();
		store.insert(make_pair(key, value));
	}
}

int cache::get(int key) {
	if(store.find(key) != store.end())
		return store[key];
	else
		return -1;
}

// TODO: Implement evict
void cache::evict() {
	switch(cache_type) {
		case FIFO:
			store.erase(store.begin());
			break;
		case LIFO:
			store.erase(store.begin());
			break;
		case LRU:
			store.erase(store.begin());
			break;
		case CUSTOM:
			store.erase(store.begin());
			break;
	}
}