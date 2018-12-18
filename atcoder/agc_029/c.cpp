// C.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long LL;

int n;
vector<int> a;

bool possible(int t) {
	int mlen = n + 1;
	int len = min(mlen, a[n - 1]);
	vector<int> v(len, t);
	for (int i = n - 2; i >= 0; --i) {
		if (a[i] < len) {
			len = a[i];
		} else {
			int j;
			for (j = len - 1; j >= 0; --j) {
				if (--v[j] > 0) {
					break;
				}
				v[j] = t;
			}
			if (j < 0) {
				return false;
			}
			int nlen = min(mlen, a[i]);
			v.resize(nlen);
			fill(v.begin() + len, v.end(), t);
			len = nlen;
		}
	}
	return true;
}

int main(int argc, char *argv[]) {
	cin >> n;
	a.resize(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	int low = 0, high = n;
	while (high - low > 1) {
		int mid = (high + low) / 2;
		if (possible(mid)) {
			high = mid;
		} else {
			low = mid;
		}
	}
	cout << high << endl;
	return 0;
}
