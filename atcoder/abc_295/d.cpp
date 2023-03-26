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

int64_t solve(std::string S) {
	int64_t ans = 0, state = 0;
	map<int64_t, int64_t> m;
	for (auto c : S) {
		m[state] += 1;
		state ^= (1LL << (c - '0'));
		ans += m[state];
	}
	return ans;
}

int main() {
	std::string S;
	std::cin >> S;
	cout << solve(S) << endl;
	return 0;
}
