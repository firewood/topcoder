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
const LL INF = 1LL << 60;

LL solve(long long N, long long M, std::vector<long long> &A, std::vector<long long> &X, std::vector<long long> &Y) {
	vector<II> v;
	for (int i = 0; i < M; i++) {
		v.emplace_back(II(Y[i], i));
	}
	sort(v.begin(), v.end());

	vector<LL> mp(N, INF);
	for (int i = 0; i < M; i++) {
		LL from = X[v[i].second], to = Y[v[i].second];
		mp[to] = min(mp[to], min(A[from], mp[from]));
	}
	LL ans = -(INF);
	for (int i = 0; i < N; i++) {
		ans = max(ans, A[i] - mp[i]);
	}
	return ans;
}

int main() {
	long long N, M;
	std::cin >> N >> M;
	std::vector<long long> A(N);
	for (int i = 0; i < N; i++) {
		std::cin >> A[i];
	}
	std::vector<long long> X(M);
	std::vector<long long> Y(M);
	for (int i = 0; i < M; i++) {
		std::cin >> X[i]; X[i]--;
		std::cin >> Y[i]; Y[i]--;
	}
	cout << solve(N, M, A, X, Y) << endl;
	return 0;
}
