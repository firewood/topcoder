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

int solve(std::string S) {
	int ans = 0, f = 1;
	for (size_t i = 0; i < S.length(); ++i) {
		if (i % 2) {
			if (S[i] == '+') {
				ans += f;
				f = 1;
			}
		} else {
			f *= S[i] != '0';
		}
	}
	ans += f;
	return ans;
}

int main() {
	std::string S;
	std::cin >> S;
	cout << solve(S) << endl;
	return 0;
}
