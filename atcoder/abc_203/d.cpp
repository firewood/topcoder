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

int solve(int N, int K, vector<vector<int>>& A) {
	int left = -1, right = 1 << 30;
	int m = (K * K + 1) / 2;
	auto possible = [&](int t) -> bool {
		// 2次元累積和
		vector<vector<int>> sum(N + 1, vector<int>(N + 1));
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; ++j) {
				sum[i + 1][j + 1] = sum[i][j + 1] + sum[i + 1][j] - sum[i][j] + (A[i][j] <= t);
			}
		}
		for (int i = 0; i <= N - K; i++) {
			for (int j = 0; j <= N - K; ++j) {
				if (sum[i + K][j + K] - sum[i][j + K] - sum[i + K][j] + sum[i][j] >= m) {
					return true;
				}
			}
		}
		return false;
	};
	while (right - left > 1) {
		int mid = (left + right) / 2;
		if (possible(mid)) {
			right = mid;
		} else {
			left = mid;
		}
	}
	return right;
}

int main() {
	int N, K;
	cin >> N >> K;
	vector<vector<int>> A(N, vector<int>(N));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; ++j) {
			cin >> A[i][j];
		}
	}
	cout << solve(N, K, A) << endl;
	return 0;
}
