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

LL solve(long long N, std::vector<long long> &A, std::vector<long long> &B) {
	sort(A.begin(), A.end());
	sort(B.begin(), B.end());
	LL ans = 0;
	for (int i = 0; i < N; i++) {
		ans += abs(B[i] - A[i]);
	}
	return ans;
}

int main() {
#if DEBUG
	freopen("in_1.txt", "r", stdin);
#endif
	long long N;
	std::cin >> N;
	std::vector<long long> A(N), B(N);
	for (int i = 0; i < N; i++) {
		std::cin >> A[i];
	}
	for (int i = 0; i < N; i++) {
		std::cin >> B[i];
	}
	cout << solve(N, A, B) << endl;
	return 0;
}
