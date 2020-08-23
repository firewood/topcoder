// D.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> II;
typedef pair<int, II> III;

static const int INF = 1 << 30;

int main(int argc, char* argv[]) {
	int h, w, sh, sw, eh, ew, ans = -1;
	cin >> h >> w >> sh >> sw >> eh >> ew;
	--sh, --sw, --eh, --ew;
	vector<string> b(h);
	for (int i = 0; i < h; ++i) {
		cin >> b[i];
	}
	priority_queue<III, vector<III>, greater<>> q;
	q.emplace(III(0, II(sh, sw)));
	vector<vector<int>> min_cost(h, vector<int>(w, INF));
	min_cost[sh][sw] = 0;
	while (!q.empty()) {
		III top = q.top();
		int cost = top.first, y = top.second.first, x = top.second.second;
		if (y == eh && x == ew) {
			ans = cost;
			break;
		}
		q.pop();
		for (int dy = -2; dy <= 2; ++dy) {
			for (int dx = -2; dx <= 2; ++dx) {
				int ny = y + dy, nx = x + dx;
				if (ny >= 0 && ny < h && nx >= 0 && nx < w && b[ny][nx] != '#') {
					int next_cost = cost + (abs(ny - y) + abs(nx - x) != 1);
					if (next_cost < min_cost[ny][nx]) {
						min_cost[ny][nx] = next_cost;
						q.emplace(III(next_cost, II(ny, nx)));
					}
				}
			}
		}
	}
	cout << ans << endl;
	return 0;
}
