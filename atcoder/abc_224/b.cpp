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

bool solve(int64_t H, int64_t W, std::vector<std::vector<int64_t>> A) {
	for (int i1 = 0; i1 < H; ++i1) {
		for (int i2 = i1 + 1; i2 < H; ++i2) {
			for (int j1 = 0; j1 < W; ++j1) {
				for (int j2 = j1 + 1; j2 < W; ++j2) {
					if (A[i1][j1] + A[i2][j2] > A[i2][j1] + A[i1][j2]) {
						return false;
					}
				}
			}
		}
	}
	return true;
}

int main() {
	int64_t H, W;
	std::cin >> H >> W;
	std::vector<std::vector<int64_t>> A(H, std::vector<int64_t>(W));
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			std::cin >> A[i][j];
		}
	}
	cout << (solve(H, W, A) ? "Yes" : "No") << endl;
	return 0;
}
