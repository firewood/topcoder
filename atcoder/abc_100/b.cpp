// B.

#include <iostream>
#include <algorithm>

using namespace std;

typedef long long LL;

int main(int argc, char *argv[])
{
	LL d, n, b = 1;
	cin >> d >> n;
	for (LL i = 0; i < d; ++i) {
		b *= 100;
	}
	LL ans = b * (n < 100 ? n : 101);
	cout << ans << endl;
	return 0;
}
