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

bool solve(int N, int M, vector<vector<int>> a) {
	int r = N;
	vector<int> used(N + 1, -1);
	vector<int> ai(M);
	vector<int> q;
	for (int i = 0; i < M; ++i) {
		q.emplace_back(i);
	}
	while (!q.empty()) {
		int i = q.back();
		q.pop_back();
		if (ai[i] >= a[i].size()) continue;
		int color = a[i][ai[i]++];
		if (used[color] >= 0) {
			--r;
			q.emplace_back(i);
			q.emplace_back(used[color]);
		} else {
			used[color] = i;
		}
	}
	return r == 0;
}

int main() {
	int N, M, K;
	cin >> N >> M;
	std::vector<vector<int>> a(M);
	for (int i = 0; i < M; i++) {
		cin >> K;
		a[i].resize(K);
		for (int j = 0; j < K; ++j) {
			cin >> a[i][j];
		}
	}
	bool ans = solve(N, M, a);
	cout << (ans ? "Yes" : "No") << endl;
	return 0;
}
