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
const string WIN = "Alice";
const string LOSE = "Bob";

typedef pair<int, int> II;

int n;
vector<int> a;
map<II, int> memo;

bool dfs(int left, int offset) {
	II key(left, offset);
	if (memo.find(key) != memo.end()) {
		return memo[key];
	}
	int &r = memo[key];
	if (left < n) {
		int d = a[left] - offset;
		if (d <= 0) {
			int cnt = 0;
			while (left + cnt < n && a[left + cnt] == offset) {
				++cnt;
			}
			if (cnt >= 2 && !dfs(left + cnt - 1, offset)) r = 1;
			if (!dfs(left + cnt, offset)) r = 1;
		} else {
			if (d >= 2 && !dfs(left, offset + d - 1)) r = 1;
			if (!dfs(left, offset + d)) r = 1;
		}
	}
	return r;
}

bool solve(int N, vector<int> &A) {
	bool ans = false;
	n = N;
	a = A;
	sort(a.begin(), a.end());
	memo.clear();
	return dfs(0, 0);
}

void process_case() {
	int N;
	cin >> N;
	vector<int> A(N);
	for (int64_t i = 0; i < N; ++i) {
		cin >> A[i];
	}
	auto ans = solve(N, A);
	cout << (ans ? WIN : LOSE) << endl;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		process_case();
	}
}
