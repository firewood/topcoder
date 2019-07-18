// D.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>

using namespace std;

int main(int argc, char *argv[]) {
	int h, w;
	cin >> h >> w;
	vector<string> s(h);
	vector<vector<int>> v(h, vector<int>(w));
	int ans = 0;
	for (int i = 0; i < h; ++i) {
		cin >> s[i];
		for (int j = 0; j < w; ++j) {
			if (s[i][j] == '.') {
				int k;
				for (k = j + 1; k < w; ++k) {
					if (s[i][k] != '.') {
						break;
					}
				}
				int cnt = k - j;
				for (; j < k; ++j) {
					v[i][j] = cnt;
				}
				--j;	// unnecessary
			}
		}
	}
	for (int j = 0; j < w; ++j) {
		for (int i = 0; i < h; ++i) {
			if (s[i][j] == '.') {
				int k;
				for (k = i + 1; k < h; ++k) {
					if (s[k][j] != '.') {
						break;
					}
				}
				int cnt = k - i;
				for (; i < k; ++i) {
					ans = max(ans, v[i][j] + cnt - 1);
				}
			}
		}
	}
	cout << ans << endl;
	return 0;
}
