#ifdef __GNUC__
#pragma GCC diagnostic ignored "-Wunused-result"
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#endif

#include <algorithm>
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
typedef long double LD;
typedef pair<LL, LL> II;
typedef pair<LL, II> III;
typedef priority_queue<III, vector<III>, greater<>> Queue;
static const LL INF = 1LL << 60;

void solve(long long N, long long H, long long A, long long B, long long C, long long D, long long E) {
	LL ans = INF;
	for (LL a = 0; a <= N; ++a) {
		double b = (double)(E * (N - a) - (H + a * B)) / (D + E);
		ans = min(ans, a * A + max(0LL, (LL)ceil(b + 1e-9)) * C);
	}
	cout << ans << endl;
}

int main() {
    long long N;
	std::cin >> N;
	long long H;
	std::cin >> H;
	long long A;
	std::cin >> A;
	long long B;
	std::cin >> B;
	long long C;
	std::cin >> C;
	long long D;
	std::cin >> D;
	long long E;
	std::cin >> E;
	solve(N, H, A, B, C, D, E);
	return 0;
}
