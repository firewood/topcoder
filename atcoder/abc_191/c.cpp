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

int solve(long long H, long long W, std::vector<std::string> &S) {
	int ans = 0;
	for (int i = 1; i < H; ++i) {
		bool f = false;
		for (int j = 0; j < W; ++j) {
			if (S[i - 1][j] == S[i][j]) {
				f = false;
			} else {
				ans += !f;
				f = true;
			}
		}
	}
	for (int j = 1; j < W; ++j) {
		bool f = false;
		for (int i = 0; i < H; ++i) {
			if (S[i][j - 1] == S[i][j]) {
				f = false;
			} else {
				ans += !f;
				f = true;
			}
		}
	}
	return ans;
}

int main() {
    long long H, W;
	std::cin >> H >> W;
	std::vector<std::string> S(H);
	for (int i = 0; i < H; i++) {
		std::cin >> S[i];
	}
	cout << solve(H, W, S) << endl;
	return 0;
}
