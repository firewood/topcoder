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

int64_t solve(int64_t N, std::vector<int64_t>& A) {
	int64_t ans = 0;
	deque<II> q;
	A.emplace_back(0);
	for (int i = 0; i <= N; ++i) {
		int64_t a = A[i], pos = i;
		while (!q.empty()) {
			int64_t value = q.front().first, index = q.front().second;
			if (value <= a) {
				break;
			}
			q.pop_front();
			pos = index;
			ans = max(ans, (i - index) * value);
		}
		q.push_front({ a, pos });
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
	cout << solve(N, A) << endl;
	return 0;
}
