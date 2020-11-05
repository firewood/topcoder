#include <algorithm>
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

typedef long long LL;

LL solve(long long N, std::vector<long long> &A) {
	if (A[0] != 0) return -1;
	LL ans = 0;
	for (LL i = 1; i < N; ++i) {
		if (A[i - 1] + 1 < A[i]) {
			return -1;
		}
		ans += A[i - 1] + 1 == A[i] ? 1 : A[i];
	}
	return ans;
}

int main() {
    long long N;
	std::cin >> N;
	std::vector<long long> A(N);
	for (int i = 0; i < N; i++) {
		std::cin >> A[i]; // A[i]--;
	}
	LL ans = solve(N, A);
	cout << ans << endl;
	return 0;
}
