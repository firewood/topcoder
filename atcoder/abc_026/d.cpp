#ifdef __GNUC__
#pragma GCC diagnostic ignored "-Wunused-result"
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#endif

#include <algorithm>
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

void solve(LD A, LD B, LD C) {
	cout.precision(20);
	auto evaluate = [&](LD t) -> LD {
		return A * t + B * sinl(C * t * M_PI);
	};
	LD left = 0, right = 200;
	for (int t = 0; t < 200; ++t) {
		LD mid = (left + right) / 2;
		if (evaluate(mid) < 100.0) {
			left = mid;
		} else {
			right = mid;
		}
	}
	cout << left << endl;
}

void solve_B(LD A, LD B, LD C) {
	cout.precision(20);
	auto evaluate = [&](LD t) -> LD {
		return A * t + B * sin(C * t * M_PI) - 100.0;
	};
	LD ans = 0;
	for (LD left = 0, right = 0.1; right <= 256; right += 0.01) {
		if ((evaluate(left) > 0) != (evaluate(right) > 0)) {
			for (int t = 0; t < 256; ++t) {
				LD mid = (left + right) / 2;
				if ((evaluate(left) > 0) == (evaluate(mid) > 0)) {
					left = mid;
				} else {
					right = mid;
				}
			}
			ans = left;
			break;
		}
	}
	cout << ans << endl;
}

int main() {
	int A, B, C;
	cin >> A >> B >> C;
	solve(A, B, C);
	return 0;
}
