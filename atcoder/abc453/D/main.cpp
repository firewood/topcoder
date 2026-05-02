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

const int dy[4] = { 0, 1, 0, -1 };
const int dx[4] = { 1, 0, -1, 0 };
const string move_str = "RDLU";
typedef pair<int, int> II;
typedef pair<int, II> III;

string solve(int64_t H, int64_t W, vector<string> S) {
	vector<vector<vector<int>>> prev_dirs(H, vector<vector<int>>(W, vector<int>(4, -1)));
	vector<III> q;
	for (int i = 0; i < H; ++i) {
		for (int j = 0; j < W; ++j) {
			if (S[i][j] == 'S') {
				q.emplace_back(III(-1, II(i, j)));
			}
		}
	}
	for (int depth = 1; !q.empty(); ++depth) {
		vector<III> nq;
		for (const auto& [prev_dir, yx] : q) {
			int y = yx.first, x = yx.second;
			if (S[y][x] == 'G') {
				string ans;
				int dir = prev_dir;
				while (S[y][x] != 'S') {
					int next_dir = prev_dirs[y][x][dir];
					ans += move_str[dir];
					y -= dy[dir];
					x -= dx[dir];
					dir = next_dir;
				}
				reverse(ans.begin(), ans.end());
				return ans;
			}
			for (int dir = 0; dir < 4; ++dir) {
				int ny = y + dy[dir], nx = x + dx[dir];
				if (ny < 0 || ny >= H || nx < 0 || nx >= W) continue;
				if (S[ny][nx] == '#') continue;
				if (S[y][x] == 'o' && prev_dir != dir) continue;
				if (S[y][x] == 'x' && prev_dir == dir) continue;
				if (prev_dirs[ny][nx][dir] < 0) {
					prev_dirs[ny][nx][dir] = prev_dir;
					nq.emplace_back(III(dir, II(ny, nx)));
				}
			}
		}
		q = nq;
	}
	return "";
}

int main() {
	int64_t H, W;
	cin >> H >> W;
	vector<string> S(H);
	for (int64_t j = 0; j < H; ++j) {
		cin >> S[j];
	}
	string ans = solve(H, W, std::move(S));
	if (ans.empty()) {
		cout << "No" << endl;
	} else {
		cout << "Yes" << endl;
		cout << ans << endl;
	}	
}
