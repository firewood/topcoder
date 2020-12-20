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

LL solve(long long N, std::vector<long long> &A) {
	LL ans = 0, sum = 0;
	sort(A.begin(), A.end());
	for (LL i = 0; i < N; ++i) {
		ans += A[i] * i - sum;
		sum += A[i];
	}
	return ans;
}

int main() {
    long long N;
	std::cin >> N;
	std::vector<long long> A(N);
	for (int i = 0; i < N; i++) {
		std::cin >> A[i];
	}
	cout << solve(N, A) << endl;
	return 0;
}
