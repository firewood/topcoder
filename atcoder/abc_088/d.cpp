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
		int whites = h * w;
		for (int i = 0; i < h; ++i) {
			cin >> b[i];
			whites -= count(b[i].begin(), b[i].end(), '#');
		}
		// BFS
		vector<pair<int, int>> q;
		q.push_back({ 0,0 });
		int ans = -1, dist = 0;
		while (!q.empty() && ans < 0) {
			++dist;
			vector<pair<int, int>> nq;
			const int dx[4] = { -1,1,0,0 };
			const int dy[4] = { 0,0,-1,1 };
			for (auto kv : q) {
				if (kv.first == h - 1 && kv.second == w - 1) {
					ans = whites - dist;
					break;
				}
				for (int dir = 0; dir < 4; ++dir) {
					int ny = kv.first + dy[dir], nx = kv.second + dx[dir];
					if (ny >= 0 && ny < h && nx >= 0 && nx < w && b[ny][nx] == '.') {
						b[ny][nx] = 0;
						nq.push_back({ ny, nx });
					}
				}
			}
			q = nq;
		}
		cout << ans << endl;
	}
	return 0;
}
