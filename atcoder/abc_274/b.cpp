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

vector<int> solve(int64_t H, int64_t W, std::vector<std::string> C) {
	vector<int> cnt(W);
	for (int i = 0; i < H; ++i) {
		for (int j = 0; j < W; ++j) {
			cnt[j] += C[i][j] == '#';
		}
	}
	return cnt;
}

int main() {
	int64_t H, W;
	std::cin >> H >> W;
	std::vector<std::string> C(H);
	for (int i = 0; i < H; i++) {
		std::cin >> C[i];
	}
	vector<int> ans = solve(H, W, C);
	for (size_t i = 0; i < ans.size(); ++i) {
		if (i) cout << " ";
		cout << ans[i];
	}
	cout << endl;
	return 0;
}
