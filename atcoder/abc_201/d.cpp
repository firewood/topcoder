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

typedef pair<int, int> II;

string solve(int H, int W, vector<string>& a) {
	vector<II> prev(W);
	for (int i = H - 1; i >= 0; --i) {
		vector<II> curr(W);
		for (int j = W - 1; j >= 0; --j) {
			II v, w;
			if (j < W - 1) {
				v = make_pair(curr[j + 1].second + (a[i][j + 1] == '+' ? 1 : -1), curr[j + 1].first);
			}
			if (i < H - 1) {
				w = make_pair(prev[j].second + (a[i + 1][j] == '+' ? 1 : -1), prev[j].first);
				if (j == W - 1 || v.first - v.second < w.first - w.second) {
					v = w;
				}
			}
			curr[j] = v;
		}
		prev = curr;
	}
	if (prev[0].first == prev[0].second) {
		return "Draw";
	}
	if (prev[0].first < prev[0].second) {
		return "Aoki";
	}
	return "Takahashi";
}

int main() {
	int H, W;
	cin >> H >> W;
	vector<string> a(H);
	for (int i = 0; i < H; i++) {
		cin >> a[i];
	}
	string ans = solve(H, W, a);
	cout << ans << endl;
	return 0;
}
