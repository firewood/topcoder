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

int solve(int H, int W, std::vector<std::string> S) {
	int y = -1, x = -1;
	for (int i = 0; i < H; ++i) {
		for (int j = 0; j < W; ++j) {
			if (S[i][j] != '-') {
				if (y >= 0) {
					return abs(y - i) + abs(x - j);
				}
				y = i;
				x = j;
			}
		}
	}
	return -1;
}

int main() {
	int H, W;
	std::cin >> H >> W;
	std::vector<std::string> S(H);
	for (int i = 0; i < H; i++) {
		std::cin >> S[i];
	}
	cout << solve(H, W, S) << endl;
	return 0;
}
