// C. 

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <cstring>

using namespace std;

typedef long long LL;

int main(int argc, char *argv[])
{
	LL n;
	cin >> n;
	vector<LL> a(n * 2);
	for (LL i = 0; i < n * 2; ++i) {
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	LL ans = (a[n - 1] - a[0]) * (a[n * 2 - 1] - a[n]);
	for (LL i = 1; i < n; ++i) {
		ans = min(ans, (a[n + i - 1] - a[i]) * (a[n * 2 - 1] - a[0]));
	}
	cout << ans << endl;
	return 0;
}
