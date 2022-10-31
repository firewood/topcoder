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

map<int64_t, int64_t> memo;

int64_t solve(int64_t N) {
	if (memo.find(N) == memo.end()) {
		memo[N] = solve(N / 3) + solve(N / 2);
	}
	return memo[N];
}

int main() {
	int64_t N;
	std::cin >> N;
	memo[0] = 1;
	cout << solve(N) << endl;
	return 0;
}
