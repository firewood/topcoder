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

static const LL INF = 1LL << 60;

LL solve(long long A, long long B, long long C) {
	LL r = 1;
	for (LL x = B % 4, c = C; c; c >>= 1) {
		if (c & 1) {
			r *= x;
		}
		x = (x * x) % 4;
	}
	LL ans = 1;
	for (LL i = 0; i < r + 4; ++i) {
		ans = (ans * A) % 10;
	}
	return ans;
}

LL solve2(long long A, long long B, long long C) {
	LL ans = -1;
	if (B <= 100 && C <= 100) {
		ans = 1;
		LL x = 1;
		for (LL i = 0; i < C; ++i) {
			x *= B;
			//x %= 16;
		}
		for (LL i = 0; i < x; ++i) {
			ans = (ans * A) % 100;
		}
	}
	return ans % 10;
}

int main() {
	long long A, B, C;
	std::cin >> A >> B >> C;
	cout << solve(A, B, C) << endl;
#ifdef _DEBUG
	for (LL a = 1; a <= 5; ++a) {
		for (LL b = 1; b <= 5; ++b) {
			for (LL c = 1; c <= 5; ++c) {
				LL p = solve(a, b, c);
				LL q = solve2(a, b, c);
				if (p != q) {
					cerr << "FAILED: a=" << a << ",b=" << b << ",c=" << c << ", ref:" << q << ",tmp:" << p << endl;
					return -1;
				}
			}
		}
	}
#endif
	return 0;
}
