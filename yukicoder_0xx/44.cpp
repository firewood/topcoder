#include <iostream>
#include <algorithm>
#include <sstream>
#include <cstring>

using namespace std;

typedef long long LL;

int main(int argc, char *argv[]) {
	string s;
	getline(cin, s);
	LL N = atoi(s.c_str());
	LL dp[64] = {};
	dp[0] = 1;
	for (LL i = 1; i <= N; ++i) {
		dp[i] = dp[i - 1];
		if (i > 1) {
			dp[i] += dp[i - 2];
		}
	}
	cout << dp[N] << endl;
	return 0;
}
