#include "cache.hpp"
#include <string>
#include <iostream>

cache::cache(int size, eviction_policy type) {
	cache_size = size;
	cache_type = type;
	time_stamp = 0;
}

void cache::insert(int key, string value) {
	if(store.find(key) != store.end()) {
		// if key already present in cache, then update its value
		if(store[key].second != value)
			store[key].second = value;
			store[key].first = time_stamp++;
		return;
	}
	if(store.size() < cache_size) {
		store.insert(make_pair(key, make_pair(time_stamp++, value)));
	} else {
		cache::evict();
		store.insert(make_pair(key, make_pair(time_stamp++, value)));
	}
}

string cache::get(int key) {
	if(store.find(key) != store.end()) {
		if(cache_type == LRU) // Update TimeStamp if cache is LRU
			store[key].first = time_stamp++;
		return store[key].second;
	}
	else
		return "KEY_NOT_FOUND";
}

void cache::print() {
	for(auto it: store) {
		cout << "Key: " << it.first << " TimeStamp: " << it.second.first << " Value: " << it.second.second << "\n";
	}
}

void cache::evict() {
	if(cache_type == FIFO or cache_type == LRU) {
		int min_ts = (store.begin()->second).first;
		int key = store.begin()->first;
		for(auto it: store) {
			int ts = it.second.first;
			if(ts < min_ts) {
				key = it.first;
				min_ts = ts;
			}		
		}
		store.erase(key);
	} else if(cache_type == LIFO) {
		int max_ts = (store.begin()->second).first;
		int key = store.begin()->first;
		for(auto it: store) {
			int ts = it.second.first;
			if(ts > max_ts) {
				key = it.first;
				max_ts = ts;
			}		
		}
		store.erase(key);
	} else if(cache_type == CUSTOM) {

	}
}