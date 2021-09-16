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

typedef pair<int64_t, int64_t> II;
typedef pair<int64_t, II> III;

int64_t solve(int64_t R, int64_t C, std::vector<std::vector<int64_t>> A, std::vector<std::vector<int64_t>> B) {
	vector <vector<int64_t>> min_costs(R, vector<int64_t>(C, 1LL << 60));
	priority_queue<III, vector<III>, greater<>> q;
	min_costs[0][0] = 0;
	q.emplace(III(0, II(0, 0)));
	while (!q.empty()) {
		auto top = q.top();
		q.pop();
		int64_t cost = top.first, r = top.second.first, c = top.second.second;
		if (cost > min_costs[r][c]) continue;
		auto check = [&](int64_t r, int64_t c, int64_t additioal_cost) {
			int64_t next_cost = cost + additioal_cost;
			if (next_cost < min_costs[r][c]) {
				min_costs[r][c] = next_cost;
				q.emplace(III(next_cost, II(r, c)));
			}
		};
		if (c < C - 1) check(r, c + 1, A[r][c]);
		if (c > 0) check(r, c - 1, A[r][c - 1]);
		if (r < R - 1) check(r + 1, c, B[r][c]);
		for (int i = 1; i <= r; ++i) {
			check(r - i, c, 1 + i);
		}
	}
	return min_costs[R - 1][C - 1];
}

int main() {
	int64_t R, C;
	std::cin >> R >> C;
	std::vector<std::vector<int64_t>> A(R, std::vector<int64_t>(C-1));
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C-1; j++) {
			std::cin >> A[i][j];
		}
	}
	std::vector<std::vector<int64_t>> B(R-1, std::vector<int64_t>(C));
	for (int i = 0; i < R-1; i++) {
		for (int j = 0; j < C; j++) {
			std::cin >> B[i][j];
		}
	}
	cout << solve(R, C, A, B) << endl;
	return 0;
}
