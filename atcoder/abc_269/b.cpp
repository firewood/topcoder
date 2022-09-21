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

void solve(std::vector<std::string> S) {
	int a = 1e9, b = -1, c = 1e9, d = -1;
	for (int i = 0; i < S.size(); ++i) {
		for (int j = 0; j < S[i].length(); ++j) {
			if (S[i][j] != '.') {
				a = min(a, i);
				b = max(b, i);
				c = min(c, j);
				d = max(d, j);
			}
		}
	}
	cout << (a + 1) << " " << (b + 1) << endl;
	cout << (c + 1) << " " << (d + 1) << endl;
}

int main() {
	std::vector<std::string> S(10);
	for (int i = 0; i < 10; i++) {
		std::cin >> S[i];
	}
	solve(S);
	return 0;
}
