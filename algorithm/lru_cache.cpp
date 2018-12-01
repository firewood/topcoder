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
	int used;
	vector<Node> nodes;
	deque<int> pool;
	unordered_map<int, int> m;
public:
	LRUCache(int capacity) {
		top = -1;
		tail = -1;
		used = 0;
		nodes.resize(capacity);
		for (int i = 0; i < capacity; ++i) {
			pool.push_back(i);
		}
	}

	int get(int key) {
		if (m.find(key) == m.end()) {
			return -1;
		}
		int index = m[key];
		int value = nodes[index].value;
		put(key, value);
		return value;
	}

	void put(int key, int value) {
		if (m.find(key) != m.end()) {
			remove(m[key]);
		}
		if (used >= nodes.size()) {
			remove(top);
		}
		int n = pool.back();
		pool.pop_back();
		if (tail >= 0) {
			nodes[tail].next = n;
		} else {
			top = n;
		}
		nodes[n].prev = tail;
		nodes[n].next = -1;
		nodes[n].key = key;
		nodes[n].value = value;
		tail = n;
		++used;
		m[key] = n;
	}

	void remove(int index) {
		if (index < 0) {
			return;
		}
		m.erase(nodes[index].key);
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
		--used;
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
