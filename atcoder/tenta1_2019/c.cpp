// C.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>

using namespace std;

int main(int argc, char *argv[]) {
	int n;
	cin >> n;
	string s;
	cin >> s;
	int dp[2] = {};
	for (char c : s) {
		int a = dp[0], b = dp[1];
		if (c == '.') {
			dp[0] = a;
			dp[1] = b + 1;
		} else {
			dp[0] = a + 1;
			dp[1] = min(a, b);
		}
	}
	int ans = min(dp[0], dp[1]);
	cout << ans << endl;
	return 0;
}
