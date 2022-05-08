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

int64_t solve(int64_t N, int64_t X, std::vector<int64_t> A) {
	priority_queue<II, vector<II>, greater<>> qh;
	map<int64_t, int64_t> ml;
	for (int i = 0; i < N; ++i) {
		qh.push({ A[i], A[i] });
		ml[A[i]] += 1;
	}
	int64_t ans = ml.rbegin()->first - ml.begin()->first, ng = 0;
	while (ng <= N && ml.rbegin()->first <= 1e18) {
		int64_t high = qh.top().first, low = qh.top().second;
		qh.pop();
		qh.push({ high * 2 + X, low * 2 });
		ml[low] -= 1;
		if (ml[low] <= 0) {
			ml.erase(low);
		}
		ml[low * 2] += 1;
		int64_t d = max(int64_t(0), ml.rbegin()->first - qh.top().first);
		if (d > ans) {
			++ng;
		} else {
			ans = d;
			ng = 0;
		}
	}
	return ans;
}

int main() {
	int64_t N, X;
	std::cin >> N >> X;
	std::vector<int64_t> A(N);
	for (int i = 0; i < N; i++) {
		std::cin >> A[i];
	}
	cout << solve(N, X, A) << endl;
	return 0;
}
