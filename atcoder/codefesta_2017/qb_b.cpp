// B.

#include <iostream>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[]) {
	int n, m, d[200000], t[200000];
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> d[i];
	}
	sort(d, d + n);
	cin >> m;
	for (int i = 0; i < m; ++i) {
		cin >> t[i];
	}
	sort(t, t + m);
	bool ans = true;
	int pos = 0;
	for (int i = 0; i < m; ++i) {
		for (; pos < n && d[pos] < t[i]; ++pos) {
			;
		}
		if (pos >= n || d[pos] > t[i]) {
			ans = false;
			break;
		}
		++pos;
	}
	cout << (ans ? "YES" : "NO") << endl;
	return 0;
}
