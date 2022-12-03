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

vector<int> solve(int N, int M, std::vector<int> A) {
	vector<int> ans(M, -1);
	vector<vector<int>> p(N);
	for (int i = 0; i < N; ++i) {
		p[i].emplace_back(i);
	}
	for (int i = 0; i < M; ++i) {
		swap(p[A[i] - 1], p[A[i]]);
		if (p[A[i]][0] == 0) {
			p[A[i] - 1].emplace_back(i);
		}
		if (p[A[i] - 1][0] == 0) {
			p[A[i]].emplace_back(i);
		}
	}
	int default_pos = -1;
	for (int i = 0; i < N; ++i) {
		if (p[i][0] == 0) {
			default_pos = i;
		}
		for (int j = 1; j < p[i].size(); ++j) {
			ans[p[i][j]] = i;
		}
	}
	for (int i = 0; i < M; ++i) {
		if (ans[i] < 0) {
			ans[i] = default_pos;
		}
	}
	return ans;
}

int main() {
	int N, M;
	std::cin >> N >> M;
	std::vector<int> A(M);
	for (int i = 0; i < M; i++) {
		std::cin >> A[i];
	}
	vector<int> ans = solve(N, M, A);
	for (size_t i = 0; i < ans.size(); ++i) {
		cout << (ans[i] + 1) << endl;
	}
	return 0;
}
