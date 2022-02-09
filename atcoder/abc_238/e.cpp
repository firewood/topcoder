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

int N;

map<int, vector<int>> ml, mr;
vector<int> memo;

int dfs(int x) {
	int& r = memo[x];
	if (r >= 0) {
		return r;
	}
	r = 0;
	for (auto y : ml[x]) {
		if (y == N) {
			r = 1;
			return r;
		}
		for (auto z : mr[y]) {
			r = dfs(z);
			if (r > 0) {
				return r;
			}
		}
		if (ml.find(y + 1) != ml.end()) {
			r = dfs(y + 1);
			if (r > 0) {
				return r;
			}
		}
	}
	if (mr.find(x - 1) != mr.end()) {
		for (auto z : mr[x - 1]) {
			r = dfs(z);
			if (r > 0) {
				return r;
			}
		}
	}
	return r;
}

int main() {
	int Q, l, r;
	cin >> N >> Q;
	memo = vector<int>(N + 1, -1);
	for (int i = 0; i < Q; ++i) {
		cin >> l >> r;
		ml[l].emplace_back(r);
		mr[r].emplace_back(l);
	}
	cout << (dfs(1) ? "Yes" : "No") << endl;
	return 0;
}
