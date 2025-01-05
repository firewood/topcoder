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

string solve(std::string N) {
	size_t len = N.length();
	if (len <= 4) {
		size_t n = stoi(N);
		auto check = [](int64_t x) {
			string s = to_string(x);
			int cnt = 0;
			for (int k = 0; k < s.length(); ++k) {
				cnt += s[k] - '0';
			}
			return (x % cnt) == 0;
		};
		for (int i = n; i < 2 * n; ++i) {
			if (check(i) && check(i + 1)) {
				return to_string(i);
			}
		}
	} else {
		const string ss[] = { "17", "20", "35", "44", "53", "62" };
		for (const auto & prefix : ss) {
			string s = prefix + string(len - 2, '0');
			if (s >= N) return s;
		}
		return "116" + string(len - 2, '0');
	}
	return "-1";
}

int main() {
	std::string N;
	std::cin >> N;
	cout << solve(N) << endl;
	return 0;
}
