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

int64_t calc(int64_t x) {
	int64_t cnt = 0;
	string s = to_string(x);
	int top = s[0] - '0';
	int len = s.length();

	if (x >= 10) {
		bool ov = false;
		for (int i = 1; i < len; ++i) {
			int d = s[i] - '0';
			if (d >= top) {
				ov = true;
			}
			if (ov) {
				d = top - 1;
			}
			cnt = cnt * top + d;
		}
		cnt += 1;
	}

	for (int i = 1; i < len; ++i) {
		for (int j = 1; j <= 9; ++j) {
			if (i == len - 1 && j >= top) {
				break;
			}
			cnt += powl(j, i);
		}
	}

	return cnt;
}

int64_t calc2(int64_t x) {
	int cnt = 0;
	for (int i = 10; i < x; ++i) {
		string s = to_string(i);
		int len = s.length();
		bool ok = true;
		for (int j = 1; j < len; ++j) {
			if (s[j] >= s[0]) {
				ok = false;
				break;
			}
		}
		cnt += ok;
	}
	return cnt;
}

int64_t solve(int64_t L, int64_t R) {
	return calc(R) - calc(L - 1);
}

int main() {
	int64_t L, R;
	std::cin >> L >> R;
	cout << solve(L, R) << endl;
	return 0;
}
