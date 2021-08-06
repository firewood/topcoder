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

string solve(string s) {
	int cnt[10] = {};
	int c = 0;
	for (int i = 0; i < 4; ++i) {
		int a = s[i] - '0';
		cnt[a] += 1;
		if (i > 0) {
			int b = s[i - 1] - '0';
			c += ((b + 1) % 10) == a;
		}
		if (cnt[a] == 4 || c == 3) {
			return "Weak";
		}
	}
	return "Strong";
}

int main() {
	string s;
	std::cin >> s;
	cout << solve(s) << endl;
	return 0;
}
