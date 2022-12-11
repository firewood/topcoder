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

int dfs(int b, const vector<int>& a) {
	if (!b) return 0;
	vector<int> p, q;
	for (int x : a) {
		if (x & b) {
			p.emplace_back(x);
		} else {
			q.emplace_back(x);
		}
	}
	if (p.empty()) {
		return dfs(b >> 1, q);
	} else if (q.empty()) {
		return dfs(b >> 1, p);
	} else {
		return min(dfs(b >> 1, q), dfs(b >> 1, p)) | b;
	}
}

int solve(int N, std::vector<int> a) {
	return dfs(1 << 29, a);
}

int main() {
	int N;
	std::cin >> N;
	std::vector<int> a(N);
	for (int i = 0; i < N; i++) {
		std::cin >> a[i];
	}
	cout << solve(N, a) << endl;
	return 0;
}
