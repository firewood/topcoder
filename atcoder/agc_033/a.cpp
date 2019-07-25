// A.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <vector>

using namespace std;

typedef pair<int, int> II;

int main(int argc, char* argv[]) {
	int h, w;
	cin >> h >> w;
	vector<string> b(h);
	vector<vector<int>>vis(h, vector<int>(w, -1));
	int sr = 0, sc = 0;
	for (int i = 0; i < h; ++i) {
		cin >> b[i];
	}
	vector<II> q;
	int dx[4] = { -1,1,0,0 };
	int dy[4] = { 0,0,-1,1 };
	for (int i = 0; i < h; ++i) {
		for (int j = 0; j < w; ++j) {
			if (b[i][j] != '#') continue;
			for (int d = 0; d < 4; ++d) {
				int ny = i + dy[d], nx = j + dx[d];
				if (ny >= 0 && ny < h && nx >= 0 && nx < w && b[ny][nx] == '.') {
					b[ny][nx] = '-';
					q.push_back({ ny, nx });
				}
			}
		}
	}
	int ans;
	for (ans = 0; q.size(); ++ans) {
		vector<II> nq;
		for (auto kv : q) {
			for (int d = 0; d < 4; ++d) {
				int ny = kv.first + dy[d], nx = kv.second + dx[d];
				if (ny >= 0 && ny < h && nx >= 0 && nx < w && b[ny][nx] == '.') {
					b[ny][nx] = '-';
					nq.push_back({ ny, nx });
				}
			}
		}
		q = nq;
	}
	cout << ans << endl;
	return 0;
}
