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

vector<int> solve(int64_t N, int64_t Q, std::vector<int> A, std::vector<int> x) {
	vector<int> ans(Q);
	sort(A.begin(), A.end());
	for (int i = 0; i < Q; ++i) {
		ans[i] = N - (lower_bound(A.begin(), A.end(), x[i]) - A.begin());
	}
	return ans;
}

int main() {
	int64_t N, Q;
	std::cin >> N >> Q;
	std::vector<int> A(N);
	for (int i = 0; i < N; i++) {
		std::cin >> A[i];
	}
	std::vector<int> x(Q);
	for (int i = 0; i < Q; i++) {
		std::cin >> x[i];
	}
	vector<int> ans = solve(N, Q, A, x);
	for (auto x : ans) {
		cout << x << endl;
	}
	return 0;
}
