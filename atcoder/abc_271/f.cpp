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

int64_t solve(int N, std::vector<std::vector<int>> a) {
	vector<map<int, int64_t>> fwd_map(N + 1), rev_map(N + 1);
	for (int b = 0; b < (1 << (N - 1)); ++b) {
		int y = 0, x = 0, v = a[0][0], ry = N - 1, rx = N - 1, rv = 0;
		for (int i = 0; i < N - 1; ++i) {
			rv ^= a[ry][rx];
			if (b & (1LL << i)) {
				y += 1;
				ry -= 1;
			} else {
				x += 1;
				rx -= 1;
			}
			v ^= a[y][x];
		}
		fwd_map[x][v] += 1;
		rev_map[rx][rv] += 1;
	}
	int64_t ans = 0;
	for (int i = 0; i < N; ++i) {
		for (auto kv : fwd_map[i]) {
			ans += kv.second * rev_map[i][kv.first];
		}
	}
	return ans;
}

int main() {
	int N;
	std::cin >> N;
	std::vector<std::vector<int>> a(N, std::vector<int>(N));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			std::cin >> a[i][j];
		}
	}
	cout << solve(N, a) << endl;
	return 0;
}
