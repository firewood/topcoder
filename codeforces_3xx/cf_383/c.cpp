// C. Arpa's loud Owf and Mehrdad's evil plan

#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <map>
#include <cstdio>
#include <cstring>

using namespace std;
typedef long long LL;

LL gcd(LL a, LL b) { return b ? gcd(b, a % b) : a; }
LL lcm(LL a, LL b) { return (a / gcd(a, b)) * b; }

int main(int argc, char *argv[])
{
	LL n, c[100], p[100], ans = 1;
	cin >> n;
	for (LL i = 0; i < n; ++i) {
		cin >> c[i];
		--c[i];
	}
	for (LL i = 0; i < n; ++i) {
		LL pos = i, j;
		for (j = 1; j <= 200; ++j) {
			pos = c[pos];
			if (pos == i) {
				break;
			}
		}
		if (j > 200) {
			ans = -1;
			break;
		}
		p[i] = j;
	}
	if (ans >= 1) {
		for (LL i = 0; i < n; ++i) {
			ans = lcm(ans, p[i]);
		}
		if ((ans % 2) == 0) {
			LL t = ans / 2, h[100] = {};
			for (LL i = 0; i < n; ++i) {
				h[i] = -1;
			}
			for (LL i = 0; i < n; ++i) {
				LL pos = i;
				for (LL j = 0; j < t; ++j) {
					pos = c[pos];
					if (pos == i) {
						break;
					}
				}
				h[pos] = i;
			}
			bool f = true;
			for (LL i = 0; i < n; ++i) {
				if (h[h[i]] != i) {
					f = false;
					break;
				}
			}
			if (f) {
				ans = t;
			}
		}
	}
	cout << ans << endl;
	return 0;
}
