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

typedef long long LL;

LL solve(long long t, long long N) {
	vector<LL> v;
	LL prev = 0, fa = -1, pc = 0, fr = -1, na = -1, i;
	for (i = 1; ; ++i) {
		LL a = i * (100 + t);
		LL b = a % 100;
		LL c = a / 100;
		LL d = c - prev;
		if (d > 1) {
			v.emplace_back(c - pc);
			if (fr < 0) {
				fa = a;
				fr = b;
			} else {
				if (fr == b) {
					v.pop_back();
					na = a;
					--pc;
					break;
				}
			}
			pc = c;
		}
		prev = c;
	}
	LL sum = accumulate(v.begin(), v.end(), 0LL);
	LL e = (N - v.size()) / v.size();
	N -= e * v.size();
	LL j = 0, k = sum * e;
	for (LL i = 0; i < N; ++i) {
		k += v[j % v.size()];
		++j;
	}
	return k - 1;
}

LL solve2(LL t, LL N) {
	if (N <= 1000) {
		LL prev = 1;
		for (int i = 1; ; ++i) {
			LL a = i * (100 + t);
			LL b = a % 100;
			LL c = a / 100;
			LL d = c - prev;
			if (d > 1) {
				if (--N <= 0) {
					return c - 1;
				}
			}
			prev = c;
		}
	}
}

int main() {
	long long t, N;
	std::cin >> t >> N;
	cout << solve(t, N) << endl;
	return 0;
}
