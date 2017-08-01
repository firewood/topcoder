#include <iostream>
#include <algorithm>

using namespace std;

typedef long long LL;
typedef pair<LL, LL> LLLL;

LLLL solve(LL a, LL b, LL c) {
	if (a) {
		LL d = (LL)(sqrt((double)b * b - 4 * (double)a * c));
		for (LL e = d - 64; e <= d + 64; ++e) {
			LL x = (-b - e) / (2 * a);
			LL y = (-b + e) / (2 * a);
			if (a * x * x + b * x + c == 0 && a * y * y + b * y + c == 0) {
				return LLLL(x, y);
			}
		}
	}
	return LLLL(0, 0);
}

int main(int argc, char *argv[])
{
	LL a, b, c;
	cin >> a >> b >> c;
	LL ans[3];
	for (LL x = -1000000; x <= 1000000; ++x) {
		LL p = a + x;
		LL q = b + p * x;
		if ((c == 0 && (x == 0 || q == 0)) || (x && q && (c % x) == 0 && (c % q) == 0 && abs(c / x + q) <= 1)) {
			LLLL y = solve(1, p, q);
			if (y.first || y.second) {
				ans[0] = x;
				ans[1] = y.first;
				ans[2] = y.second;
				break;
			}
		}
	}
	sort(ans, ans + 3);
	for (int i = 0; i < 3; ++i) {
		if (i) {
			cout << " ";
		}
		cout << ans[i];
	}
	cout << endl;
	return 0;
}
