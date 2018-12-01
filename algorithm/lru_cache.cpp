#include <iostream>
#include <queue>
#include <unordered_map>
#include <cstdio>
#include <cstring>
#include <cassert>

using namespace std;

struct Node {
	int prev;
	int next;
	int key;
	int value;
};

class LRUCache {
	int top;
	int tail;
	vector<Node> nodes;
	deque<int> pool;
	unordered_map<int, int> key_to_index;
public:
	LRUCache(int capacity) {
		top = -1;
		tail = -1;
		nodes.resize(capacity);
		for (int i = 0; i < capacity; ++i) {
			pool.push_back(i);
		}
	}

	int get(int key) {
		if (key_to_index.find(key) == key_to_index.end()) {
			return -1;
		}
		int index = key_to_index[key];
		int value = nodes[index].value;
		put(key, value);
		return value;
	}

	void put(int key, int value) {
		if (key_to_index.find(key) != key_to_index.end()) {
			remove(key_to_index[key]);
		}
		if (pool.empty()) {
			remove(top);
		}
		int index = pool.back();
		pool.pop_back();
		if (tail >= 0) {
			nodes[tail].next = index;
		} else {
			top = index;
		}
		nodes[index].prev = tail;
		nodes[index].next = -1;
		nodes[index].key = key;
		nodes[index].value = value;
		tail = index;
		key_to_index[key] = index;
	}

	void remove(int index) {
		assert(index >= 0);
		key_to_index.erase(nodes[index].key);
		int prev = nodes[index].prev, next = nodes[index].next;
		if (prev >= 0) {
			nodes[prev].next = next;
		} else {
			top = next;
		}
		if (next >= 0) {
			nodes[next].prev = prev;
		} else {
			tail = prev;
		}
		pool.push_back(index);
	}
};

int main(int argc, char *argv[])
{
	LRUCache cache(2 /* capacity */);

	cache.put(1, 1);
	cache.put(2, 2);
	assert(cache.get(1) == 1);       // returns 1
	cache.put(3, 3);    // evicts key 2
	assert(cache.get(2) == -1);       // returns -1 (not found)
	cache.put(4, 4);    // evicts key 1
	assert(cache.get(1) == -1);       // returns -1 (not found)
	assert(cache.get(3) == 3);       // returns 3
	assert(cache.get(4) == 4);       // returns 4

	return 0;
}
