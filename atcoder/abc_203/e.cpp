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

int64_t solve(int N, int M, std::vector<int> X, std::vector<int> Y) {
	map<int, set<int>> m;
	for (int i = 0; i < M; ++i) {
		m[X[i]].insert(Y[i]);
	}
	set<int> s;
	s.insert(N);
	for (auto kv : m) {
		map<int, int> nq;
		for (auto y : kv.second) {
			nq[y] = -1;
		}
		for (auto y : kv.second) {
			if (s.find(y - 1) != s.end() || s.find(y + 1) != s.end()) {
				nq[y] = 1;
			}
		}
		for (auto kv : nq) {
			if (kv.second > 0) {
				s.insert(kv.first);
			} else {
				s.erase(kv.first);
			}
		}
	}
	return s.size();
}

int main() {
	int N, M;
	std::cin >> N >> M;
	std::vector<int> X(M), Y(M);
	for (int i = 0; i < M; i++) {
		std::cin >> X[i] >> Y[i];
	}
	cout << solve(N, M, X, Y) << endl;
	return 0;
}
