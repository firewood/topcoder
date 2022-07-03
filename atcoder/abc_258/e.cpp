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

void solve(int64_t N, int64_t Q, int64_t X, std::vector<int64_t> W, std::vector<int64_t> K) {
	vector< int64_t> sum(N * 2 + 2), q, used(N, -1);
	int64_t total = accumulate(W.begin(), W.end(), int64_t(0));
	for (int i = 0; i <= N * 2; ++i) {
		sum[i + 1] = sum[i] + W[i % N];
	}
	int64_t i = 0, offset, period;
	for (int64_t t = 0; ; ++t) {
		if (used[i] >= 0) {
			offset = used[i];
			period = t - used[i];
			break;
		}
		used[i] = t;
		int64_t loops = (X - 1) / total;
		int64_t target = sum[i] + X - loops * total;
		int64_t pos = lower_bound(sum.begin() + i + 1, sum.end(), target) - (sum.begin() + i);
		q.emplace_back(loops * N + pos);
		i = (i + pos) % N;
	}
	for (int i = 0; i < Q; ++i) {
		int64_t ans = 0, k = K[i];
		if (k < offset) {
			ans = q[k];
		} else {
			ans = q[offset + (k - offset) % period];
		}
		cout << ans << endl;
	}
}

int main() {
	int64_t N, Q, X;
	std::cin >> N >> Q >> X;
	std::vector<int64_t> W(N);
	for (int i = 0; i < N; i++) {
		std::cin >> W[i];
	}
	std::vector<int64_t> K(Q);
	for (int i = 0; i < Q; i++) {
		std::cin >> K[i];
		--K[i];
	}
	solve(N, Q, X, W, K);
	return 0;
}
