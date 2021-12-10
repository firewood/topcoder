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

typedef long double LD;
typedef pair<int64_t, int64_t> II;
typedef pair<int64_t, II> III;

static const int64_t INF = 1LL << 60;

vector<int> solve(int N, std::vector<int> s, int64_t Q, std::vector<int> k) {
	map<int, int> m;
	int i, c = 0;
	for (i = 0; i < N; ++i) {
		if (s[i] > 0) {
			m[s[i]] += 1;
		}
	}
	vector<int> cnt(N + 2, 1 << 30), score(N + 2), ans(Q);
	cnt[0] = 0;
	i = 0;
	for (auto it = m.rbegin(); it != m.rend(); ++it) {
		++i;
		c += it->second;
		cnt[i] = c;
		score[i] = it->first;
	}
	for (int i = 0; i < Q; ++i) {
		if (c <= k[i]) continue;
		int pos = lower_bound(cnt.begin(), cnt.end(), k[i]) - cnt.begin();
		if (cnt[pos] == k[i]) {
			++pos;
		}
		ans[i] = score[pos] + 1;
	}
	return ans;
}

int main() {
	int N, Q;
	std::cin >> N;
	std::vector<int> s(N);
	for (int i = 0; i < N; i++) {
		std::cin >> s[i];
	}
	std::cin >> Q;
	std::vector<int> k(Q);
	for (int i = 0; i < Q; i++) {
		std::cin >> k[i];
	}
	vector<int> ans = solve(N, s, Q, k);
	for (int i = 0; i < ans.size(); ++i) {
		cout << ans[i] << endl;
	}
	return 0;
}
