// Google Code Jam 2020 Round 1B
// Problem A. Expogo

#include <iostream>
#include <sstream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long LL;

string solve(LL x, LL y) {
	char h[3] = { 'E', 'W' };
	char v[3] = { 'N', 'S' };
	string ans;
	LL d = 1;
	for (LL d = 1; x != 0 || y != 0; d *= 2) {
		LL nd = d * 2;
		if (x < 0) {
			x = -x;
			swap(h[0], h[1]);
		}
		if (y < 0) {
			y = -y;
			swap(v[0], v[1]);
		}
		if ((x & d) == d && (y & d) == d) {
			return "";
		}
		if ((x & d) == 0 && (y & d) == 0) {
			return "";
		}
		if (x == d && y == 0) {
			ans += h[0];
			break;
		}
		if (x == 0 && y == d) {
			ans += v[0];
			break;
		}
		if ((x & d) == d) {
			LL a = x + d;
			if ((a == 0 && y == 0)
				|| ((a & nd) == nd && (y & nd) == 0)
				|| ((a & nd) == 0 && (y & nd) == nd)) {
				x = a;
				ans += h[1];
				continue;
			}
			a = abs(x - d);
			if ((a == 0 && y == 0)
				|| ((a & nd) == nd && (y & nd) == 0)
				|| ((a & nd) == 0 && (y & nd) == nd)) {
				x -= d;
				ans += h[0];
				continue;
			}
			return "";
		} else {
			LL a = y + d;
			if ((a == 0 && x == 0)
				|| ((a & nd) == nd && (x & nd) == 0)
				|| ((a & nd) == 0 && (x & nd) == nd)) {
				y += d;
				ans += v[1];
				continue;
			}
			a = abs(y - d);
			if ((a == 0 && x == 0)
				|| ((a & nd) == nd && (x & nd) == 0)
				|| ((a & nd) == 0 && (x & nd) == nd)) {
				y -= d;
				ans += v[0];
				continue;
			}
			return "";
		}
	}
	return ans;
}

int main(int argc, char *argv[]) {
	int T;
	cin >> T;
	for (int t = 1; t <= T; ++t) {
		int x, y;
		cin >> x >> y;
		string ans = solve(x, y);
		cout << "Case #" << t << ": " << (ans.empty() ? "IMPOSSIBLE" : ans) << endl;
	}
	return 0;
}
