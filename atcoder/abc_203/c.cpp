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
typedef pair<LL, LL> II;

LL solve(long long N, long long K, std::vector<long long> &A, std::vector<long long> &B) {
	LL ans = K, p = 0;
	vector<II> v;
	for (int i = 0; i < N; ++i) {
		v.emplace_back(II(A[i], B[i]));
	}
	sort(v.begin(), v.end());
	while (p < v.size() && ans >= v[p].first) {
		ans += v[p++].second;
	}
	return ans;
}

int main() {
#if _DEBUG
	freopen("in.txt", "r", stdin);
#endif
	long long N, K;
	std::cin >> N >> K;
	std::vector<long long> A(N), B(N);
	for (int i = 0; i < N; i++) {
		std::cin >> A[i] >> B[i];
	}
	cout << solve(N, K, A, B) << endl;
	return 0;
}
