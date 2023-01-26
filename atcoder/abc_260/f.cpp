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

void solve(int S, int T, int M, std::vector<int> u, std::vector<int> v) {
	vector<vector<int>> edges(T);
	for (int i = 0; i < M; ++i) {
		edges[v[i] - S].emplace_back(u[i]);
	}
	vector<int> f(S, -1);
	for (int i = 0; i < T; ++i) {
		for (auto n : edges[i]) {
			f[n] = i;
		}
		for (int j = i + 1; j < T; ++j) {
			int tn = -1;
			for (auto n : edges[j]) {
				if (f[n] == i) {
					if (tn < 0) {
						tn = n;
					} else {
						cout << (tn + 1) << " " << (n + 1) << " " << (S + i + 1) << " " << (S + j + 1) << endl;
						return;
					}
				}
			}
		}
	}
	cout << -1 << endl;
}

int main() {
	int S, T, M;
	std::cin >> S >> T >> M;
	std::vector<int> u(M), v(M);
	for (int i = 0; i < M; i++) {
		std::cin >> u[i] >> v[i];
		--u[i]; --v[i];
	}
	solve(S, T, M, u, v);
	return 0;
}
