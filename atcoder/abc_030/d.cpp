// D.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <numeric>

using namespace std;

typedef long long LL;

int main(int argc, char* argv[]) {
#ifdef _MSC_VER
	while (true)
#endif
	{
		int n = -1, a;
		cin >> n >> a;
		if (n < 0) return 0;
		string k;
		cin >> k;
		vector<int> b(n + 1);
		for (int i = 0; i < n; ++i) {
			cin >> b[i + 1];
		}
		int t = 0, c = a;
		vector<int> vis(n + 1);
		while (!vis[c]) {
			vis[c] = ++t;
			c = b[c];
		}
		LL f = t - vis[c] + 1;
		LL x = 0;
		if (k.length() <= 6) {
			x = atoll(k.c_str());
		} else {
			LL d = 1;
			for (int i = k.length() - 1; i >= 0; --i) {
				x = (x + d * (k[i] - '0')) % f;
				d = (d * 10) % f;
			}
			while (x <= (t - f)) {
				x += f;
			}
		}
		c = a;
		for (LL i = 0; i < x; ++i) {
			c = b[c];
		}
		cout << c << endl;
	}
	return 0;
}
