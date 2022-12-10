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

void solve(int64_t N, int64_t T, std::vector<int64_t> A) {
	int64_t r = T % accumulate(A.begin(), A.end(), int64_t(0));
	for (int i = 0; i < N; ++i) {
		if (r < A[i]) {
			cout << (i + 1) << " " << r << endl;
			return;
		}
		r -= A[i];
	}
}

int main() {
	int64_t N, T;
	std::cin >> N >> T;
	std::vector<int64_t> A(N);
	for (int i = 0; i < N; i++) {
		std::cin >> A[i];
	}
	solve(N, T, A);
	return 0;
}
