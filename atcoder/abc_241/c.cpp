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

bool solve(int64_t N, std::vector<std::string> S) {
	auto check = [&](int y, int x, int dy, int dx) {
		int c = 0;
		for (int i = 0; i < 6; ++i) {
			c += S[y + dy * i][x + dx * i] == '#';
		}
		return c >= 4;
	};
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			if (i <= N - 6 && check(i, j, 1, 0)) {
				return true;
			}
			if (j <= N - 6 && check(i, j, 0, 1)) {
				return true;
			}
			if (i <= N - 6 && j <= N - 6 && check(i, j, 1, 1)) {
				return true;
			}
			if (i >= 5 && j <= N - 6 && check(i, j, -1, 1)) {
				return true;
			}
		}
	}
	return false;
}

int main() {
	int64_t N;
	std::cin >> N;
	std::vector<std::string> S(N);
	for (int i = 0; i < N; i++) {
		std::cin >> S[i];
	}
	cout << (solve(N, S) ? "Yes" : "No") << endl;
	return 0;
}
