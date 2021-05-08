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

void solve(int H, int W, vector<vector<int>> &A) {
	vector<int> h(H), v(W);
	for (int i = 0; i < H; ++i) {
		for (int j = 0; j < W; ++j) {
			h[i] += A[i][j];
			v[j] += A[i][j];
		}
	}
	for (int i = 0; i < H; ++i) {
		for (int j = 0; j < W; ++j) {
			if (j) cout << " ";
			cout << h[i] + v[j] - A[i][j];
		}
		cout << endl;
	}
}

int main() {
	int H, W;
	std::cin >> H >> W;
	vector<vector<int>> A(H, vector<int>(W));
	for (int i = 0; i < H; ++i) {
		for (int j = 0; j < W; ++j) {
			cin >> A[i][j];
		}
	}
	solve(H, W, A);
	return 0;
}
