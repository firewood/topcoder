// D.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long LL;
const LL MOD = 2019;

int main(int argc, char* argv[]) {
#ifdef _MSC_VER
	while (true)
#endif
	{
		string s;
		cin >> s;
		if (s.empty()) return 0;
		vector<LL> dp(MOD);
		dp[0] = 1;
		LL d = 1, sum = 0, ans = 0;
		// Œ…DP
		for (auto it = s.rbegin(); it != s.rend(); ++it) {
			sum = (sum + d * (*it - '0')) % MOD;
			ans += dp[sum];
			dp[sum] += 1;
			d = (d * 10) % MOD;
		}
		cout << ans << endl;
	}
	return 0;
}
