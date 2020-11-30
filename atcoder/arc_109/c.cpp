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

string solve(int n, int k, std::string s) {
	for (int i = 0; i < k; ++i) {
		if (s.length() % 2) {
			s = s + s;
		}
		string t;
		for (int j = 0; j < s.length(); j += 2) {
			// P, R, S
			char a = min(s[j], s[j + 1]), b = max(s[j], s[j + 1]);
			char win = a == 'P' && b == 'S' ? b : a;
			t += win;
		}
		s = t;
	}
	return s.substr(0, 1);
}

int main() {
	int n, k;
	std::string s;
	std::cin >> n >> k >> s;
	cout << solve(n, k, s) << endl;
	return 0;
}
