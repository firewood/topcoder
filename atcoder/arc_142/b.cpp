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

bool is_valid(int N, vector<vector<int>>& a) {
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			int p = 0, q = 0;
			for (int y = max(0, i - 1); y <= min(i + 1, N - 1); ++y) {
				for (int x = max(0, j - 1); x <= min(j + 1, N - 1); ++x) {
					if (y == 0 && x == 0) {

					} else {
						p += a[y][x] > a[i][j];
						q += a[y][x] < a[i][j];
					}
				}
			}
			if (p == q) {
				return false;
			}
		}
	}
	return true;
}

vector<vector<int>> solve(int N) {
	vector<vector<int>> ans(N, vector<int>(N));
	int seq = 0;
	for (int i = 0; i < N; i += 2) {
		for (int j = 0; j < N; ++j) {
			ans[i][j] = seq++;
		}
	}
	for (int i = 1; i < N; i += 2) {
		for (int j = 0; j < N; ++j) {
			ans[i][j] = seq++;
		}
	}
	return ans;
}

int main() {
	int64_t N;
	std::cin >> N;

/*
	for (int i = 2; i <= 500; ++i) {
		vector<vector<int>> ans = solve(i);
		if (!is_valid(i, ans)) {
			cout << "-1" << endl;
		}
	}
*/

	vector<vector<int>> ans = solve(N);

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			if (j)cout << " ";
			cout << (ans[i][j] + 1);
		}
		cout << endl;
	}
	return 0;
}
