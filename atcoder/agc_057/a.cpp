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

int64_t solve(int64_t L, int64_t R) {
	string r = to_string(R);
	int64_t low = stoll(string("10000000000").substr(0, r.length()));
	int64_t ans = R - max(low, L) + 1;
	if (ans < low) {
		int64_t high = low - 1;
		low = max({ low / 10, L, R / 10 + 1, (R % low) + 1 });
		ans += max(int64_t(0), high - low + 1);
	}
	return ans;
}

int main() {
	int64_t T, L, R;
	cin >> T;
	for (int tt = 0; tt < T; ++tt) {
		cin >> L >> R;
		int64_t ans = solve(L, R);
		cout << ans << endl;
	}
	return 0;
}
