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

vector<int64_t> solve(int64_t N, std::vector<int64_t> lx, std::vector<int64_t> ly, std::vector<int64_t> rx, std::vector<int64_t> ry) {
	// imos
	vector<vector<int64_t>> tiles(1002, vector<int64_t>(1002));
	for (int64_t i = 0; i < N; ++i) {
		tiles[ly[i]][lx[i]] += 1;
		tiles[ly[i]][rx[i]] -= 1;
		tiles[ry[i]][lx[i]] -= 1;
		tiles[ry[i]][rx[i]] += 1;
	}
	for (int64_t y = 0; y <= 1000; ++y) {
		for (int64_t x = 1; x <= 1000; ++x) {
			tiles[y][x] += tiles[y][x - 1];
		}
	}
	for (int64_t y = 1; y <= 1000; ++y) {
		for (int64_t x = 0; x <= 1000; ++x) {
			tiles[y][x] += tiles[y - 1][x];
		}
	}
	vector<int64_t> ans(N);
	for (int64_t y = 0; y <= 1000; ++y) {
		for (int64_t x = 0; x <= 1000; ++x) {
			int64_t c = tiles[y][x];
			if (c > 0) {
				ans[c - 1] += 1;
			}
		}
	}
	return ans;
}

int main() {
	int64_t N;
	std::cin >> N;
	std::vector<int64_t> lx(N), ly(N), rx(N), ry(N);
	for (int i = 0; i < N; i++) {
		std::cin >> lx[i] >> ly[i] >> rx[i] >> ry[i];
	}
	for (auto x : solve(N, lx, ly, rx, ry)) {
		cout << x << endl;
	}
	return 0;
}
