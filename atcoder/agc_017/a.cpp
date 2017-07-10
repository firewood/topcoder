// A. 

#include <iostream>
#include <algorithm>
#include <sstream>
#include <cstdio>
#include <cstring>

using namespace std;

typedef long long LL;

int main(int argc, char *argv[])
{
	int n, p;
	cin >> n >> p;
	LL dp[2][2] = {1};
	for (int i = 0; i < n; ++i) {
		int a;
		cin >> a;
		if (a % 2) {
			dp[(i % 2) ^ 1][0] = dp[i % 2][0] + dp[i % 2][1];
			dp[(i % 2) ^ 1][1] = dp[i % 2][0] + dp[i % 2][1];
		} else {
			dp[(i % 2) ^ 1][0] = dp[i % 2][0] * 2;
			dp[(i % 2) ^ 1][1] = dp[i % 2][1] * 2;
		}
	}
	cout << dp[n % 2][p] << endl;
	return 0;
}
