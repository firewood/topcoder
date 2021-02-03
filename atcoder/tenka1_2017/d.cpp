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

LL solve(long long N, long long K, std::vector<long long> &A, std::vector<long long> &B) {
	auto calc = [&](LL x) -> LL {
		LL sum = 0;
		for (int i = 0; i < N; i++) {
			if ((A[i] & x) == A[i]) {
				sum += B[i];
			}
		}
		return sum;
	};
	LL ans = calc(K);
	for (LL b = 2; b <= K; b <<= 1) {
		if (b & K) {
			ans = max(ans, calc((K & ~b) | (b - 1)));
		}
	}
	return ans;
}

int main() {
    long long N, K;
	std::cin >> N >> K;
	std::vector<long long> A(N), B(N);
	for (int i = 0; i < N; i++) {
		std::cin >> A[i] >> B[i];
	}
	cout << solve(N, K, A, B) << endl;
	return 0;
}
