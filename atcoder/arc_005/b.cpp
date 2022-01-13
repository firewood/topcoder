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

string solve(int64_t x, int64_t y, std::string W, std::vector<std::string> c) {
	string ans;
	int dx = 0, dy = 0;
	if (W.find('R') != string::npos) dx = 1;
	if (W.find('L') != string::npos) dx = -1;
	if (W.find('U') != string::npos) dy = -1;
	if (W.find('D') != string::npos) dy = 1;
	for (int i = 0; i < 4; ++i) {
		ans += c[y][x];
		x += dx, y += dy;
		if (x < 0) x = 1, dx = 1;
		if (x >= 9) x = 7, dx = -1;
		if (y < 0) y = 1, dy = 1;
		if (y >= 9) y = 7, dy = -1;
	}
	return ans;
}

int main() {
	int64_t x, y;
	std::string W;
	std::cin >> x >> y >> W;
	--x, --y;
	std::vector<std::string> c(9);
	for (int i = 0; i < 9; i++) {
		std::cin >> c[i];
	}
	cout << solve(x, y, W, c) << endl;
	return 0;
}
