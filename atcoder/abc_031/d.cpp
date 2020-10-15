#ifdef __GNUC__
#pragma GCC diagnostic ignored "-Wunused-result"
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#endif

#include <algorithm>
#include <cmath>
#include <cstring>
#include <cctype>
#include <iostream>
#include <sstream>
#include <numeric>
#include <map>
#include <set>
#include <queue>
#include <vector>

using namespace std;

void solve(int K, int N, std::vector<string> &v, std::vector<string> &w) {
	vector<int> digits(K, 1);
	while (true) {
		vector<string> ans(K);
		int i;
		for (i = 0; i < N; ++i) {
			int pos = 0;
			for (char c : v[i]) {
				int d = c - '1';
				for (int j = 0; j < digits[d]; ++j) {
					if (pos >= w[i].length()) {
						goto next;
					}
					if (ans[d].length() <= j) {
						ans[d] += w[i][pos++];
					} else if (ans[d][j] != w[i][pos++]) {
						goto next;
					}
				}
			}
			if (pos != w[i].length()) {
				goto next;
			}
		}
		for (auto x : ans) {
			cout << x << endl;
		}
		return;
next:
		for (i = 0; i < K; ++i) {
			digits[i] += 1;
			if (digits[i] <= 3) break;
			digits[i] = 1;
		}
		if (i >= K) break;
	}
}

int main() {
	int K, N;
	std::cin >> K >> N;
	std::vector<string> v(N), w(N);
	for (int i = 0; i < N; i++) {
		std::cin >> v[i] >> w[i];
	}
	solve(K, N, v, w);
	return 0;
}
