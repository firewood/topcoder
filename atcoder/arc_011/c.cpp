#ifdef __GNUC__
#pragma GCC diagnostic ignored "-Wunused-result"
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#endif

#include <algorithm>
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

typedef long long LL;

void solve(std::string first, std::string last, int N, std::vector<std::string> &s) {
	int ans = -1;
	vector<string> words;
	vector<vector<string>> q(1, { first });
	vector<int> used(N + 1);
	s.emplace_back(last);
	if (first == last) {
		ans = 0;
		words = { first, last };
	}
	while (!q.empty() && ans < 0) {
		vector<vector<string>> nq;
		for (vector<string> a : q) {
			for (int j = 0; j <= N; ++j) {
				if (used[j]) continue;
				int cnt = 0;
				for (int k = 0; k < first.length(); ++k) {
					cnt += a.back()[k] != s[j][k];
				}
				if (cnt != 1) continue;
				used[j] = 1;
				nq.emplace_back(a);
				nq.back().emplace_back(s[j]);
				if (s[j] == last) {
					words = nq.back();
					ans = words.size() - 1;
					ans -= j == N;
				}
			}
		}
		q = nq;
	}
	cout << ans << endl;
	for (string a : words) {
		cout << a << endl;
	}
}

int main() {
	std::string first, last;
	std::cin >> first >> last;
	int N;
	std::cin >> N;
	std::vector<std::string> s(N);
	for (int i = 0; i < N; i++) {
		std::cin >> s[i];
	}
	solve(first, last, N, s);
	return 0;
}
