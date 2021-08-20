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
	for (int i = 0; i <= 9999; ++i) {
		string x = "0000" + to_string(i);
		string y = S;
		x = x.substr(x.length() - 4);
		bool ok = true;
		for (char c : x) {
			int d = c - '0';
			if (y[d] == 'x') {
				ok = false;
			} else {
				y[d] = '?';
			}
		}
		ans += ok && y.find('o') == string::npos;
	}
	return ans;
}

int main() {
	std::string S;
	std::cin >> S;
	cout << solve(S) << endl;
	return 0;
}
