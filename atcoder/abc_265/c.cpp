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

bool solve(int H, int W, const vector<string> &G, int &i, int &j) {
	vector<vector<int>> v(H, vector<int>(W));
	while (!v[i][j]) {
		v[i][j] = 1;
		switch (G[i][j]) {
		case 'U':
			if (i == 0) return true;
			--i;
			break;
		case 'D':
			if (i == H - 1) return true;
			++i;
			break;
		case 'L':
			if (j == 0) return true;
			--j;
			break;
		case 'R':
			if (j == W - 1) return true;
			++j;
			break;
		}
	}
	return false;
}

int main() {
	int H, W, i = 0, j = 0;
	std::cin >> H >> W;
	std::vector<std::string> G(H);
	for (int i = 0; i < H; i++) {
		std::cin >> G[i];
	}
	if (solve(H, W, G, i, j)) {
		cout << i + 1 << " " << j + 1 << endl;
	} else {
		cout << "-1" << endl;
	}
	return 0;
}
