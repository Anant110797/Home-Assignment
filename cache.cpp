#include "cache.hpp"
#include <string>

cache::cache(int size, eviction_policy type) {
	cache_size = size;
	cache_type = type;
}

void cache::insert(int key, string value) {
	if(store.size() < cache_size) {
		store.insert(make_pair(key, value));
	} else {
		cache::evict();
		store.insert(make_pair(key, value));
	}
}

string cache::get(int key) {
	if(store.find(key) != store.end())
		return store[key];
	else
		return "";
}

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