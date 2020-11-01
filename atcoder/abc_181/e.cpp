#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <sstream>
#include <numeric>
#include <queue>
#include <vector>

using namespace std;

typedef long long LL;
static const LL INF = 1LL << 60;

void solve(long long N, long long M, std::vector<long long> &H, std::vector<long long> &W) {
	LL ans = INF;
	sort(H.begin(), H.end());
	sort(W.begin(), W.end());
	vector<LL> fwd(N + 2), rev(N + 4);
	for (LL i = 1; i < N; i += 2) {
		fwd[i + 1] = fwd[i - 1] + H[i] - H[i - 1];
	}
	for (LL i = N - 2; i >= 0; i -= 2) {
		rev[i + 1] = rev[i + 3] + H[i + 1] - H[i];
	}
	LL wi = 0;
	for (LL i = 0; i < N; i += 2) {
		while (wi < M - 1 && (abs(H[i] - W[wi]) >= abs(H[i] - W[wi + 1]))) {
			++wi;
		}
		LL cost = fwd[i] + rev[i + 2] + abs(H[i] - W[wi]);
		ans = min(ans, cost);
	}
	cout << ans << endl;
}

int main() {
	long long N, M;
	std::cin >> N >> M;
	std::vector<long long> H(N);
	for (int i = 0; i < N; i++) {
		std::cin >> H[i];
	}
	std::vector<long long> W(M);
	for (int i = 0; i < M; i++) {
		std::cin >> W[i];
	}
	solve(N, M, H, W);
	return 0;
}
