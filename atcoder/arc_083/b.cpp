// B.

#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
	int n, k, x, ans = 0;
	cin >> n >> k;
	for (int i = 0; i < n; ++i) {
		cin >> x;
		ans += min(x, abs(x - k)) * 2;
	}
	cout << ans << endl;
	return 0;
}
