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
const int64_t INF = 1LL << 60;
vector<vector<II>> memo(3002, vector<II>(3002, { INF, INF }));
vector<int64_t> a;

II &dfs(int left, int right) {
	II &r = memo[left][right];
	if (r.first == INF) {
		if (left >= right) {
			r = { 0, 0 };
		} else if (left + 1 == right) {
			r = { a[left], 0 };
		} else {
			II &p = dfs(left + 1, right), &q = dfs(left, right - 1);
			II x(a[left] + p.second, p.first), y(a[right - 1] + q.second, q.first);
			r = ((x.first - x.second) >= (y.first - y.second)) ? x : y;
		}
	}
	return r;
}

II solve(int N, std::vector<int64_t> &A) {
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
	auto ans = solve(N, A);
	cout << ans.first << " " << ans.second << endl;
}
