// B.

#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[]) {
	int n;
	cin >> n;
	string a, b, c;
	cin >> a >> b >> c;
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		int p = a[i] == b[i], q = b[i] == c[i], r = c[i] == a[i];
		if (p & q & r) {
			;
		} else if (p || q || r) {
			++ans;
		} else {
			ans += 2;
		}
	}
	cout << ans << endl;
	return 0;
}
