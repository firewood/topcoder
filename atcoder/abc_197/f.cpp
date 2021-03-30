#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstring>
#include <iostream>
#include <sstream>
#include <numeric>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <vector>

using namespace std;

typedef pair<int, int> II;
inline II make_key(int a, int b) {
	return make_pair(min(a, b), max(a, b));
}

int solve(int N, int M, std::vector<int> &A, std::vector<int> &B, std::vector<char> &C) {
	vector<vector<int>> v(26);
	for (int i = 0; i < M; i++) {
		v[C[i] - 'a'].emplace_back(i);
	}
	map<II, set<II>> m;
	set<II> adj;
	for (int ch = 0; ch < 26; ++ch) {
		for (int i = 0; i < v[ch].size(); ++i) {
			int a = A[v[ch][i]], c = B[v[ch][i]];
			adj.emplace(make_key(a, c));
			for (int j = i + 1; j < v[ch].size(); ++j) {
				int b = A[v[ch][j]], d = B[v[ch][j]];
				m[make_key(a, b)].insert(make_key(c, d));
				m[make_key(a, d)].insert(make_key(b, c));
				m[make_key(b, c)].insert(make_key(a, d));
				m[make_key(c, d)].insert(make_key(a, b));
			}
		}
	}
	set<II> q;
	q.emplace(II(0, N - 1));
	for (int i = 0; i < M && !q.empty(); ++i) {
		set<II> nq;
		for (auto x : q) {
			if (adj.find(x) != adj.end()) {
				return i * 2 + 1;
			}
			for (auto y : m[x]) {
				if (y.first == y.second) {
					return (i + 1) * 2;
				}
				nq.insert(y);
			}
		}
		q = nq;
	}
	return -1;
}

int main() {
    int N, M;
	std::cin >> N >> M;
	std::vector<int> A(M), B(M);
	std::vector<char> C(M);
	for (int i = 0; i < M; i++) {
		std::cin >> A[i] >> B[i] >> C[i];
		--A[i], --B[i];
	}
	cout << solve(N, M, A, B, C) << endl;
	return 0;
}
