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

int64_t solve(int64_t N, std::vector<int64_t> A, std::vector<int64_t> B, std::vector<int64_t> C, std::vector<int64_t> D) {
	int ans = 0;
	vector<vector<int>> u(101, vector<int>(101));
	for (int i = 0; i < N; ++i) {
		for (int a = A[i]; a < B[i]; ++a) {
			fill(u[a].begin() + C[i], u[a].begin() + D[i], 1);
		}
	}
	for (int i = 0; i <= 100; ++i) {
		ans += accumulate(u[i].begin(), u[i].end(), 0);
	}
	return ans;
}

int main() {
	int64_t N;
	std::cin >> N;
	std::vector<int64_t> A(N), B(N), C(N), D(N);
	for (int i = 0; i < N; i++) {
		std::cin >> A[i] >> B[i] >> C[i] >> D[i];
	}
	cout << solve(N, A, B, C, D) << endl;
	return 0;
}
