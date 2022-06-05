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

int64_t solve(int64_t N, std::string S) {
	int64_t ans = 0, cnt = 0;
	char prev = 0;
	for (char c : S + ".") {
		if (c == prev) {
			++cnt;
		} else {
			ans += cnt * (cnt + 1) / 2;
			cnt = 0;
		}
		prev = c;
	}
	return ans;
}

int main() {
	int64_t N;
	std::string S;
	std::cin >> N >> S;
	cout << solve(N, S) << endl;
	return 0;
}
