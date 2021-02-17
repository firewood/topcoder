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

void solve(int N, std::vector<long long> &a) {
	a.emplace_back(0);
	vector<LL> ans(N);
	vector<int> seq(N + 1);
	iota(seq.begin(), seq.end(), 0);
	sort(seq.begin(), seq.end(), [&](int lhs, int rhs) {
		return make_pair(-a[lhs], -lhs) < make_pair(-a[rhs], -rhs);
	});

	int index = N;
	for (int i = 0; i < N; i++) {
		index = min(index, seq[i]);
		ans[index] += (a[seq[i]] - a[seq[i + 1]]) * (i + 1);
	}
	for (auto x : ans) {
		cout << x << endl;
	}
}

int main() {
    int N;
	std::cin >> N;
	std::vector<long long> a(N);
	for (int i = 0; i < N; i++) {
		std::cin >> a[i];
	}
	solve(N, a);
	return 0;
}
