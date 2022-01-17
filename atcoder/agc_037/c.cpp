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

typedef pair<int64_t, int64_t> II;

int64_t solve(int64_t N, std::vector<int64_t> A, std::vector<int64_t> B) {
	int64_t ans = 0;
	priority_queue<II> q;
	for (int i = 0; i < N; ++i) {
		q.emplace(II(B[i], i));
	}
	while (!q.empty()) {
		int64_t i = q.top().second;
		q.pop();
		if (B[i] == A[i]) {
			continue;
		}
		int64_t d = B[(i - 1 + N) % N] + B[(i + 1) % N];
		int64_t c = (B[i] - A[i]) / d;
		if (c <= 0) {
			return -1;
		}
		B[i] -= c * d;
		q.emplace(II(B[i], i));
		ans += c;
	}
	return ans;
}

int main() {
	int64_t N;
	std::cin >> N;
	std::vector<int64_t> A(N);
	for (int i = 0; i < N; i++) {
		std::cin >> A[i];
	}
	std::vector<int64_t> B(N);
	for (int i = 0; i < N; i++) {
		std::cin >> B[i];
	}
	cout << solve(N, A, B) << endl;
	return 0;
}
