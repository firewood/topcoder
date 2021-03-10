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

static const LL INF = 1LL << 60;

LL solve(long long N, std::vector<long long>& A) {
	LL ans = 0;
	vector<LL> cnt(401);
	for (int i = 0; i < N; i++) {
		cnt[A[i] + 200] += 1;
	}
	for (LL i = 0; i <= 400; i++) {
		for (LL j = i + 1; j <= 400; ++j) {
			ans += (j - i) * (j - i) * cnt[i] * cnt[j];
		}
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
