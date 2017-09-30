#include <iostream>
#include <sstream>
#include <algorithm>
using namespace std;
typedef long long LL;
const LL MOD = 1000000007;
int main(int argc, char *argv[])
{
	LL L;
	cin >> L;
	LL ans = 0;
	if (L <= 1000000) {
		for (LL a = 2; a < L; ++a) {
			LL b = a + 1;
			LL cl = b + 1;
			LL ch = min(a + b - 1, L - a - b);
			if (ch >= cl) {
				ans = (ans + ch - cl + 1) % MOD;
			}
			cl = a + 3;
			ch = (L - a + 1) / 2;
			if (ch >= cl) {
				ans = (ans + ch - cl + 1) % MOD;
			}
		}
	}
	cout << ans << endl;
	return 0;
}
