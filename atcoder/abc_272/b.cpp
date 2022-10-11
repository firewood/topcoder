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

bool solve(int N, int M, vector<vector<int>> a) {
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			auto check = [&]() {
				for (int k = 0; k < M; ++k) {
					if (a[k][i] == 1 && a[k][j] == 1) {
						return true;
					}
				}
				return false;
			};
			if (!check()) {
				return false;
			}
		}
	}
	return true;
}

int main() {
	int N, M, k, x;
	cin >> N >> M;
	std::vector<vector<int>> a(M, vector<int>(N));
	for (int i = 0; i < M; i++) {
		cin >> k;
		for (int j = 0; j < k; ++j) {
			cin >> x;
			a[i][x - 1] = 1;
		}
	}
	bool ans = solve(N, M, a);
	cout << (ans ? "Yes" : "No") << endl;
	return 0;
}
