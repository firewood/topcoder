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

int64_t solve(int64_t N) {
	int64_t ans = 0;
	string s = to_string(N);
	sort(s.rbegin(), s.rend());
	for (int b = 1; b < (1 << s.length()); ++b) {
		int64_t a[2] = {};
		for (int i = 0; i < s.length(); ++i) {
			int64_t j = (b >> i) & 1;
			a[j] = (a[j] * 10) + s[i] - '0';
		}
		ans = max(ans, a[0] * a[1]);
	}
	return ans;
}

int main() {
	int64_t N;
	std::cin >> N;
	cout << solve(N) << endl;
	return 0;
}
