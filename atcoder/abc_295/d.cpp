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
	int64_t ans = 0;
	map<int, int> m;
	vector<int> cnt(10);
	int state = 0;
	m[0] = 1;
	for (auto c : S) {
		int d = c - '0';
		state ^= (1 << d);
		ans += m[state];
		m[state] += 1;
	}
	return ans;
}

int main() {
	std::string S;
	std::cin >> S;
	cout << solve(S) << endl;
	return 0;
}
