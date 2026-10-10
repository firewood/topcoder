#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <deque>
#include <fstream>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>

using namespace std;

int64_t solve(int64_t N, int64_t M, vector<int64_t> A, vector<int64_t> B) {
	int64_t ans = 0;

	vector<vector<int64_t>> py(N * 3 + 2, vector<int64_t>(N * 3 + 2));
	vector<vector<int64_t>> px(N * 3 + 2, vector<int64_t>(N * 3 + 2));
	vector<vector<int64_t>> sum(N * 3 + 2, vector<int64_t>(N * 3 + 2));

	int64_t adj = 0;
	for (int64_t i = 0; i < N; ++i) {
		for (int64_t j = 0; j < N; ++j) {
			int64_t value = (A[i] * B[j]) % M;
			py[N + i + 1 - N][N + j + 1 - N] += -value;
			px[N + i + 0 - N][N + j + 1 + N] += value;
			adj += value * N;
		}
	}
	for (int64_t i = 1; i < N * 3; ++i) {
		for (int64_t j = 1; j < N * 3; ++j) {
			py[i][j] += py[i - 1][j - 1];
			px[i][j] += px[i - 1][j + 1];
			sum[i][j] += py[i][j] + px[i][j];
		}
	}

	for (int64_t i = 0; i < N * 3; ++i) {
		for (int64_t j = 0; j < N * 3; ++j) {
			sum[i + 1][j + 1] += sum[i][j + 1] + sum[i + 1][j] - sum[i][j];
		}
	}

	for (int64_t i = 0; i < N; ++i) {
		for (int64_t j = 0; j < N; ++j) {
			ans ^= (sum[N + i][N + j] + i * N + j + adj);
		}
	}

	return ans;
}

int main() {
	int64_t N, M;
	cin >> N >> M;
	vector<int64_t> A(N), B(N);
	for (int64_t i = 0; i < N; ++i) {
		cin >> A[i];
	}
	for (int64_t i = 0; i < N; ++i) {
		cin >> B[i];
	}
	auto ans = solve(N, M, A, B);
	cout << ans << endl;
}
