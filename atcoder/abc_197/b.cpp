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

int solve(int H, int W, int X, int Y, std::vector<std::string>& S) {
	int ans = S[X][Y] == '.';
	const int dx[4] = { -1,1,0,0 };
	const int dy[4] = { 0,0,-1,1 };
	for (int d = 0; d < 4; ++d) {
		for (int i = 1;; ++i) {
			int nx = X + dx[d] * i;
			int ny = Y + dy[d] * i;
			if (nx < 0 || nx >= H || ny < 0 || ny >= W) break;
			if (S[nx][ny] != '.') break;
			++ans;
		}
	}
	return ans;
}

int main() {
	int H, W, X, Y;
	std::cin >> H >> W >> X >> Y;
	--X, --Y;
	std::vector<std::string> S(H);
	for (int i = 0; i < H; i++) {
		std::cin >> S[i];
	}
	cout << solve(H, W, X, Y, S) << endl;
	return 0;
}
