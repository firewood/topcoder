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
	for (char c : S) {
		ans = ans * 26 + c - 'A' + 1;
	}
	return ans;
}

int main() {
	std::string S;
	std::cin >> S;
	cout << solve(S) << endl;
	return 0;
}
