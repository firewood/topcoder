// A.

#include <iostream>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[])
{
	long long n, k, x, y, ans;
	cin >> n >> k >> x >> y;
	ans = x * min(n, k) + y * max(0LL, n - k);
	cout << ans << endl;
	return 0;
}
