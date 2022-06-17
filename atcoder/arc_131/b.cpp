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
#include <random>

using namespace std;

const int dy[4] = { 0, -1, 0, 1 };
const int dx[4] = { -1, 0, 1, 0 };

std::vector<string> solve(int H, int W, std::vector<string> c) {
	vector<string> ans = c;
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; ++j) {
			if (ans[i][j] == '.') {
				int used = 0;
				for (int dir = 0; dir < 4; ++dir) {
					int ny = i + dy[dir], nx = j + dx[dir];
					if (ny >= 0 && ny < H && nx >= 0 && nx < W) {
						if (ans[ny][nx] != '.') {
							used |= 1 << (ans[ny][nx] - '1');
						}
					}
				}
				for (int k = 0; k < 5; ++k) {
					if ((used & (1 << k)) == 0) {
						ans[i][j] = char('1' + k);
						break;
					}
				}
			}
		}
	}
	return ans;
}

int main() {
	int64_t H, W;
	cin >> H >> W;
	std::vector<string> c(H);
	for (int i = 0; i < H; i++) {
		std::cin >> c[i];
	}
	std::vector<string> ans = solve(H, W, c);
	for (int i = 0; i < H; i++) {
		cout << ans[i] << endl;
	}
	return 0;
}
