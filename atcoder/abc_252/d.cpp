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

int64_t solve(int64_t N, std::vector<int64_t> A) {
	int64_t ans = N * (N - 1) * (N - 2) / (3 * 2);
	map< int64_t, int64_t> m;
	for (int i = 0; i < N; ++i) {
		m[A[i]] += 1;
	}
	for (auto kv : m) {
		int64_t cnt = kv.second;
		ans -= cnt * (cnt - 1) / 2 * (N - cnt);
		ans -= cnt * (cnt - 1) * (cnt - 2) / 6;
	}
	return ans;
}

int64_t solve2(int64_t N, std::vector<int64_t> A) {
	int64_t ans = 0;
	for (int i = 0; i < N; ++i) {
		for (int j = i + 1; j < N; ++j) {
			for (int k = j + 1; k < N; ++k) {
				if (A[i] != A[j] && A[j] != A[k] && A[k] != A[i]) {
					++ans;
				}
			}
		}
	}
	return ans;
}

int main() {
	int64_t N;
	std::cin >> N;
	std::vector<int64_t> A(N);
	for (int i = 0; i < N; i++) {
		std::cin >> A[i];
	}
//	cerr << solve2(N, A) << endl;
	cout << solve(N, A) << endl;
	return 0;
}
