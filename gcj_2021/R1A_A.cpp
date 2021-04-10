// Google Code Jam 2021 Round 1A
// Problem A. Append Sort (12pts, 14pts)

#include <iostream>
#include <sstream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long LL;

LL solve(int n, vector<string> w) {
	LL ans = 0;
	string prev = w[0];
	for (int i = 1; i < n; ++i) {
		string s = w[i], x;
		if (s.length() > prev.length() || (s.length() == prev.length() && s > prev)) {
			prev = s;
			continue;
		}
		if (s.length() < prev.length()) {
			x = s + string(prev.length() - s.length(), '0');
			if (x > prev) {
				ans += prev.length() - s.length();
				prev = x;
				continue;
			}
			x = s + string(prev.length() - s.length(), '9');
			if (x > prev) {
				LL y = stoll(prev.substr(prev.length() - s.length()));
				string z = string(prev.length() - s.length(), '0') + to_string(y + 1);
				x = s + z.substr(z.length() - (prev.length() - s.length()));
				ans += prev.length() - s.length();
				prev = x;
				continue;
			}
		}
		ans += prev.length() - s.length() + 1;
		x = s + string(prev.length() - s.length() + 1, '0');
		prev = x;
	}
	return ans;
}

int main(int argc, char* argv[]) {
	int T;
	cin >> T;
	for (int t = 1; t <= T; ++t) {
		int n;
		cin >> n;
		vector<string> w(n);
		for (int i = 0; i < n; ++i) {
			cin >> w[i];
		}
		LL ans = solve(n, w);
		cout << "Case #" << t << ": " << ans << endl;
	}
	return 0;
}
