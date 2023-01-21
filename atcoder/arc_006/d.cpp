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

typedef pair<int, int> II;

// rotate anti-clockwise
vector <string> rotate(const vector <string>& a) {
	if (a.empty()) {
		return a;
	}
	int h = a.size(), w = a[0].length();
	vector <string> b(w, string(h, ' '));
	for (int r = 0; r < w; ++r) {
		for (int c = 0; c < h; ++c) {
			b[r][c] = a[c][w - r - 1];
		}
	}
	return b;
}

void solve(int H, int W, const vector<string> &b, vector<int> &ans) {
	vector<vector<int>> vis(H, vector<int>(W));
	auto check = [&](int y, int x, int dy, int dx) {
		int cnt = 0;
		while (y >= 0 && y < H && x >= 0 && x < W) {
			if (b[y][x] == '.') break;
			y += dy;
			x += dx;
			++cnt;
		}
		return cnt;
	};
	const int check_factors[] = { 12,16,11 };
	for (int i = 0; i < H; ++i) {
		for (int j = 0; j < W; ++j) {
			if (!vis[i][j] && b[i][j] != '.') {
				int cnt = 0;
				vis[i][j] = 1;
				deque<II> q;
				q.emplace_back(i, j);
				while (!q.empty()) {
					int y = q.front().first, x = q.front().second;
					q.pop_front();
					++cnt;
					for (int dy = -1; dy <= 1; ++dy) {
						for (int dx = -1; dx <= 1; ++dx) {
							int ny = y + dy, nx = x + dx;
							if (ny < 0 || ny >= H || nx < 0 || nx >= W) continue;
							if (vis[ny][nx]) continue;
							vis[ny][nx] = 1;
							if (b[ny][nx] != '.') {
								q.emplace_back(ny, nx);
							}
						}
					}
				}
				int yc = check(i, j, 1, 0), xc = check(i, j, 0, 1);
				for (int i = 0; i < 3; ++i) {
					ans[i] += yc == xc && yc * yc * check_factors[i] == cnt;
				}
			}
		}
	}
}

int main() {
	int H, W;
	cin >> H >> W;
	vector<string> b(H);
	for (int i = 0; i < H; i++) {
		cin >> b[i];
	}
	vector<int> ans(3);
	for (int i = 0; i < 4; ++i) {
		solve(H, W, b, ans);
		b = rotate(b);
		swap(H, W);
	}
	cout << ans[0] << " " << ans[1] << " " << ans[2] << endl;
	return 0;
}
