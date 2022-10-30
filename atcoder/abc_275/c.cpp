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

int calc(int a, int b) {
	int ax = a % 9, ay = a / 9, bx = b % 9, by = b / 9;
	return (bx - ax) * (bx - ax) + (by - ay) * (by - ay);
};

int64_t solve(std::vector<std::string> S) {
	int64_t ans = 0;
	for (int a = 0; a < 81; ++a) {
		if (S[a / 9][a % 9] == '.') continue;
		for (int b = a + 1; b < 81; ++b) {
			if (S[b / 9][b % 9] == '.') continue;
			for (int c = b + 1; c < 81; ++c) {
				if (S[c / 9][c % 9] == '.') continue;
				for (int d = c + 1; d < 81; ++d) {
					if (S[d / 9][d % 9] == '.') continue;
					ans +=
						calc(a, b) == calc(b, d) &&
						calc(b, d) == calc(d, c) &&
						calc(d, c) == calc(c, a) &&
						calc(c, a) == calc(a, b) &&
						calc(a, d) == calc(b, c);
				}
			}
		}
	}
	return ans;
}

int main() {
	std::vector<std::string> S(9);
	for (int i = 0; i < 9; i++) {
		std::cin >> S[i];
	}
	cout << solve(S) << endl;
	return 0;
}
