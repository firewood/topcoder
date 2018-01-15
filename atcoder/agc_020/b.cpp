// B.

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <vector>

using namespace std;

typedef long long LL;

int main(int argc, char *argv[])
{
	int k;
	cin >> k;
	vector<LL> a(k);
	for (int i = 0; i < k; ++i) {
		cin >> a[i];
	}
	reverse(a.begin(), a.end());
	LL l = -1, r = -1;
	if (a[0] == 2) {
		l = 2, r = 3;
		for (int i = 1; i < (int)a.size(); ++i) {
			LL x = a[i];
			LL p = ((l + x - 1) / x) * x;
			LL q = (r / x) * x + x - 1;
			if (p > q) {
				l = -1;
				break;
			}
			l = p;
			r = q;
		}
	}
	if (l < 0) {
		cout << l << endl;
	} else {
		cout << l << " " << r << endl;
	}
	return 0;
}
