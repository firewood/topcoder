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

void solve(int64_t N) {
	vector<vector<int>> a(N, vector<int>(N, -1));

	for (int i = 0; i < N - 1; ++i) {
		for (int j = i + 1; j < N; ++j) {
			for (int k = 1, b = 1; ; ++k, b <<= 1) {
				if (((i ^ j) & b) != 0) {
					a[i][j] = k;
					break;
				}
			}
		}
	}

	for (int i = 0; i < N - 1; ++i) {
		for (int j = i + 1; j < N; ++j) {
			if (j > i + 1) cout << " ";
			cout << a[i][j];
		}
		cout << endl;
	}
}

int main() {
	int64_t N;
	std::cin >> N;
	solve(N);
	return 0;
}
