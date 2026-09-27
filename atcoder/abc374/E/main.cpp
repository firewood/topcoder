#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <deque>
#include <fstream>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>

using namespace std;

int64_t gcd(int64_t a, int64_t b) { return b ? gcd(b, a % b) : a; }
int64_t lcm(int64_t a, int64_t b) { return (a / gcd(a, b)) * b; }

int64_t solve(int64_t N, int64_t X, vector<int64_t> A, vector<int64_t> P, vector<int64_t> B, vector<int64_t> Q) {
	auto possible = [&](int64_t t) -> bool {
		int64_t r = X;
		for (int i = 0; i < N; i++) {
			int64_t a = A[i], b = B[i], p = P[i], q = Q[i];
			if (a * q < b * p) {
				swap(a, b);
				swap(p, q);
			}
			int64_t min_price = 1LL << 30;
			int64_t cf = lcm(a, b);
			for (int64_t ac = max(int64_t(0), t / a / cf - 1) * cf; ; ++ac) {
				int64_t rt = max(int64_t(0), t - ac * a);
				int64_t bc = (rt + b - 1) / b;
				min_price = min(min_price, ac * p + bc * q);
				if (rt <= 0) {
					break;
				}
			}
			r -= min_price;
		}
		return r >= 0;
	};
	int64_t left = 0, right = 1LL << 30;
	while (right - left > 1) {
		int64_t mid = (left + right) / 2;
		if (possible(mid)) {
			left = mid;
		} else {
			right = mid;
		}
	}
	return left;
}

int main() {
	int64_t N, X;
	cin >> N >> X;
	vector<int64_t> A(N), P(N), B(N), Q(N);
	for (int64_t i = 0; i < N; ++i) {
		cin >> A[i] >> P[i] >> B[i] >> Q[i];
	}
	auto ans = solve(N, X, A, P, B, Q);
	cout << ans << endl;
}
