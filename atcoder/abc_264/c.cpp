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

#ifdef _MSC_VER
#define popcount __popcnt
#else
#define popcount __builtin_popcount
#endif

bool solve(int H1, int W1, int H2, int W2, const vector<vector<int>>& a, const vector<vector<int>>& b) {
	auto check = [&](int hb, int wb) {
		int ai = 0;
		for (int i = 0; i < H2; ++i) {
			while ((hb & (1 << ai)) == 0) {
				++ai;
			}
			int aj = 0;
			for (int j = 0; j < W2; ++j) {
				while ((wb & (1 << aj)) == 0) {
					++aj;
				}
				if (a[ai][aj] != b[i][j]) {
					return false;
				}
				++aj;
			}
			++ai;
		}
		return true;
	};

	int hsz = 1 << H1, wsz = 1 << W1;
	for (int hb = 1; hb < hsz; ++hb) {
		if (popcount(hb) == H2) {
			for (int wb = 1; wb < wsz; ++wb) {
				if (popcount(wb) == W2) {
					if (check(hb, wb)) {
						return true;
					}
				}
			}
		}
	}
	return false;
}

int main() {
	int H1, W1, H2, W2;
	cin >> H1 >> W1;
	vector<vector<int>> a(H1, vector<int>(W1));
	for (int i = 0; i < H1; ++i) {
		for (int j = 0; j < W1; ++j) {
			cin >> a[i][j];
		}
	}
	cin >> H2 >> W2;
	vector<vector<int>> b(H2, vector<int>(W2));
	for (int i = 0; i < H2; ++i) {
		for (int j = 0; j < W2; ++j) {
			cin >> b[i][j];
		}
	}
	bool ans = solve(H1, W1, H2, W2, a, b);
	cout << (ans ? "Yes" : "No") << endl;
	return 0;
}
