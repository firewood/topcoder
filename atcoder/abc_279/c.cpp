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

bool solve(int64_t H, int64_t W, std::vector<std::string> S, std::vector<std::string> T) {
	auto build = [&](const vector<string>& a) {
		vector<string> b;
		for (int j = 0; j < W; ++j) {
			string s;
			for (int i = 0; i < H; ++i) {
				s += a[i][j];
			}
			b.emplace_back(s);
		}
		sort(b.begin(), b.end());
		return b;
	};
	return build(S) == build(T);
}

int main() {
	int64_t H, W;
	std::cin >> H >> W;
	std::vector<std::string> S(H);
	for (int i = 0; i < H; i++) {
		std::cin >> S[i];
	}
	std::vector<std::string> T(H);
	for (int i = 0; i < H; i++) {
		std::cin >> T[i];
	}
	cout << (solve(H, W, S, T) ? "Yes" : "No") << endl;
	return 0;
}
