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

vector<int> solve(const int Q, const vector<int>& t, const vector<int> &x) {
	vector<int> ans;
	map<int, int> key_count_map;
	set<int> doubles;
	map<int, set<int>> value_key_map;

	auto get_next_key = [&](int x) {
		auto it = key_count_map.lower_bound(x + 1);
		if (it == key_count_map.end()) {
			return -1;
		}
		return it->first;
	};

	auto calc = [&](int x) {
		auto it = key_count_map.find(x);
		if (x < 0 || it == key_count_map.begin()) {
			return -1;
		}
		--it;
		return x ^ it->first;
	};

	auto remove = [&](int x) {
		int value = calc(x);
		if (value >= 0) {
			value_key_map[value].erase(x);
			if (value_key_map[value].empty()) {
				value_key_map.erase(value);
			}
		}
	};

	auto add = [&](int x) {
		int value = calc(x);
		if (value >= 0) {
			value_key_map[value].insert(x);
		}
	};

	for (int i = 0; i < Q; ++i) {
		int key = x[i], next_key = get_next_key(key);
		switch (t[i]) {
		case 1:
			remove(next_key);
			key_count_map[key] += 1;
			if (key_count_map[key] == 2) {
				doubles.insert(key);
			}
			add(key);
			add(next_key);
			break;
		case 2:
			key_count_map[key] -= 1;
			if (key_count_map[key] == 0) {
				remove(next_key);
				remove(key);
				key_count_map.erase(key);
				add(next_key);
			} else if (key_count_map[key] == 1) {
				doubles.erase(key);
			}
			break;
		case 3:
			ans.emplace_back(doubles.empty() ? value_key_map.begin()->first : 0);
			break;
		}
	}
	return ans;
}

int main() {
	int Q;
	cin >> Q;
	vector<int> t(Q), x(Q);
	for (int i = 0; i < Q; ++i) {
		cin >> t[i];
		if (t[i] != 3) {
			cin >> x[i];
		}
	}
	for (auto ans : solve(Q, t, x)) {
		cout << ans << endl;
	}
	return 0;
}
