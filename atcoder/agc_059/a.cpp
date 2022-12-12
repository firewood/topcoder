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

vector<int> solve(int N, int Q, const std::string& S, const std::vector<int>& L, const std::vector<int>& R) {
	vector<int> ans(Q), cnt(N);
	for (int i = 1; i < N; ++i) {
		cnt[i] = cnt[i - 1] + (S[i] != S[i - 1]);
	}
	for (int i = 0; i < Q; ++i) {
		ans[i] = (cnt[R[i]] - cnt[L[i]] + (S[L[i]] != S[R[i]]) + 1) / 2;
	}
	return ans;
}

int main() {
	int N, Q;
	std::string S;
	std::cin >> N >> Q >> S;
	std::vector<int> L(Q), R(Q);
	for (int i = 0; i < Q; i++) {
		std::cin >> L[i] >> R[i];
		--L[i]; --R[i];
	}
	vector<int> ans = solve(N, Q, S, L, R);
	for (size_t i = 0; i < ans.size(); ++i) {
		cout << ans[i] << endl;
	}
	return 0;
}
