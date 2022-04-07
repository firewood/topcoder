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

int64_t solve(int64_t N, int64_t K, int64_t X, std::vector<int64_t> A) {
	for (int i = 0; i < N; ++i) {
		int64_t a = min(K, A[i] / X);
		A[i] -= a * X;
		K -= a;
	}
	sort(A.rbegin(), A.rend());
	return accumulate(A.begin() + min(N, K), A.end(), int64_t(0));
}

int main() {
	int64_t N, K, X;
	std::cin >> N >> K >> X;
	std::vector<int64_t> A(N);
	for (int i = 0; i < N; i++) {
		std::cin >> A[i];
	}
	cout << solve(N, K, X, A) << endl;
	return 0;
}
