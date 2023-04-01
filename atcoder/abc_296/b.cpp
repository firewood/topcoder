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

string solve(std::vector<std::string> S) {
	for (int i = 0; i < 8; ++i) {
		for (int j = 0; j < 8; ++j) {
			if (S[i][j] != '.') {
				return string(1, char('a' + j)) + string(1, char('0' + 8 - i));
			}
		}
	}
}

int main() {
	std::vector<std::string> S(8);
	for (int i = 0; i < 8; i++) {
		std::cin >> S[i];
	}
	cout << solve(S) << endl;
	return 0;
}
