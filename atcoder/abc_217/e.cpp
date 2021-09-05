#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstring>
#include <iostream>
#include <sstream>
#include <numeric>
#include <map>
#include <set>
#include <queue>
#include <vector>

using namespace std;

int main() {
	int Q, t, x, top = -1;
	cin >> Q;
	priority_queue<int, vector<int>, greater<int>> sorted_pool;
	deque<int> unsorted_pool;
	for (int i = 0; i < Q; i++) {
		cin >> t;
		if (t == 1) {
			cin >> x;
			unsorted_pool.push_back(x);
		} else if (t == 2) {
			if (!sorted_pool.empty()) {
				top = sorted_pool.top();
				sorted_pool.pop();
			} else if (!unsorted_pool.empty()) {
				top = unsorted_pool.front();
				unsorted_pool.pop_front();
			}
			cout << top << endl;
		} else {
			while (!unsorted_pool.empty()) {
				sorted_pool.emplace(unsorted_pool.front());
				unsorted_pool.pop_front();
			}
		}
	}
	return 0;
}
