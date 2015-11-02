// B.

#include <iostream>
#include <algorithm>
#include <sstream>

using namespace std;
typedef long long LL;

const LL MOD = 1000000009LL;

int main(int argc, char *argv[])
{
	int N;
	cin >> N;
	LL ans = 0;
	if (N > 2) {
		ans = 1;
		LL c = 1;
		LL d = 2;
		for (int i = 3; i < N; ++i) {
			c = (c * 2 + d) % MOD;
			d = (d * 2) % MOD;
			ans = (ans + c) % MOD;
		}
	}
	cout << ans << endl;
	return 0;
}
