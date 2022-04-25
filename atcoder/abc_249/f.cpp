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

static const int64_t INF = 1LL << 60;

int64_t solve(int64_t N, int64_t K, std::vector<int64_t> t, std::vector<int64_t> y) {
	int64_t a = K >= N ? 0 : -INF, b = -INF, sum = 0;
	priority_queue<int64_t, vector<int64_t>, greater<>> qk;
	priority_queue<int64_t, vector<int64_t>> qd;
	auto remove_from_discard_queue = [&]() {
		if (!qd.empty()) {
			int64_t top = qd.top();
			qd.pop();
			sum += top;
			qk.emplace(top);
		}
	};
	for (int i = N - 1; i >= 0; --i) {
		if (t[i] == 1) {
			a = max(a, y[i] + sum);
			--K;
			if (qd.size() > K) {
				remove_from_discard_queue();
				b = sum;
			}
			if (K < 0) {
				b = -INF;
				break;
			}
		} else {
			if (y[i] < 0) {
				qd.emplace(y[i]);
			} else {
				sum += y[i];
			}
			if (qd.size() > K) {
				remove_from_discard_queue();
			}
			if (!qd.empty() && !qk.empty() && qd.top() > qk.top()) {
				remove_from_discard_queue();
				int64_t top = qk.top();
				qk.pop();
				sum -= top;
				qd.emplace(top);
			}
			b = sum;
		}
	}
	return max(a, b);
}

int main() {
	int64_t N, K;
	std::cin >> N >> K;
	std::vector<int64_t> t(N), y(N);
	for (int i = 0; i < N; i++) {
		std::cin >> t[i] >> y[i];
	}
	cout << solve(N, K, t, y) << endl;
	return 0;
}
