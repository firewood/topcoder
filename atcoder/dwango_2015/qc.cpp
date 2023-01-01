#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstring>
#include <iostream>
#include <sstream>
#include <numeric>
#include <map>
#include <set>
#include <queue>
#include <vector>
#include <atcoder/modint>

using namespace std;

typedef long double LD;

LD solve(int N) {
	static const int COMBSZ = 256;
	static vector<vector<LD>> C(COMBSZ, vector<LD>(COMBSZ, 0));
	for (int i = 0; i < COMBSZ; ++i) {
		C[i][0] = 1;
		for (int j = 1; j <= i; ++j) {
			C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]);
		}
	}

	vector<LD> p(N + 1);
	p[0] = 1;
	for (int i = 1; i <= N; ++i) {
		p[i] = p[i - 1] / 3;
	}

	vector<vector<LD>> tbl(N + 1, vector<LD>(N + 1, 0));
	vector<int> cnt(3);
	for (int n = 2; n <= N; ++n) {
		vector<LD>& w = tbl[n];
		for (int a = 0; a <= n; ++a) {
			for (int b = 0; a + b <= n; ++b) {
				int c = n - a - b;
				cnt[0] = a, cnt[1] = b, cnt[2] = c;
				if (cnt[0] > cnt[1]) swap(cnt[0], cnt[1]);
				if (cnt[1] > cnt[2]) swap(cnt[1], cnt[2]);
				if (cnt[0] > cnt[1]) swap(cnt[0], cnt[1]);
				if (cnt[1] == 0) {
					w[n] += p[n];
				} else if (cnt[0] == 0) {
					w[cnt[1]] += p[n] * C[n][cnt[1]];
				} else {
					if (cnt[0] == cnt[1] && cnt[1] == cnt[2]) {
						w[n] += p[n] * C[n][cnt[0]] * C[cnt[1] + cnt[2]][cnt[1]];
					} else {
						w[cnt[0]] += p[n] * C[n][cnt[0]] * C[cnt[1] + cnt[2]][cnt[1]];
					}
				}
			}
		}
	}

	LD ans = 0;
	vector<LD> rp(N + 1, 0);
	rp[N] = 1.0;
	for (int tt = 1; tt < 1000; ++tt) {
		vector<LD> next(N + 1, 0);
		for (int n = 2; n <= N; ++n) {
			for (int r = 1; r <= n; ++r) {
				next[r] += rp[n] * tbl[n][r];
			}
		}
		ans += next[1] * tt;
		rp = next;
	}

	return ans;
}

int main() {
	cout.precision(20);
	int N;
	cin >> N;
	cout << solve(N) << endl;
	return 0;
}
