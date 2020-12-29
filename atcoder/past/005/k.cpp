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

typedef long double LD;

LD solve(std::vector<std::string> &S) {
	int st = 0;
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j) {
			if (S[i][j] == '#') {
				st |= (1 << (i * 4 + j));
			}
		}
	}
	vector<LD> dp(1 << 16);
	for (int b = 1; b <= st; ++b) {
		const int dx[5] = { 0, -1, 1, 0, 0 };
		const int dy[5] = { 0, 0, 0, -1, 1 };
		LD mn = 1e10;
		for (int i = 0; i < 4; ++i) {
			for (int j = 0; j < 4; ++j) {
				LD c = 0, tot = 5.0;
				for (int dir = 0; dir < 5; ++dir) {
					int y = i + dy[dir], x = j + dx[dir];
					if (x >= 0 && x < 4 && y >= 0 && y < 4 && (b & (1 << (y * 4 + x))) != 0) {
						c += 1.0;
						tot += dp[b & ~(1 << (y * 4 + x))];
					}
				}
				if (c > 0) {
					mn = min(mn, tot / c);
				}
			}
		}
		dp[b] = mn;
	}
	return dp[st];
}

int main() {
	cout.precision(10);
    std::vector<std::string> S(4);
	for (int i = 0; i < 4; i++) {
		std::cin >> S[i];
	}
	cout << solve(S) << endl;
	return 0;
}
