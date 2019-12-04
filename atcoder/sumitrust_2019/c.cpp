// C.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int main(int argc, char* argv[]) {
	cout.precision(20);
#ifdef _MSC_VER
	while (true)
#endif
	{
		int x = -1;
		cin >> x;
		if (x <= 0) return 0;
		vector<int> dp(100001);
		dp[0] = 1;
		for (int i = 100; i <= 105; ++i) {
			for (int j = i; j <= x; ++j) {
				if (dp[j - i]) {
					dp[j] = 1;
				}
			}
		}
		cout << dp[x] << endl;
	}
	return 0;
}
