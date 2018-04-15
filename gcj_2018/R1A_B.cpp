// Google Code Jam 2018 Round 1A
// Problem B. Bit Party

#include <iostream>
#include <sstream>
#include <algorithm>
#include <numeric>
#include <vector>

using namespace std;

typedef long long LL;

LL solve(LL r, LL b, LL c, vector<LL> &m, vector<LL> &s, vector<LL> &p) {
	LL left = 0, right = 1LL << 62;
	while ((right - left) > 1) {
		LL t = (left + right) / 2;
		vector<LL> cnt;
		for (LL i = 0; i < c; ++i) {
			LL r = (t - p[i]);
			if (r > 0) {
				cnt.push_back(min(m[i], r / s[i]));
			}
		}
		sort(cnt.rbegin(), cnt.rend());
		if (accumulate(cnt.begin(), cnt.begin() + min((LL)cnt.size(), r), 0LL) >= b) {
			right = t;
		} else {
			left = t;
		}
	}
	return right;
}

int main(int argc, char *argv[]) {
	int T;
	cin >> T;
	for (int t = 1; t <= T; ++t) {
		LL r, b, c;
		cin >> r >> b >> c;
		vector<LL> m(c), s(c), p(c);
		for (int i = 0; i < c; ++i) {
			cin >> m[i] >> s[i] >> p[i];
		}
		cout << "Case #" << t << ": " << solve(r, b, c, m, s, p) << endl;
	}
	return 0;
}
