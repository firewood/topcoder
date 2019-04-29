// Google Code Jam 2019 Round 1B
// Problem A. 

#include <iostream>
#include <sstream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

typedef pair<int, int> II;
typedef pair<II, II> IIII;

II solve(vector<IIII> p, int q) {
	II ans(q, q);
	int n = (int)p.size();
	if (q <= 100) {
		int m[102][102] = {};
		for (auto x : p) {
			II st = x.first;
			II dir = x.second;
			if (dir.first) {
				for (int i = st.first + dir.first; i >= 0 && i <= q; i += dir.first) {
					for (int j = 0; j <= q; ++j) {
						m[i][j] += 1;
					}
				}
			} else {
				for (int i = st.second + dir.second; i >= 0 && i <= q; i += dir.second) {
					for (int j = 0; j <= q; ++j) {
						m[j][i] += 1;
					}
				}
			}
		}
		int mx = -1;
		for (int i = 0; i <= q; ++i) {
			for (int j = 0; j <= q; ++j) {
				mx = max(mx, m[i][j]);
			}
		}
		for (int i = 0; i <= q; ++i) {
			for (int j = 0; j <= q; ++j) {
				if (m[i][j] == mx) {
					return II(i, j);
				}
			}
		}
	}
	return ans;
}

int main(int argc, char *argv[]) {
	int T;
	cin >> T;
	for (int t = 1; t <= T; ++t) {
		int p, q;
		cin >> p >> q;
		vector<IIII> v;
		for (int i = 0; i < p; ++i) {
			int x, y;
			string d;
			cin >> x >> y >> d;
			if (d == "N") {
				v.push_back(IIII(II(x, y), II(0, 1)));
			}
			if (d == "S") {
				v.push_back(IIII(II(x, y), II(0, -1)));
			}
			if (d == "E") {
				v.push_back(IIII(II(x, y), II(1, 0)));
			}
			if (d == "W") {
				v.push_back(IIII(II(x, y), II(-1, 0)));
			}
		}
		II ans = solve(v, q);
		cout << "Case #" << t << ": " << ans.first << " " << ans.second << endl;
	}
	return 0;
}
