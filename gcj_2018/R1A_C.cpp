// Google Code Jam 2018 Round 1A
// Problem C. Edgy Baking

#include <iostream>
#include <sstream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cmath>

using namespace std;

typedef long long LL;

long double solve(int n, long double p, vector<long double> &w, vector<long double> &h) {
	long double mn = 0, mx = 0;
	long double tot = 2 * (accumulate(w.begin(), w.end(), 0.0) + accumulate(h.begin(), h.end(), 0.0));
	long double r = p - tot;
	for (int i = 0; i < n; ++i) {
		long double a = min(w[i], h[i]) * 2;
		if (a <= r) {
			mn += a;
			mx += sqrt(w[i] * w[i] + h[i] * h[i]) * 2;
			r -= a;
		}
	}
	return min(p, tot + mx);
}

int main(int argc, char *argv[]) {
	int T;
	cin >> T;
	for (int t = 1; t <= T; ++t) {
		int n;
		long double p;
		cin >> n >> p;
		vector<long double> w(n), h(n);
		for (int i = 0; i < n; ++i) {
			cin >> w[i] >> h[i];
		}
		printf("Case #%d: %.7f\n", t, (double)solve(n, p, w, h));
	}
	return 0;
}
