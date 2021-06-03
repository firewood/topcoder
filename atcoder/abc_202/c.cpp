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

LL solve(long long N, std::vector<long long> &A, std::vector<long long> &B, std::vector<long long> &C) {
	LL ans = 0;
	map<LL, LL> ma;
	for (int i = 0; i < N; i++) {
		ma[A[i]] += 1;
	}
	for (int i = 0; i < N; i++) {
		ans += ma[B[C[i] - 1]];
	}
	return ans;
}

int main() {
	long long N;
	std::cin >> N;
	std::vector<long long> A(N), B(N), C(N);
	for (int i = 0; i < N; i++) {
		std::cin >> A[i];
	}
	for (int i = 0; i < N; i++) {
		std::cin >> B[i];
	}
	for (int i = 0; i < N; i++) {
		std::cin >> C[i];
	}
	cout << solve(N, A, B, C) << endl;
	return 0;
}
