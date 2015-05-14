#include <iostream>
#include <algorithm>
#include <sstream>
#include <set>

using namespace std;

typedef long long LL;
typedef set<LL> LLSet;

int main(int argc, char *argv[])
{
	LL N, D, T;
	string s;
	getline(cin, s);
	stringstream sa(s);
	sa >> N >> D >> T;
	getline(cin, s);
	stringstream sb(s);
	LLSet z;
	LL ans = 0;
	for (LL i = 0; i < N; ++i) {
		LL x;
		sb >> x;
		LL a = x - D * T, b = x + D * T;
		LL c = ((a % D) + D) % D;
		for (LL y : z) {
			LL d = y - D * T, e = y + D * T;
			LL f = ((d % D) + D) % D;
			if (c == f) {
				if (a >= d && a <= e) {
					a = e + D;
				}
				if (b >= d && b <= e) {
					b = d - D;
				}
			}
		}
		z.insert(x);
		if (b >= a) {
			ans += (b - a + D) / D;
		}
	}
	cout << ans << endl;
	return 0;
}
