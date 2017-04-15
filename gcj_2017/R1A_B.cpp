// Google Code Jam 2017 Round 1A
// Problem B. Ratatouille

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>

using namespace std;

int solve(int N, int P, vector<int> &g, vector<vector<int> > &p) {
	int ans = 0, low = 1;
	int left[100] = {};
	while (true) {
		for (int i = 0; i < N; ++i) {
			if (left[i] >= P) {
				return ans;
			}
			low = max(low, (p[i][left[i]] * 100) / 110 / g[i]);
		}
		bool c = false;
		for (int i = 0; i < N; ++i) {
			int l = (low * g[i] * 90) / 100;
			int h = (low * g[i] * 110) / 100;
			c = false;
			for (; left[i] < P; ++left[i]) {
				if (l <= p[i][left[i]] && p[i][left[i]] <= h) {
					c = true;
					break;
				}
				if (p[i][left[i]] > h) {
					break;
				}
			}
			if (!c) {
				break;
			}
		}
		if (c) {
			++ans;
			for (int i = 0; i < N; ++i) {
				++left[i];
			}
		} else {
			++low;
		}
	}
	return -1;
}

int main(int argc, char *argv[]) {
	int T;
	cin >> T;
	for (int t = 1; t <= T; ++t) {
		int N, P;
		cin >> N >> P;
		vector<int> g(N);
		for (int i = 0; i < N; ++i) {
			cin >> g[i];
		}
		vector<vector<int> > p(N);
		for (int i = 0; i < N; ++i) {
			p[i].resize(P);
			for (int j = 0; j < P; ++j) {
				cin >> p[i][j];
			}
			sort(p[i].begin(), p[i].end());
		}
		cout << "Case #" << t << ": " << solve(N, P, g, p) << endl;
	}
	return 0;
}
