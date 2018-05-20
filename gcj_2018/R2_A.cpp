// Google Code Jam 2018 Round 2
// Problem A. Falling Balls

#include <iostream>
#include <sstream>
#include <algorithm>
#include <numeric>
#include <vector>

using namespace std;

vector<string> solve(int c, vector<int> b) {
	int tot = accumulate(b.begin(), b.end(), 0);
	if (tot != c || b[0] == 0 || b.back() == 0) {
		return vector<string>();
	}

	vector<int> g(c);
	int pos = 0;
	int mx = 0;
	for (int i = 0; i < c; ++i) {
		int r = b[i];
		while (r > 0) {
			--r;
			g[pos] = i;
			mx = max(mx, abs(pos - i));
			++pos;
		}
	}

	string fill = string(c, '.');
	vector<string> r(mx + 1, fill);

	for (int i = 0; i < c; ++i) {
		int diff = g[i] - i;
		if (diff > 0) {
			for (int j = 0; j < diff; ++j) {
				r[mx - diff + j][i + j] = '\\';
			}
		} else if (diff < 0) {
			diff = -diff;
			for (int j = 0; j < diff; ++j) {
				r[mx - diff + j][i - j] = '/';
			}
		}
	}

	return r;
}

int main(int argc, char *argv[]) {
	int T;
	cin >> T;
	for (int t = 1; t <= T; ++t) {
		int c;
		cin >> c;
		vector<int> b(c);
		for (int i = 0; i < c; ++i) {
			cin >> b[i];
		}
		vector<string> ans = solve(c, b);
		if (ans.empty()) {
			cout << "Case #" << t << ": IMPOSSIBLE" << endl;
		} else {
			cout << "Case #" << t << ": " << ans.size() << endl;
			for (string s : ans) {
				cout << s << endl;
			}
		}
	}
	return 0;
}
