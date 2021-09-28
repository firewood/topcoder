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

int64_t solve(int64_t N, std::vector<int64_t> A, int64_t X) {
	int64_t sum = accumulate(A.begin(), A.end(), int64_t(0));
	int64_t t = X / sum, ans = t * N;
	X -= t * sum;
	for (int i = 0; X >= 0; ++i) {
		++ans;
		X -= A[i % N];
	}
	return ans;
}

int main() {
	int64_t N, X;
	std::cin >> N;
	std::vector<int64_t> A(N);
	for (int i = 0; i < N; i++) {
		std::cin >> A[i];
	}
	std::cin >> X;
	cout << solve(N, A, X) << endl;
	return 0;
}
