#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <sstream>
#include <numeric>
#include <queue>
#include <vector>

using namespace std;

typedef long long LL;

int main() {
	// H, W <= 1500
	// N <= 500000
	// M <= 100000
	LL H, W, N, M, a, b, c, d;
	cin >> H >> W >> N >> M;
	vector<vector<int>> light(H + 1, vector<int>(W + 1));
	vector<vector<int>> block(H + 1, vector<int>(W + 1));
	vector<vector<int>> floor(H + 1, vector<int>(W + 1));
	for (LL i = 0; i < N; ++i) {
		cin >> a >> b;
		light[a][b] = 1;
	}
	for (LL i = 0; i < M; ++i) {
		cin >> c >> d;
		block[c][d] = 1;
	}
	int st;
	auto fill = [&](int i, int j) {
		if (light[i][j]) {
			st = 1;
		} else if (block[i][j]) {
			st = 0;
		}
		floor[i][j] |= st;
	};
	for (int i = 1; i <= H; ++i) {
		st = 0;
		for (int j = 1; j <= W; ++j) {
			fill(i, j);
		}
		st = 0;
		for (int j = W; j >= 1; --j) {
			fill(i, j);
		}
	}
	for (int j = 1; j <= W; ++j) {
		st = 0;
		for (int i = 1; i <= H; ++i) {
			fill(i, j);
		}
		st = 0;
		for (int i = H; i >= 1; --i) {
			fill(i, j);
		}
	}
	LL ans = 0;
	for (int i = 1; i <= H; ++i) {
		ans += accumulate(floor[i].begin(), floor[i].end(), 0LL);
	}
	cout << ans << endl;
	return 0;
}
