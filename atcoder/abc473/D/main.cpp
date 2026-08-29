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

int n, k;

vector<vector<int>> ans;
vector<int> seq;

void dfs(int pos, int sum) {
	if (pos == n - 1) {
		int r = k - sum;
		if ((r % n) == 0) {
			seq[pos] = r / n;
			ans.emplace_back(seq);
		}
	} else {
		for (int64_t i = 0; sum <= k; ++i) {
			seq[pos] = i;
			dfs(pos + 1, sum);
			sum += pos + 1;
		}
	}
}

vector<vector<int>> solve(int N, int K) {
	n = N;
	k = K;
	seq.resize(N);
	dfs(0, 0);
	// sort(ans.begin(), ans.end());
	return ans;
}

int main() {
	int N, K;
	cin >> N >> K;
	auto answers = solve(N, K);
	for (const auto ans : answers) {
		for (int64_t i = 0; i < N; ++i) {
			cout << (i ? " " : "") << ans[i];
		}
		cout << endl;
	}
}
