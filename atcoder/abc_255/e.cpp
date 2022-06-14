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

int64_t solve(int64_t N, int64_t M, std::vector<int64_t> S, std::vector<int64_t> X) {
	int64_t ans = 0, a = 0;
	set<int64_t> s(X.begin(), X.end());
	map<int64_t, int64_t> m[2];
	for (int i = 0; i < N; ++i) {
		m[i % 2][a] += 1;
		a = S[i] - a;
	}
	for (int mi = 0; mi < 2; ++mi) {
		for (auto kv : m[mi]) {
			for (int i = 0; i < M; ++i) {
				int64_t cnt = 0, d = X[i] - kv.first;
				for (int j = 0; j < M; ++j) {
					for (int k = 0; k < 2; ++k) {
						auto it = m[mi ^ k].find(X[j] + (k * 2 - 1) * d);
						if (it != m[mi ^ k].end()) {
							cnt += it->second;
						}
					}
				}
				ans = max(ans, cnt);
			}
		}
	}
	return ans;
}

int main() {
	int64_t N, M;
	std::cin >> N >> M;
	std::vector<int64_t> S(N-1);
	for (int i = 0; i < N-1; i++) {
		std::cin >> S[i];
	}
	std::vector<int64_t> X(M);
	for (int i = 0; i < M; i++) {
		std::cin >> X[i];
	}
	cout << solve(N, M, S, X) << endl;
	return 0;
}
