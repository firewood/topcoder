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

vector<int> solve(int64_t N, int64_t K, std::vector<int64_t> A, int64_t Q, std::vector<int64_t> l, std::vector<int64_t> r) {
	vector<int> ans(Q, 1);
	vector<vector<int64_t>> sum(N + 1);
	sum.front().resize(K);
	for (int i = 0; i < N; ++i) {
		sum[i + 1] = sum[i];
		sum[i + 1][i % K] += A[i];
	}
	for (int i = 0; i < Q; ++i) {
		int& ok = ans[i];
		int64_t d = sum[r[i]][0] - sum[l[i]][0];
		for (int j = 1; j < K; ++j) {
			if ((sum[r[i]][j] - sum[l[i]][j]) != d) {
				ok = false;
			}
		}
	}
	return ans;
}

int main() {
	int64_t N, K, Q;
	std::cin >> N >> K;
	std::vector<int64_t> A(N);
	for (int i = 0; i < N; i++) {
		std::cin >> A[i];
	}
	std::cin >> Q;
	std::vector<int64_t> l(Q), r(Q);
	for (int i = 0; i < Q; i++) {
		std::cin >> l[i] >> r[i];
		--l[i];
	}
	for (auto ans : solve(N, K, A, Q, l, r)) {
		cout << (ans ? "Yes" : "No") << endl;
	}
	return 0;
}
