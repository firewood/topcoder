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

string solve(int64_t N) {
	string s = to_string(N + 100000 - 1);
	return string(2, s[0]) + s[1] + s[2] + s[3] + s[3] + s[4] + s[5] + s[4];
}

int main() {
	int64_t N;
	std::cin >> N;
	cout << solve(N) << endl;
	return 0;
}
