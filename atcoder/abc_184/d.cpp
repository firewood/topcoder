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

using namespace std;

typedef long double LD;

LD solve(long long A, long long B, long long C) {
	LD ans = 0;
	vector<vector<vector<LD>>> dp(101, vector<vector<LD>>(101, vector<LD>(101)));
	dp[A][B][C] = 1.0;
	for (int a = 0; a < 100; ++a) {
		for (int b = 0; b < 100; ++b) {
			for (int c = 0; c < 100; ++c) {
				if (a + b + c <= 0) continue;
				LD d = dp[a][b][c];
				LD e = d * a / (a + b + c);
				LD f = a + b + c - A - B - C + 1;
				if (a >= 99) {
					ans += e * f;
				} else {
					dp[a + 1][b][c] += e;
				}
				e = d * b / (a + b + c);
				if (b >= 99) {
					ans += e * f;
				} else {
					dp[a][b + 1][c] += e;
				}
				e = d * c / (a + b + c);
				if (c >= 99) {
					ans += e * f;
				} else {
					dp[a][b][c + 1] += e;
				}
			}
		}
	}
	return ans;
}

int main() {
	cout.precision(20);
	long long A, B, C;
	std::cin >> A >> B >> C;
	LD ans = solve(A, B, C);
	cout << ans << endl;
	return 0;
}
