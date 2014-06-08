// Google Code Jam 2014 R1C
// Problem A. Part Elf

#include <iostream>
#include <sstream>
#include <algorithm>
#include <set>
#include <vector>

using namespace std;

typedef long long LL;
LL gcd(LL a, LL b) { return b ? gcd(b, a % b) : a; }

int solve(void)
{
	int N = 0;
	string s;
	getline(cin, s);
	LL p, q;
	sscanf(s.c_str(), "%lld/%lld", &p, &q);
	LL g = gcd(p, q);
	p /= g;
	q /= g;

	for (LL n = 1LL << 40; n > 0; n >>= 1) {
		if (n != q) {
			continue;
		}

		for (int ans = 0; n > 0; ++ans, n >>= 1) {
			if (n & p) {
				return ans;
			}
		}
		break;
	}

	return -1;
}

int main(int argc, char *argv[])
{
	string s;
	getline(cin, s);
	int T = atoi(s.c_str());
	if (T <= 0) return 0;

	for (int t = 1; t <= T; ++t) {
		int ans = solve();
		printf("Case #%d: ", t);
		if (ans < 0) {
			printf("impossible\n");
		} else {
			printf("%d\n", ans);
		}
	}

	return 0;
}

