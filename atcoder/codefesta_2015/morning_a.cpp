#include <iostream>
#include <vector>

using namespace std;
typedef long long LL;

int main(int argc, char *argv[])
{
	int n;
	cin >> n;
	vector<LL> a(n), rcnt(n), rrcnt(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	LL c = 0, r = 0;
	for (int i = 0; i < n; ++i) {
		if (i % 2) {
			r += c;
			c += 1 + a[i];
			r += c;
			++c;
		} else {
			c += a[i];
		}
		rcnt[i] = r;
	}
	c = 0, r = 0;
	for (int i = n - 1; i >= 0; --i) {
		if (i % 2) {
			r += c;
			c += 1 + a[i];
			r += c;
			++c;
		} else {
			c += a[i];
		}
		rrcnt[i] = r;
	}
	LL ans = 1LL << 60;
	for (int i = 0; i < n; i += 2) {
		ans = min(ans, rcnt[i] + rrcnt[i]);
	}
	cout << ans << endl;
	return 0;
}
