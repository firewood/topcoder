// B.

#include <iostream>
#include <algorithm>
#include <sstream>

using namespace std;
typedef long long LL;

const LL MOD = 1000000007LL;

int main(int argc, char *argv[])
{
	int N;
	cin >> N;
	int a[100000];
	int x = 0;
	for (int i = 0; i < N; ++i) {
		cin >> a[i];
		x ^= a[i];
	}
	LL ans = 0;
	if (x == 0) {
		ans = 1;
		for (int i = 1; i < N; ++i) {
			ans = (ans * 2) % MOD;
		}
		ans = (ans + MOD - 1) % MOD;
	}
	cout << ans << endl;
	return 0;
}
