// B.

#include <iostream>

using namespace std;

typedef long long LL;

int main(int argc, char *argv[])
{
	LL n;
	cin >> n;
	LL ans = 1;
	for (LL i = 1; i <= n; ++i) {
		ans = (ans * i) % 1000000007;
	}
	cout << ans << endl;
	return 0;
}
