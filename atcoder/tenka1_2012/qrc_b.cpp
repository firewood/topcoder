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

string solve(std::string s) {
	s += "---";
	string ans = s, suits = "SHDC";
	for (auto suit : suits) {
		string d;
		int pos = 0, cnt = 0;
		while (s[pos] != '-' && cnt < 5) {
			int len = 2;
			if (s[pos + 1] == '1' && s[pos + 2] == '0') {
				len = 3;
			}
			if (s[pos] == suit && (!isdigit(s[pos + 1]) || len == 3)) {
				++cnt;
			} else {
				d += s.substr(pos, len);
			}
			pos += len;
		}
		if (cnt >= 5 && d.length() < ans.length()) {
			ans = d;
		}
	}
	return ans.empty() ? "0" : ans;
}

int main() {
	std::string s;
	std::cin >> s;
	cout << solve(s) << endl;
	return 0;
}
