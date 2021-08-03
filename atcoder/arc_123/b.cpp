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

int64_t solve(int64_t N, std::vector<int64_t> A, std::vector<int64_t> B, std::vector<int64_t> C) {
	int64_t ans = 0;
	sort(A.rbegin(), A.rend());
	sort(B.rbegin(), B.rend());
	sort(C.rbegin(), C.rend());
	for (int ia = 0, ib = 0, ic = 0; ic < N; ++ia, ++ib, ++ic) {
		while (ib < N && B[ib] >= C[ic]) {
			++ib;
		}
		if (ib >= N) {
			break;
		}
		while (ia < N && A[ia] >= B[ib]) {
			++ia;
		}
		if (ia >= N) {
			break;
		}
		++ans;
	}
	return ans;
}

int main() {
	int64_t N;
	std::cin >> N;
	std::vector<int64_t> A(N);
	for (int i = 0; i < N; i++) {
		std::cin >> A[i];
	}
	std::vector<int64_t> B(N);
	for (int i = 0; i < N; i++) {
		std::cin >> B[i];
	}
	std::vector<int64_t> C(N);
	for (int i = 0; i < N; i++) {
		std::cin >> C[i];
	}
	cout << solve(N, std::move(A), std::move(B), std::move(C)) << endl;
	return 0;
}
