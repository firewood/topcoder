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

typedef pair<int, int> II;

const int INF = 1 << 30;

int solve(int N, std::vector<int> P, std::vector<int> Q) {
	vector<int> p(N + 1);
	for (int i = 0; i < N; ++i) {
		p[Q[i]] = i;
	}
	vector<int> dp(N, INF);
	for (int i = 0; i < N; ++i) {
		int a = P[i];
		vector<int> qpos;
		for (int b = a; b <= N; b += a) {
			qpos.emplace_back(p[b]);
		}
		sort(qpos.rbegin(), qpos.rend());
		for (auto j : qpos) {
			*lower_bound(dp.begin(), dp.end(), j) = j;
		}
	}
	return lower_bound(dp.begin(), dp.end(), INF) - dp.begin();
}

int main() {
	int N;
	std::cin >> N;
	std::vector<int> P(N);
	for (int i = 0; i < N; i++) {
		std::cin >> P[i];
	}
	std::vector<int> Q(N);
	for (int i = 0; i < N; i++) {
		std::cin >> Q[i];
	}
	cout << solve(N, P, Q) << endl;
	return 0;
}
