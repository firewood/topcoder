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

int64_t solve(int64_t H, int64_t W, std::vector<std::string> S) {
	int64_t ans = 0;
	for (int top = 0; top < H; ++top) {
		for (int left = 0; left < W; ++left) {
			for (int h = 1; h + top <= H; ++h) {
				for (int w = 1; w + left <= W; ++w) {
					int64_t ok = 1;
					for (int i = 0; i < h; ++i) {
						for (int j = 0; j < w; ++j) {
							ok &= (S[top + i][left + j] == S[top + h - 1 - i][left + w - 1 - j]);
						}
					}
					ans += ok;
				}
			}
		}
	}
	return ans;
}

int main() {
	int64_t H, W;
	std::cin >> H >> W;
	std::vector<std::string> S(H);
	for (int64_t i = 0; i < H; ++i) {
		std::cin >> S[i];
	}
	auto ans = solve(H, W, std::move(S));
	cout << ans << endl;
}
