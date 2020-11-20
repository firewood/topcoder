// E.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>

using namespace std;

typedef long long LL;
typedef pair<int, int> II;

int main(int argc, char* argv[]) {
	cout.precision(20);
#ifdef _MSC_VER
	while (true)
#endif
	{
		int h = -1, w, m, y, x, xm = 0, ym = 0, ans = 0;
		cin >> h >> w >> m;
		if (h <= 0) return 0;
		vector<int> yc(h), xc(w), by(m), bx(m);
		for (int i = 0; i < m; ++i) {
			cin >> y >> x;
			--y, --x;
			by[i] = y;
			bx[i] = x;
			yc[y] += 1;
			xc[x] += 1;
			ym = max(ym, yc[y]);
			xm = max(xm, xc[x]);
		}
		set<II> max_x_pos;
		set<int> max_x;
		map<int, set<int>> max_y_pos;
		for (int i = 0; i < m; ++i) {
			if (xm == xc[bx[i]]) {
				max_x.emplace(bx[i]);
				max_x_pos.emplace(II(by[i], bx[i]));
			}
			if (ym == yc[by[i]]) {
				max_y_pos[by[i]].emplace(bx[i]);
			}
		}
		for (auto kv : max_y_pos) {
			int cross = 0;
			for (int x : kv.second) {
				cross += max_x_pos.find(II(kv.first, x)) != max_x_pos.end();
			}
			ans = max(ans, xm + ym - (cross >= max_x.size()));
		}
		cout << ans << endl;
	}
	return 0;
}
