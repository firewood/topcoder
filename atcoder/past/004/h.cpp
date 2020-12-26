#include <algorithm>
#include <cmath>
#include <cstring>
#include <cctype>
#include <iostream>
#include <sstream>
#include <numeric>
#include <map>
#include <set>
#include <queue>
#include <vector>

using namespace std;

int main() {
	int H, W, K;
	cin >> H >> W >> K;
	vector<string> s(H);
	int hsum[10][32][32] = {};
	int vsum[10][32][32] = {};
	for (int i = 0; i < H; ++i) {
		cin >> s[i];
		for (int j = 0; j < W; ++j) {
			for (int k = 0; k < 10; ++k) {
				hsum[k][i][j + 1] = hsum[k][i][j];
			}
			int d = s[i][j] - '0';
			hsum[d][i][j + 1] += 1;
		}
	}
	for (int i = 0; i < H; ++i) {
		for (int j = 0; j < W; ++j) {
			for (int k = 0; k < 10; ++k) {
				vsum[k][i + 1][j + 1] = vsum[k][i][j + 1] + hsum[k][i][j + 1];
			}
		}
	}
	int ans = 0;
	for (int i = 0; i < H; ++i) {
		for (int j = 0; j < W; ++j) {
			for (int k = 0; k < 10; ++k) {
				for (int n = min(i + 1, j + 1); n >= 1; --n) {
					int c = vsum[k][i + 1][j + 1] - vsum[k][i + 1 - n][j + 1] - vsum[k][i + 1][j + 1 - n] + vsum[k][i + 1 - n][j + 1 - n];
					if (n * n - c <= K) {
						ans = max(ans, n);
					}
				}
			}
		}
	}
	cout << ans << endl;
	return 0;
}
