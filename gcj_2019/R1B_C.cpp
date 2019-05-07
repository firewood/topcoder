// Google Code Jam 2019 Round 1B
// Problem C. Fair Fight

#include <iostream>
#include <sstream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

int solve(int n, int K, vector<int> c, vector<int> d) {
	int ans = 0;
	if (n <= 100) {
		for (int i = 0; i < n; ++i) {
			for (int j = i; j < n; ++j) {
				int cm = 0, dm = 0;
				for (int k = i; k <= j; ++k) {
					cm = max(cm, c[k]);
					dm = max(dm, d[k]);
				}
				ans += abs(cm - dm) <= K;
			}
		}
	}
	return ans;
}

int main(int argc, char* argv[]) {
	int T;
	cin >> T;
	for (int t = 1; t <= T; ++t) {
		int n, k;
		cin >> n >> k;
		vector<int> c(n), d(n);
		for (int i = 0; i < n; ++i) {
			cin >> c[i];
		}
		for (int i = 0; i < n; ++i) {
			cin >> d[i];
		}
		int ans = solve(n, k, c, d);
		cout << "Case #" << t << ": " << ans << endl;
	}
	return 0;
}
