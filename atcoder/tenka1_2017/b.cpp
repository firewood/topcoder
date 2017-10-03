// B.

#include <iostream>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[]) {
	int n;
	cin >> n;
	int a[100000], b[100000];
	for (int i = 0; i < n; ++i) {
		cin >> a[i] >> b[i];
	}
	sort(a, a + n);
	sort(b, b + n);
	int ans = a[n - 1] + b[0];
	cout << ans << endl;
	return 0;
}
