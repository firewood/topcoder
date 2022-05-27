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

int64_t solve(int64_t N, int64_t L, std::vector<int64_t> A) {
	int64_t ans = 0;
	priority_queue<int64_t, vector<int64_t>, greater<>> q;
	for (int i = 0; i < N; ++i) {
		q.emplace(A[i]);
	}
	int64_t r = L - accumulate(A.begin(), A.end(), int64_t(0));
	if (r > 0) {
		q.emplace(r);
	}
	while (q.size() > 1) {
		int64_t a = q.top();
		q.pop();
		int64_t b = q.top();
		q.pop();
		int64_t c = a + b;
		ans += c;
		q.emplace(c);
	}
	return ans;
}

int main() {
	int64_t N, L;
	std::cin >> N >> L;
	std::vector<int64_t> A(N);
	for (int i = 0; i < N; i++) {
		std::cin >> A[i];
	}
	cout << solve(N, L, A) << endl;
	return 0;
}
