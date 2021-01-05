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

typedef long long LL;

#ifdef _MSC_VER
#include <intrin.h>
inline uint32_t __builtin_clz(unsigned long value)
{
	unsigned long leading_zero = 0;
	_BitScanReverse(&leading_zero, value);
	return 31 - leading_zero;
}
#endif
inline uint32_t calc_log_size(unsigned long size) { return 32 - __builtin_clz(size); }

void solve(int N, int M, int D, std::vector<int> &A) {
	int log_size = calc_log_size(D);
	vector<vector<int>> table(log_size, vector<int>(N + 1));
	vector<int> seq(N + 1);
	iota(seq.begin(), seq.end(), 0);
	for (int i = 0; i < M; ++i) {
		swap(seq[A[i]], seq[A[i] + 1]);
	}
	for (int i = 1; i <= N; ++i) {
		table[0][seq[i]] = i;
	}
	// doubling
	for (int k = 1; k < log_size; ++k) {
		for (int i = 1; i <= N; ++i) {
			table[k][i] = table[k - 1][table[k - 1][i]];
		}
	}
	iota(seq.begin(), seq.end(), 0);
	for (int k = 0; k < log_size; ++k) {
		if (D & (1 << k)) {
			for (int i = 1; i <= N; ++i) {
				seq[i] = table[k][seq[i]];
			}
		}
	}
	for (int i = 1; i <= N; ++i) {
		cout << seq[i] << endl;
	}
}

int main() {
	int N, M, D;
	std::cin >> N >> M >> D;
	std::vector<int> A(M);
	for (int i = 0; i < M; i++) {
		std::cin >> A[i];
	}
	solve(N, M, D, A);
	return 0;
}
