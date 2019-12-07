// D.

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long LL;

int main(int argc, char *argv[])
{
	int h, w, d, a, q, l, r;
	cin >> h >> w >> d;
	vector<LL> sum(h * w + 1);
	vector<pair<int, int>> pos(h * w + 1);
	for (int i = 0; i < h; ++i) {
		for (int j = 0; j < w; ++j) {
			cin >> a;
			pos[a] = { i, j };
		}
	}
	for (int i = h * w - d; i >= 0; --i) {
		sum[i] = sum[i + d] + abs(pos[i + d].first - pos[i].first) + abs(pos[i + d].second - pos[i].second);
	}
	cin >> q;
	for (int i = 0; i < q; ++i) {
		cin >> l >> r;
		cout << (sum[l] - sum[r]) << endl;
	}
	return 0;
}
