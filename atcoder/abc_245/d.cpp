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

vector<int64_t> solve(int64_t N, int64_t M, std::vector<int64_t> A, std::vector<int64_t> C) {
	vector<int64_t> ans(M + 1);
	for (int i = M; i >= 0; --i) {
		ans[i] = C[N + i] / A[N];
		for (int j = 0; j <= N; ++j) {
			C[N + i - j] -= ans[i] * A[N - j];
		}
	}
	return ans;
}

int main() {
	int64_t N, M;
	std::cin >> N >> M;
	std::vector<int64_t> A(N + 1);
	for (int i = 0; i < N + 1; i++) {
		std::cin >> A[i];
	}
	std::vector<int64_t> C(N + M + 1);
	for (int i = 0; i < N + M + 1; i++) {
		std::cin >> C[i];
	}
	vector<int64_t> ans = solve(N, M, A, C);
	for (size_t i = 0; i < ans.size(); ++i) {
		if (i) cout << " ";
		cout << ans[i];
	}
	cout << endl;
	return 0;
}
