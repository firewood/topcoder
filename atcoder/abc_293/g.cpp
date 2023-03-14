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

typedef pair<int, int> II;

vector<int64_t> solve(int N, int Q, std::vector<int> A, std::vector<int> l, std::vector<int> r) {
	vector<int64_t> ans(Q), C(N + 1);
	vector<int64_t> cnt(200002);
	for (int64_t i = 3; i <= N; ++i) {
		C[i] = i * (i - 1) * (i - 2) / 6;
	}
	vector<pair<II, int>> v;
	int b = N / sqrt(Q) + 1;
	for (int i = 0; i < Q; ++i) {
		v.emplace_back(II(l[i] / b, r[i]), i);
	}
	sort(v.begin(), v.end());
	int left = l[v.front().second], right = left;
	int64_t total = 0;
	auto add = [&](int pos) {
		int64_t& c = cnt[A[pos]];
		c += 1;
		total += C[c] - C[c - 1];
	};
	auto del = [&](int pos) {
		int64_t& c = cnt[A[pos]];
		c -= 1;
		total += C[c] - C[c + 1];
	};
	for (auto kv : v) {
		int ll = l[kv.second], rr = r[kv.second];
		while (left > ll) {
			--left;
			add(left);
		}
		while (right > rr) {
			--right;
			del(right);
		}
		while (left < ll) {
			del(left);
			++left;
		}
		while (right < rr) {
			add(right);
			++right;
		}
		ans[kv.second] = total;
	}
	return ans;
}

int main() {
	int N, Q;
	std::cin >> N >> Q;
	std::vector<int> A(N);
	for (int i = 0; i < N; i++) {
		std::cin >> A[i];
	}
	std::vector<int> l(Q), r(Q);
	for (int i = 0; i < Q; i++) {
		std::cin >> l[i] >> r[i];
		--l[i];
	}
	vector<int64_t> ans = solve(N, Q, A, l, r);
	for (auto x : ans) {
		cout << x << endl;
	}
	return 0;
}
