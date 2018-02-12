#include <iostream>
#include <sstream>
#include <vector>
#include <set>
#include <algorithm>
#include <chrono>
#include <bitset>

using namespace std;
using namespace std::chrono;

typedef pair<int, int> II;
typedef pair<II, II> IIII;

int H;
int W;
int D;
int K;
vector<II> pos;

static const int TIME_LIMIT = 4000;
auto start_time = high_resolution_clock::now();
int past() {
	return duration_cast<milliseconds>(high_resolution_clock::now() - start_time).count();
}
bool is_timed_out() {
	return past() > (TIME_LIMIT - 250);
}

__inline int dist(int a, int b) {
	return abs(pos[a].first - pos[b].first) + abs(pos[a].second - pos[b].second);
}

int main()
{
	cin >> H >> W >> D >> K;
	for (int i = 0; i < D; ++i) {
		int r, c;
		cin >> r >> c;
		pos.push_back(II(r, c));
	}

	vector<IIII> ans;
	while (!is_timed_out()) {
		int rate = max(1, 10 - (past() / 400));
		for (int t = 0; t < 10000; ++t) {
			int a = (rand() % (D - 2)) + 1, b = (rand() % (D - 2)) + 1;
			if (a != b) {
				int before = dist(a - 1, a) + dist(a, a + 1) + dist(b - 1, b) + dist(b, b + 1);
				int after = dist(a - 1, b) + dist(b, a + 1) + dist(b - 1, a) + dist(a, b + 1);
				if (after * rate < before) {
					ans.push_back(IIII(pos[a], pos[b]));
					swap(pos[a], pos[b]);
				}
			}
		}
	}
	for (int i = 0; i < K && (int)ans.size(); ++i) {
		cout << ans[i].first.first << " " << ans[i].first.second << " " << ans[i].second.first << " " << ans[i].second.second << endl;
	}
	return 0;
}
