// Google Code Jam 2015 R2
// Problem A

#include <iostream>
#include <sstream>
#include <algorithm>
#include <set>
#include <vector>

using namespace std;

int m[128][128];

int cdx[256];
int cdy[256];

int solve(int R, int C) {
	int ans = 0;
	for (int i = 0; i < R; ++i) {
		for (int j = 0; j < C; ++j) {
			int x = cdx[m[i][j]];
			int y = cdy[m[i][j]];
			if (x || y) {
				bool f = true;
				int cx = j, cy = i;
				while (f) {
					cx += x, cy += y;
					if (cx < 0 || cx >= C || cy < 0 || cy >= R) {
						f = false;
					} else if (m[cy][cx] != '.') {
						break;
					}
				}
				if (!f) {
					const int dx[] = { -1, 1, 0, 0 };
					const int dy[] = { 0, 0, -1, 1 };
					for (int d = 0; !f && d < 4; ++d) {
						int cx = j, cy = i;
						while (!f) {
							cx += dx[d], cy += dy[d];
							if (cx < 0 || cx >= C || cy < 0 || cy >= R) {
								break;
							} else if (m[cy][cx] != '.') {
								f = true;
								break;
							}
						}
					}
					if (f) {
						++ans;
					} else {
						return -1;
					}
				}
			}
		}
	}
	return ans;
}

int main(int argc, char *argv[]) {
	cdx['<'] = -1;
	cdx['>'] = 1;
	cdy['^'] = -1;
	cdy['v'] = 1;

	string s;
	getline(cin, s);
	int T = atoi(s.c_str());
	for (int t = 1; t <= T; ++t) {
		int R, C;
		getline(cin, s);
		stringstream ss(s);
		ss >> R >> C;
		for (int i = 0; i < R; ++i) {
			getline(cin, s);
			for (int j = 0; j < C; ++j) {
				m[i][j] = s[j];
			}
		}
		int r = solve(R, C);
		cout << "Case #" << t << ": ";
		if (r < 0) {
			cout << "IMPOSSIBLE" << endl;
		} else {
			cout << r << endl;
		}
	}
	return 0;
}
