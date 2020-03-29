// C.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

typedef long long LL;

int main(int argc, char* argv[]) {
	LL k, n;
	cin >> k >> n;
	vector<LL> a(n * 2);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		a[i + n] = k + a[i];
	}
	LL ans = 1LL << 60;
	for (int i = 0; i < n; ++i) {
		ans = min(ans, a[i + n - 1] - a[i]);
	}
	cout << ans << endl;
	return 0;
}
