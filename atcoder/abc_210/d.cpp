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

static const int64_t INF = 1LL << 60;

int64_t solve(int64_t H, int64_t W, int64_t C, std::vector<std::vector<int64_t>> A) {
	auto calc = [&]() -> int64_t {
		int64_t min_cost = INF;
		vector<vector<int64_t>> left2right(H, vector<int64_t>(W)), top2bottom(H, vector<int64_t>(W));
		for (int y = 0; y < H; y++) {
			int64_t lp = 0;
			for (int x = 0; x < W; ++x) {
				int64_t xpos = x == 0 ? -1 : left2right[y][x - 1];
				int64_t ypos = y == 0 ? -1 : top2bottom[y - 1][x];
				if (x > 0) {
					min_cost = min(min_cost, A[y][x] + A[y][xpos] + C * (x - xpos));
					if (y > 0) {
						min_cost = min(min_cost, A[ypos][x] + A[y][xpos] + C * (y - ypos + x - xpos));
					}
					if (A[y][x] <= A[y][xpos] + C * (x - xpos)) {
						xpos = x;
					}
					left2right[y][x] = xpos;
				}
				if (y > 0) {
					min_cost = min(min_cost, A[y][x] + A[ypos][x] + C * (y - ypos));
					if (A[y][x] <= A[ypos][x] + C * (y - ypos)) {
						ypos = y;
					}
					top2bottom[y][x] = ypos;
				}

			}
		}
		return min_cost;
	};
	int64_t ans = calc();
	for (auto& a : A) {
		reverse(a.begin(), a.end());
	}
	return min(ans, calc());
}

int main() {
	int64_t H, W, C;
	std::cin >> H >> W >> C;
	std::vector<std::vector<int64_t>> A(H, std::vector<int64_t>(W));
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			std::cin >> A[i][j];
		}
	}
	cout << solve(H, W, C, std::move(A)) << endl;
	return 0;
}
