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

bool solve(int64_t R, int64_t C) {
	string b[] = {
		"xxxxxxxxxxxxxxx",
		"x             x",
		"x xxxxxxxxxxx x",
		"x x         x x",
		"x x xxxxxxx x x",
		"x x x     x x x",
		"x x x xxx x x x",
		"x x x x x x x x",
		"x x x xxx x x x",
		"x x x     x x x",
		"x x xxxxxxx x x",
		"x x         x x",
		"x xxxxxxxxxxx x",
		"x             x",
		"xxxxxxxxxxxxxxx"
	};
	return b[R - 1][C - 1] != ' ';
}

int main() {
	int64_t R, C;
	std::cin >> R >> C;
	cout << (solve(R, C) ? "black" : "white") << endl;
	return 0;
}
