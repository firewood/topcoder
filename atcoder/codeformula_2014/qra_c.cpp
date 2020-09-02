#ifdef __GNUC__
#pragma GCC diagnostic ignored "-Wunused-result"
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#endif

#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <sstream>
#include <numeric>
#include <set>
#include <vector>

using namespace std;

typedef long long LL;

void solve(int n, int k, std::vector<std::vector<int>> &a) {
	vector<vector<int>> visit(n, vector<int>(k));
	vector<int> used(1000000);
	int cursor = k;
	for (int i = 0; i < n; ++i) {
		set<int> s;
		for (int j = 0; j < cursor; ++j) {
			int row = j % n, col = j / n;
			if (row <= i && !visit[row][col]) {
				visit[row][col] = 1;
				if (used[a[row][col]]) {
					++cursor;
				} else {
					used[a[row][col]] = 1;
					s.emplace(a[row][col]);
				}
			}
		}
		string sep;
		for (int x : s) {
			cout << sep << x;
			sep = " ";
		}
		cout << endl;
	}
}

int main() {
	int n, k;
	cin >> n >> k;
	std::vector<std::vector<int>> a(n, std::vector<int>(k));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < k; j++) {
			cin >> a[i][j];
		}
	}
	solve(n, k, a);
	return 0;
}
