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

typedef pair<int64_t, int64_t> II;

static const int64_t INF = 1LL << 60;

void solve(int64_t N, std::vector<int64_t> L, std::vector<int64_t> R) {
	vector<II> v;
	for (int i = 0; i < N; ++i) {
		v.emplace_back(II(L[i], R[i]));
	}
	v.emplace_back(II(INF, INF));
	sort(v.begin(), v.end());
	int64_t st = v[0].first, ed = st;
	for (auto x : v) {
		if (ed < x.first) {
			cout << st << " " << ed << endl;
			st = x.first;
		}
		ed = max(ed, x.second);
	}
}

int main() {
	int64_t N;
	std::cin >> N;
	std::vector<int64_t> L(N), R(N);
	for (int i = 0; i < N; i++) {
		std::cin >> L[i] >> R[i];
	}
	solve(N, L, R);
	return 0;
}
