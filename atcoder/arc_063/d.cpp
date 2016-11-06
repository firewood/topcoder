// D.

#include <iostream>
#include <algorithm>
#include <sstream>
#include <cstdio>
#include <cstdlib>

using namespace std;

int main(int argc, char *argv[]) {
	int N, T;
	cin >> N >> T;
	int a[100000];
	for (int i = 0; i < N; ++i) {
		cin >> a[i];
	}
	int mn = 1 << 30;
	int d = 0;
	for (int i = 0; i < N; ++i) {
		mn = min(mn, a[i]);
		d = max(d, a[i] - mn);
	}
	int ans = 0;
	mn = 1 << 30;
	for (int i = 0; i < N; ++i) {
		mn = min(mn, a[i]);
		if (a[i] - mn == d) {
			++ans;
			++mn;
		}
	}
	cout << ans << endl;
	return 0;
}
