#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;
typedef pair<int, int> II;

int main(int argc, char *argv[]) {
	int H, W, N;
	cin >> H >> W >> N;
	string s[10000];
	for (int i = 0; i < H; ++i) {
		cin >> s[i];
	}
	int r[10000] = {};
	for (int i = 0; i < W; ++i) {
		for (int j = H - 1; j >= 0 && s[j][i] == '#'; --j) {
			++r[i];
		}
	}
	vector<II> v;
	for (int i = 0; i < N; ++i) {
		int c;
		cin >> c;
		v.push_back(II(c, i));
	}
	sort(v.begin(), v.end());
	int b[30000][3] = {};
	int u[30000] = {};
	int pos = 0;
	for (int x = 0; x < W; ++x) {
		while (pos != v.size() && v[pos].first + 2 < x) {
			++pos;
		}
		for (int i = 0; i < r[x]; ++i) {
			bool f = false;
			for (int j = pos; j != v.size() && v[j].first <= x; ++j) {
				if (!u[v[j].second]) {
					f = true;
					u[v[j].second] = 1;
					b[v[j].second][x - v[j].first]++;
					break;
				}
			}
			if (!f) {
				for (int j = pos; j != v.size() && v[j].first <= x; ++j) {
					if (b[v[j].second][x - v[j].first] < 3) {
						b[v[j].second][x - v[j].first]++;
						break;
					}
				}
			}
		}
	}
	for (int i = 0; i < N; ++i) {
		for (int j = 3; j >= 1; --j) {
			for (int k = 0; k < 3; ++k) {
				cout << (b[i][k] >= j ? '#' : '.');
			}
			cout << endl;
		}
	}
	return 0;
}
