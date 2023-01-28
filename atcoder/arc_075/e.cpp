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
#include <atcoder/fenwicktree>

using namespace std;

int64_t solve(int64_t N, int64_t K, std::vector<int64_t> a) {
	int64_t ans = 0, sum = 0;
	map<int64_t, vector<int>> m;
	m[0].emplace_back(0);
	for (int i = 0; i < N; ++i) {
		sum += a[i] - K;
		m[sum].emplace_back(i + 1);
	}
	vector<int> seq(N + 1);
	int ord = 0;
	for (auto kv : m) {
		for (auto i : kv.second) {
			seq[i] = ord;
		}
		++ord;
	}
	atcoder::fenwick_tree<int> fw(N + 1);
	for (auto i : seq) {
		ans += fw.sum(0, i + 1);
		fw.add(i, 1);
	}
	return ans;
}

int main() {
	int64_t N, K;
	std::cin >> N >> K;
	std::vector<int64_t> a(N);
	for (int i = 0; i < N; i++) {
		std::cin >> a[i];
	}
	cout << solve(N, K, a) << endl;
	return 0;
}
