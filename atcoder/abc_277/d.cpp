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
#include <atcoder/modint>

using namespace std;

int64_t solve(int64_t N, int64_t M, std::vector<int64_t> A) {
	int64_t total = accumulate(A.begin(), A.end(), int64_t(0)), ans = total;
	map<int64_t, int64_t> m;
	for (int i = 0; i < N; ++i) {
		m[A[i]] += 1;
	}
	bool found = false;
	for (auto kv : m) {
		if (m.find((kv.first + 1) % M) == m.end()) {
			found = true;
			int64_t remain = total;
			for (int i = 0; i < M; ++i) {
				int64_t y = (kv.first - i + M) % M;
				auto it = m.find(y);
				if (it == m.end()) {
					break;
				}
				remain -= y * it->second;
			}
			ans = min(ans, remain);
		}
	}
	return found ? ans : 0;
}

int main() {
	int64_t N, M;
	std::cin >> N >> M;
	std::vector<int64_t> A(N);
	for (int i = 0; i < N; i++) {
		std::cin >> A[i];
	}
	cout << solve(N, M, A) << endl;
	return 0;
}
