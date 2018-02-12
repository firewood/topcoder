#include <iostream>
#include <sstream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

typedef pair<int, int> II;
typedef pair<II, II> IIII;

int H;
int W;
int D;
int K;

int main()
{
	set<II> poss;
	const int grid_d = 8;
	cin >> H >> W >> D >> K;
	vector<II> pos;
	vector<IIII> ans;
	for (int i = 0; i < D; ++i) {
		int r, c;
		cin >> r >> c;
		pos.push_back(II(r, c));
		poss.insert(II(r, c));
	}
	vector<II> opos = pos;
	{
		vector<II> errs;
		for (int i = 1; i < D - 1; ++i) {
			int cb = abs(pos[i - 1].first - pos[i].first) + abs(pos[i - 1].second - pos[i].second);
			int cf = abs(pos[i + 1].first - pos[i].first) + abs(pos[i + 1].second - pos[i].second);
			int cd = abs(pos[i - 1].first - pos[i + 1].first) + abs(pos[i - 1].second - pos[i + 1].second);
			int cost = cb + cf - cd;
			errs.push_back(II(cost, i));
		}
		sort(errs.rbegin(), errs.rend());
		set<int> can[64][64];
		for (int i = 0; i < K; ++i) {
			int j = errs[i].second;
			can[pos[j].first / grid_d][pos[j].second / grid_d].insert(j);
		}
		for (int i = 0; i < (int)errs.size() && ((int)ans.size() < K); ++i) {
			int src = errs[i].second;
			int cx = (pos[src - 1].second + pos[src + 1].second) / 2;
			int cy = (pos[src - 1].first + pos[src + 1].first) / 2;
			set<int> &s = can[cy / grid_d][cx / grid_d];
			vector<II> sv;
			int sx = pos[src].second, sy = pos[src].first;
			for (int dst : s) {
				int dx = pos[dst].second, dy = pos[dst].first;
				int prev = abs(pos[src - 1].first - sy) + abs(pos[src - 1].second - sx)
					+ abs(pos[src + 1].first - sy) + abs(pos[src + 1].second - sy)
					+ abs(pos[dst - 1].first - dy) + abs(pos[dst - 1].second - dx)
					+ abs(pos[dst + 1].first - dy) + abs(pos[dst + 1].second - dy);
				int cost = abs(pos[src - 1].first - dy) + abs(pos[src - 1].second - dx)
					+ abs(pos[src + 1].first - dy) + abs(pos[src + 1].second - dy)
					+ abs(pos[dst - 1].first - sy) + abs(pos[dst - 1].second - sx)
					+ abs(pos[dst + 1].first - sy) + abs(pos[dst + 1].second - sy);
				if (cost * 4 <= prev) {
					sv.push_back(II(cost, dst));
				}
			}
			sort(sv.begin(), sv.end());
			if (sv.size()) {
				set<int> &ss = can[sy / grid_d][sx / grid_d];
				ss.erase(src);
				s.erase(sv[0].second);
				swap(pos[sv[0].first], pos[sv[0].second]);
				ans.push_back(IIII(pos[sv[0].first], pos[sv[0].second]));
			}
		}
	}
	{
		vector<II> errs;
		for (int i = 1; i < D - 1; ++i) {
			int cb = abs(pos[i - 1].first - pos[i].first) + abs(pos[i - 1].second - pos[i].second);
			int cf = abs(pos[i + 1].first - pos[i].first) + abs(pos[i + 1].second - pos[i].second);
			int cd = abs(pos[i - 1].first - pos[i + 1].first) + abs(pos[i - 1].second - pos[i + 1].second);
			int cost = cb + cf - cd;
			errs.push_back(II(cost, i));
		}
		sort(errs.rbegin(), errs.rend());
		for (int i = 0; i < (int)errs.size() && (int)ans.size() < K; ++i) {
			int src = errs[i].second;
			int sx = min(pos[src - 1].second, pos[src + 1].second);
			int ex = max(pos[src - 1].second, pos[src + 1].second);
			int sy = min(pos[src - 1].first, pos[src + 1].first);
			int ey = max(pos[src - 1].first, pos[src + 1].first);
			bool ok = false;
			for (int y = sy; !ok && y <= ey; ++y) {
				for (int x = sx; x <= ex; ++x) {
					if (poss.find(II(y, x)) == poss.end()) {
						ok = true;
						ans.push_back(IIII(pos[src], II(y, x)));
						poss.insert(II(y, x));
						break;
					}
				}
			}
		}
	}
	for (int i = 0; i < (int)ans.size(); ++i) {
		cout << ans[i].first.first << " " << ans[i].first.second << " " << ans[i].second.first << " " << ans[i].second.second << endl;
	}

	return 0;
}
