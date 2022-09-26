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

vector<int64_t> solve(int64_t N, int64_t K, std::vector<int64_t> A) {
	vector<int64_t> ans(N);
	priority_queue<int64_t, vector<int64_t>, greater<>> q;
	int64_t cnt = 0;
	for (int i = 0; i < N; ++i) {
		if (A[i] > 0) {
			++cnt;
			q.push(A[i]);
		}
	}
	int64_t r = K, prev = 0, x = -1;
	while (!q.empty()) {
		int64_t top = q.top(), d = top - prev;
		int64_t rc = r / cnt;
		if (rc <= d) {
			x = prev + rc;
			r -= rc * cnt;
			break;
		}
		r -= d * cnt;
		prev = top;
		while (!q.empty() && q.top() == top) {
			--cnt;
			q.pop();
		}
	}
	for (int i = 0; i < N; ++i) {
		A[i] = max(int64_t(0), A[i] - x);
	}
	for (int i = 0; i < N; ++i) {
		if (A[i] > 0 && r > 0) {
			--A[i];
			--r;
		}
	}
	return A;
}

int main() {
	int64_t N, K;
	std::cin >> N >> K;
	std::vector<int64_t> A(N);
	for (int i = 0; i < N; i++) {
		std::cin >> A[i];
	}
	vector<int64_t> ans = solve(N, K, A);
	if (!ans.empty()) {
		for (size_t i = 0; i < ans.size(); ++i) {
			if (i) cout << " ";
			cout << ans[i];
		}
		cout << endl;
	}
	return 0;
}
