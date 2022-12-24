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
	int ans = 0;
	for (int i = 0; i < S.length(); ++i) {
		if (i < S.length() - 1 && S[i] == '0' && S[i + 1] == '0') {
			++i;
		}
		++ans;
	}
	return ans;
}

int main() {
	std::string S;
	std::cin >> S;
	cout << solve(S) << endl;
	return 0;
}
