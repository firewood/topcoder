// D.

#include <sstream>
#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>

using namespace std;

typedef long long LL;

LL solve(LL n, LL k, vector<LL> a) {
	LL dp[64][2] = {};
	for (LL i = 0, b = 1; i < 60; ++i, b <<= 1) {
		LL sum[2] = {};
		for (LL c : a) {
			sum[0] += c & b;
			sum[1] += b ^ (c & b);
		}
		dp[i + 1][0] = dp[i][0] + sum[0];
		if (k & b) {
			dp[i + 1][0] = max({ dp[i + 1][0], dp[i][0] + sum[1], dp[i][1] + sum[0] });
		}
		dp[i + 1][1] = dp[i][1] + max(sum[0], sum[1]);
	}
	return dp[60][0];
}

#ifdef _DEBUG
LL solve2(LL n, LL k, vector<LL> a) {
	LL mx = 0;
	for (LL i = 0; i <= k; ++i) {
		LL sum = 0;
		for (LL c : a) {
			sum += i ^ c;
		}
		mx = max(mx, sum);
	}
	return mx;
}
#endif

int main(int argc, char *argv[]) {
	LL n, k;
	cin >> n >> k;
	vector<LL> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	LL ans = solve(n, k, a);
	cout << ans << endl;
#ifdef _DEBUG
	for (LL t = 0; t < 1000; ++t) {
		n = rand() % 10;
		k = rand() % 100;
		a.resize(n);
		for (LL i = 0; i < n; ++i) {
			a[i] = rand() % 100;
		}
		LL ans = solve(n, k, a);
		LL mx = solve2(n, k, a);
		if (ans != mx) {
			cout << ans << "," << mx << endl;
			cout << n << " " << k << endl;
			for (LL c : a) {
				cout << " " << c;
			}
			cout << endl;
			return -1;
		}
	}
#endif
	return 0;
}
