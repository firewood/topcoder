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

vector<string> solve(int64_t R, int64_t C, std::vector<std::string> B) {
	vector<string> ans = B;
	for (int i = 0; i < R; ++i) {
		for (int j = 0; j < C; ++j) {
			int d = B[i][j] - '0';
			if (d >= 0 && d <= 9) {
				for (int k = 0; k < R; ++k) {
					for (int l = 0; l < C; ++l) {
						if (abs(i - k) + abs(j - l) <= d) {
							ans[k][l] = '.';
						}
					}
				}
			}
		}
	}
	return ans;
}

int main() {
	int64_t R, C;
	std::cin >> R >> C;
	std::vector<std::string> B(R);
	for (int i = 0; i < R; i++) {
		std::cin >> B[i];
	}
	vector<string> ans = solve(R, C, B);
	for (auto s : ans) {
		cout << s << endl;
	}
	return 0;
}
