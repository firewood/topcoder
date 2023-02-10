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

int solve(std::string S, int64_t T) {
	int x = count(S.begin(), S.end(), 'R') - count(S.begin(), S.end(), 'L');
	int y = count(S.begin(), S.end(), 'U') - count(S.begin(), S.end(), 'D');
	int d = abs(x) + abs(y);
	int u = count(S.begin(), S.end(), '?');
	return (T == 1) ? (d + u) : max(int(S.length()) % 2, d - u);
}

int main() {
	std::string S;
	int T;
	std::cin >> S >> T;
	cout << solve(S, T) << endl;
	return 0;
}
