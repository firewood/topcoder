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
#include <unordered_map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
#include <atcoder/modint>

using namespace std;
const int64_t MOD = 998244353;
using mint = atcoder::modint998244353;

mint solve(int N, int M, vector<vector<int>> A) {
	mint ans = 0;
	unordered_map<int, unordered_map<int, int>> m;
	for (int64_t i = 0; i < N; ++i) {
		for (int64_t j = 0; j < M; ++j) {
			m[A[i][j]][i] += 1;
		}
	}
	for (const auto &kv1 : m) {
		mint x = 1;
		for (const auto &kv2 : kv1.second) {
			x *= (M - kv2.second);
		}
		ans += mint(M).pow(N) - x * mint(M).pow(N - kv1.second.size());
	}
	return ans;
}

int main() {
	int64_t N, M;
	cin >> N >> M;
	vector<vector<int>> A(N, vector<int>(M));
	for (int j = 0; j < N; ++j) {
		for (int i = 0; i < M; ++i) {
			cin >> A[j][i];
		}
	}
	auto ans = solve(N, M, A);
	cout << ans.val() << endl;
}
