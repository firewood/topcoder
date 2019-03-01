// D.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <map>

using namespace std;

typedef long long LL;

int main(int argc, char *argv[]) {
	LL n, m;
	cin >> n >> m;
	map<LL, LL> x;
	LL sum = 0, ans = 0;
	x[0] = 1;
	for (LL i = 0; i < n; ++i) {
		LL a;
		cin >> a;
		sum = (sum + a) % m;
		ans += x[sum];
		x[sum] += 1;
	}
	cout << ans << endl;
	return 0;
}
