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

typedef long long LL;
typedef pair<LL, LL> II;

bool solve(long long N, std::vector<long long> &a, std::vector<long long> &b, std::vector<long long> &p) {
	map<int, int> owner;
	vector<int> seq(N);
	iota(seq.begin(), seq.end(), 0);
	sort(seq.begin(), seq.end(), [&](int lhs, int rhs) {
		return a[lhs] < a[rhs];
	});
	for (int i = 0; i < N; ++i) {
		if (p[i] != i && a[i] <= b[p[i]]) {
			return false;
		}
		owner[p[i]] = i;
	}
	vector<II> ans;
	for (int i = 0; i < N; ++i) {
		int j = seq[i];
		if (owner[j] == j) continue;
		int target = owner[j];
		ans.emplace_back(II(j + 1, target + 1));
		owner[p[j]] = target;
		owner[j] = j;
		swap(p[j], p[target]);
	}
	cout << ans.size() << endl;
	for (auto kv : ans) {
		cout << kv.first << " " << kv.second << endl;
	}
	return true;
}

int main() {
    long long N;
	std::cin >> N;
	std::vector<long long> a(N), b(N), p(N);
	for (int i = 0; i < N; i++) {
		std::cin >> a[i];
	}
	for (int i = 0; i < N; i++) {
		std::cin >> b[i];
	}
	for (int i = 0; i < N; i++) {
		std::cin >> p[i]; p[i]--;
	}
	if (!solve(N, a, b, p)) {
		cout << -1 << endl;
	}
	return 0;
}
