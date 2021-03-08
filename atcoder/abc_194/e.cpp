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

LL solve(long long N, long long M, std::vector<long long> &A) {
	LL ans = INF;
	vector<LL> vis(1500002, -1);
	for (LL i = 0; i < N; i++) {
		LL a = A[i];
		if (i - vis[a] > M) {
			ans = min(ans, a);
		}
		vis[a] = i;
	}
	for (LL i = 0; i < ans; ++i) {
		if (N - vis[i] > M) {
			ans = i;
			break;
		}
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
	cout << solve(N, M, A) << endl;
	return 0;
}
