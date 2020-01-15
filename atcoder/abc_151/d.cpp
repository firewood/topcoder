// D.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>

using namespace std;

int main(int argc, char* argv[]) {
#ifdef _MSC_VER
	while (true)
#endif
	{
		int h = -1, w;
		cin >> h >> w;
		if (h < 0) return 0;
		vector<string> b(h);
		for (int i = 0; i < h; ++i) {
			cin >> b[i];
		}
		vector<vector<int>> d(h * w, vector<int>(h * w, 1 << 29));
		for (int i = 0; i < h; ++i) {
			for (int j = 0; j < w; ++j) {
				if (b[i][j] != '.') continue;
				const int dx[] = { -1,1,0,0 };
				const int dy[] = { 0,0,-1,1 };
				for (int dir = 0; dir < 4; ++dir) {
					int ny = i + dy[dir], nx = j + dx[dir];
					if (ny >= 0 && ny < h && nx >= 0 && nx < w && b[ny][nx] == '.') {
						d[i * w + j][ny * w + nx] = 1;
						d[ny * w + nx][i * w + j] = 1;
					}
				}
			}
		}
		for (int k = 0; k < h * w; ++k) {
			for (int i = 0; i < h * w; ++i) {
				for (int j = 0; j < h * w; ++j) {
					d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
				}
			}
		}
		int ans = 0;
		for (int i = 0; i < h * w; ++i) {
			for (int j = 0; j < h * w; ++j) {
				if (i != j && d[i][j] < (1 << 29)) {
					ans = max(ans, d[i][j]);
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}
