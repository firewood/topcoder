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

int64_t solve(int64_t N, std::vector<int64_t> A, std::vector<int64_t> B) {
	if (A == B) return 0;
	int64_t mn = 1LL << 60;
	for (int i = 0; i < N; ++i) {
		if (A[i] > B[i]) {
			mn = min(mn, B[i]);
		}
	}
	return accumulate(A.begin(), A.end(), int64_t(0)) - mn;
}

int main() {
	int64_t N;
	std::cin >> N;
	std::vector<int64_t> A(N), B(N);
	for (int i = 0; i < N; i++) {
		std::cin >> A[i] >> B[i];
	}
	cout << solve(N, A, B) << endl;
	return 0;
}
