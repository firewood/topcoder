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
typedef pair<int64_t, int64_t> II;
map<II, II> memo;
vector<int64_t> a;

II dfs(int left, int right) {
	if (left >= right) {
		return { 0, 0 };
	}
	if (left + 1 == right) {
		return { a[left], 0 };
	}
	II key(left, right);
	if (memo.find(key) != memo.end()) {
		return memo[key];
	}
	II p = dfs(left + 1, right), q = dfs(left, right - 1);
	II x(a[left] + p.second, p.first), y(a[right - 1] + q.second, q.first);
	II r = ((x.first - x.second) > (y.first - y.second)) ? x : y;
	memo[key] = r;
	return r;
}

II solve(int N, std::vector<int64_t> A) {
	a = A;
	return dfs(0, N);
}

int main() {
	int N;
	std::cin >> N;
	std::vector<int64_t> A(N);
	for (int64_t i = 0; i < N; ++i) {
		std::cin >> A[i];
	}
	auto ans = solve(N, std::move(A));
	cout << ans.first << " " << ans.second << endl;
}
