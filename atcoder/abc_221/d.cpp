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

vector<int64_t> solve(int64_t N, std::vector<int64_t> A, std::vector<int64_t> B) {
	vector<int64_t> cnt(N);
	int64_t pd = 0, pc = 0;
	vector<II> q;
	for (int i = 0; i < N; ++i) {
		q.emplace_back(II(A[i], 1));
		q.emplace_back(II(A[i] + B[i], -1));
	}
	sort(q.begin(), q.end());
	for (auto kv : q) {
		if (pc > 0) {
			cnt[pc - 1] += kv.first - pd;
		}
		pc += kv.second;
		pd = kv.first;
	}
	return cnt;
}

int main() {
	int64_t N;
	std::cin >> N;
	std::vector<int64_t> A(N), B(N);
	for (int i = 0; i < N; i++) {
		std::cin >> A[i] >> B[i];
	}
	vector<int64_t> ans = solve(N, A, B);
	for (int i = 0; i < N; ++i) {
		if (i) cout << " ";
		cout << ans[i];
	}
	cout << endl;
	return 0;
}
