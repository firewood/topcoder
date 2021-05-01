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

int solve(int N, std::vector<int>& A, std::vector<int>& B, std::vector<int>& C, std::vector<int>& D, std::vector<int>& E) {
	vector<vector<int>> v = { A, B, C, D, E };
	int left = 0, right = 1 << 30;
	auto possible = [&](int t) -> bool {
		vector<int> f(1 << 5);
		for (int i = 0; i < N; ++i) {
			int b = 0;
			for (int j = 0; j < 5; ++j) {
				if (v[j][i] >= t) {
					b |= 1 << j;
				}
			}
			f[b] = 1;
		}
		for (int i = 0; i < 1 << 5; ++i) {
			int a = f[i] ? i : 0;
			for (int j = i; j < 1 << 5; ++j) {
				int b = a | (f[j] ? j : 0);
				for (int k = j; k < 1 << 5; ++k) {
					int c = b | (f[k] ? k : 0);
					if (c == (1 << 5) - 1) return true;
				}
			}
		}
		return false;
	};
	while (right - left > 1) {
		int mid = (left + right) / 2;
		if (possible(mid)) {
			left = mid;
		} else {
			right = mid;
		}
	}
	return left;
}

int main() {
	int N;
	std::cin >> N;
	std::vector<int> A(N), B(N), C(N), D(N), E(N);
	for (int i = 0; i < N; i++) {
		std::cin >> A[i] >> B[i] >> C[i] >> D[i] >> E[i];
	}
	cout << solve(N, A, B, C, D, E) << endl;
	return 0;
}
