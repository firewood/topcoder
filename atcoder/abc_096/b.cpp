// B.

#include <iostream>
#include <algorithm>
#include <numeric>

using namespace std;

int main(int argc, char *argv[])
{
	long long a[3];
	cin >> a[0] >> a[1] >> a[2];
	sort(a, a + 3);
	int k;
	cin >> k;
	for (int i = 0; i < k; ++i) {
		a[2] *= 2;
	}
	long long ans = accumulate(a, a + 3, 0LL);
	cout << ans << endl;
	return 0;
}
