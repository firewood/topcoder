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

typedef long double LD;
typedef pair<int64_t, int64_t> II;

int64_t gcd(int64_t a, int64_t b) { return b ? gcd(b, a % b) : a; }
int64_t lcm(int64_t a, int64_t b) { return (a / gcd(a, b)) * b; }

II normalize(int64_t x, int64_t y) {
	int64_t xs = x > 0 ? 1 : -1, ys = y > 0 ? 1 : -1;
	if (x == 0) {
		y = ys;
	} else if (y == 0) {
		x = xs;
	} else {
		int64_t g = gcd(x * xs, y * ys);
		x /= g;
		y /= g;
	}
	return II(x, y);
}

vector<int64_t> solve(int64_t N, int64_t Q, std::vector<int64_t> X, std::vector<int64_t> Y, std::vector<int64_t> A, std::vector<int64_t> B) {
	vector<int64_t> ans(Q), sum(1);
	map<II, int> m, rm;
	for (int i = 0; i < N; ++i) {
		m[normalize(X[i], Y[i])] += 1;
	}
	vector<pair<LD, II>> v;
	for (const auto& kv : m) {
		v.emplace_back(make_pair(atan2l(LD(kv.first.second), LD(kv.first.first)), kv.first));
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < int(v.size()); ++i) {
		rm[v[i].second] = i;
		sum.emplace_back(sum.back() + m[v[i].second]);
	}
	for (int i = 0; i < int(v.size()); ++i) {
		sum.emplace_back(sum.back() + m[v[i].second]);
	}
	for (int qi = 0; qi < Q; ++qi) {
		// clockwise: B -> A
		size_t st = rm[normalize(X[B[qi]], Y[B[qi]])];
		size_t ed = rm[normalize(X[A[qi]], Y[A[qi]])];
		if (ed < st) {
			ed += v.size();
		}
		ans[qi] = sum[ed + 1] - sum[st];
	}
	return ans;
}

int main() {
	{
		int64_t N, Q;
		std::cin >> N >> Q;
		std::vector<int64_t> X(N), Y(N);
		for (int i = 0; i < N; i++) {
			std::cin >> X[i] >> Y[i];
		}
		std::vector<int64_t> A(Q), B(Q);
		for (int i = 0; i < Q; i++) {
			std::cin >> A[i] >> B[i];
			--A[i];
			--B[i];
		}
		vector<int64_t> ans = solve(N, Q, X, Y, A, B);
		for (auto x : ans) {
			cout << x << endl;
		}
	}
	return 0;
}
