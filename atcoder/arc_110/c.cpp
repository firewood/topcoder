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

bool solve(long long N, std::vector<long long> &P) {
	map<int, int> m;
	vector<int> ops;
	vector<int> used(N);
	for (int i = 0; i < N; ++i) {
		m[P[i]] = i;
	}
	for (int i = 0; i < N; ++i) {
		int pos = m[i];
		while (pos > i) {
			int prev = P[pos - 1];
			swap(P[pos - 1], P[pos]);
			m[i] = pos - 1;
			m[prev] = pos;
			--pos;
			used[pos] += 1;
			if (used[pos] > 1) return false;
			ops.emplace_back(pos + 1);
		}
		while (pos < i) {
			int next = P[pos + 1];
			swap(P[pos], P[pos + 1]);
			m[i] = pos + 1;
			m[next] = pos;
			++pos;
			if (used[pos] > 1) return false;
			ops.emplace_back(pos + 1);
		}
	}
	for (int i = 0; i < N - 1; ++i) {
		if (used[i] != 1) {
			return false;
		}
	}
	for (auto x : ops) {
		cout << x << endl;
	}
	return true;
}

int main() {
    long long N;
	std::cin >> N;
	std::vector<long long> P(N);
	for (int i = 0; i < N; i++) {
		std::cin >> P[i]; P[i]--;
	}
	if (!solve(N, P)) {
		cout << "-1" << endl;
	}
	return 0;
}
