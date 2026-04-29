#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <deque>
#include <fstream>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>

using namespace std;

int64_t solve(int64_t N, int64_t K, std::vector<int64_t> A) {
	map<int64_t, int64_t> m;
	for (int i = 0; i < N; ++i) {
		m[A[i]] += 1;
	}
	vector<int64_t> v;
	for (const auto& kv : m) {
		v.emplace_back(kv.first * kv.second);
	}
	sort(v.begin(), v.end());
	int64_t sz = max(int64_t(0), int64_t(v.size()) - K);
	return accumulate(v.begin(), v.begin() + sz, int64_t(0));
}

int main() {
	int64_t N, K;
	std::cin >> N >> K;
	std::vector<int64_t> A(N);
	for (int64_t i = 0; i < N; ++i) {
		std::cin >> A[i];
	}
	auto ans = solve(N, K, std::move(A));
	cout << ans << endl;
}
