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

int64_t solve(int64_t H, int64_t W, int64_t K, std::vector<int64_t> A, std::vector<int64_t> B) {
	if ((accumulate(A.begin(), A.end(), 0LL) % K) != (accumulate(B.begin(), B.end(), 0LL) % K)) {
		return -1;
	} else {
		int64_t a = 0, b = 0;
		for (int i = 0; i < H; ++i) {
			a += ((K - 1) * W - A[i]) % K;
		}
		for (int i = 0; i < W; ++i) {
			b += ((K - 1) * H - B[i]) % K;
		}
		return H * W * (K - 1) - max(a, b);
	}
}

int main() {
	int64_t H, W, K;
	std::cin >> H >> W >> K;
	std::vector<int64_t> A(H);
	for (int i = 0; i < H; i++) {
		std::cin >> A[i];
	}
	std::vector<int64_t> B(W);
	for (int i = 0; i < W; i++) {
		std::cin >> B[i];
	}
	cout << solve(H, W, K, A, B) << endl;
	return 0;
}
