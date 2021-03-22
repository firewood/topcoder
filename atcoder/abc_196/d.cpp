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

int solve(int H, int W, int A, int B) {
	int ans = 0, sz = H * W, large = 0, d;
	vector<int> dir(sz);
	auto check = [&]() {
		for (int i = 0; i < H; ++i) {
			for (int j = 0; j < W; ++j) {
				if (dir[W * i + j] == 1) {
					if (j == W - 1 || dir[W * i + j + 1] || i > 0 && dir[W * (i - 1) + j + 1] == 2) {
						return false;
					}
				} else if (dir[W * i + j] == 2) {
					if (i == H - 1 || dir[W * (i + 1) + j]) {
						return false;
					}
				}
			}
		}
		return true;
	};
	do {
		if (large == A && check()) {
			++ans;
		}
		for (d = 0; d < sz; ++d) {
			dir[d] += 1;
			large += dir[d] == 1;
			if (dir[d] <= 2) break;
			dir[d] = 0;
			--large;
		}
	} while (d < sz);		// or large > 0
	return ans;
}

int main() {
	int H, W, A, B;
	std::cin >> H >> W >> A >> B;
	cout << solve(H, W, A, B) << endl;
	return 0;
}
