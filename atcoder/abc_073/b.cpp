// B.

#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
	int n, l, r, ans = 0;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> l >> r;
		ans += (r - l) + 1;
	}
	cout << ans << endl;
	return 0;
}
