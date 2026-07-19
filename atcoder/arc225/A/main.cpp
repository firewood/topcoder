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

vector<vector<int64_t>> solve(int64_t N, vector<vector<int64_t>> X) {
	vector<vector<int64_t>> ans(N, vector<int64_t>(N));
	int64_t table[5] = {0, 2, 4, 1, 3};
	for (int64_t i = 0; i < N; ++i) {
		for (int64_t j = 0; j < N; ++j) {
			ans[i][j] = table[X[i][j]];
		}
	}
	return ans;
}

int main() {
	int64_t N;
	cin >> N;
	vector<vector<int64_t>> X(N, vector<int64_t>(N));
	for (int64_t i = 0; i < N; ++i) {
		for (int64_t j = 0; j < N; ++j) {
			cin >> X[i][j];
		}
	}
	auto answers = solve(N, X);
	for (const auto &ans : answers) {
		for (int64_t i = 0; i < N; ++i) {
			cout << (i ? " " : "") << ans[i];
		}
		cout << endl;
	}
}
