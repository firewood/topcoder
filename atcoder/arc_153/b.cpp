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

int main() {
	int64_t H, W, Q, r, c;
	cin >> H >> W;
	vector<string> a(H);
	for (int i = 0; i < H; ++i) {
		cin >> a[i];
	}
	int vpos = 0, hpos = 0;
	cin >> Q;
	for (int tt = 0; tt < Q; ++tt) {
		cin >> r >> c;
		if (vpos < r) {
			vpos = r - vpos - 1;
		} else {
			vpos = H - (vpos - r) - 1;
		}
		if (hpos < c) {
			hpos = c - hpos - 1;
		} else {
			hpos = W - (hpos - c) - 1;
		}
	}
	vector<int> v(H), h(W);
	int dir = Q % 2 ? -1 : 1;
	for (int i = 0; i < H; ++i, vpos += dir) {
		v[(vpos + H) % H] = i;
	}
	for (int i = 0; i < W; ++i, hpos += dir) {
		h[(hpos + W) % W] = i;
	}
	vector<string> ans = a;
	for (int i = 0; i < H; ++i) {
		for (int j = 0; j < W; ++j) {
			cout << ans[v[i]][h[j]];
		}
		cout << endl;
	}
	return 0;
}
