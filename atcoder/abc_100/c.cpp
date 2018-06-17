// C.

#include <iostream>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[])
{
	int n, a, ans = 0;
	cin >> n;
	for (int i = 0; i <= n; ++i) {
		cin >> a;
		while ((a % 2) == 0) {
			++ans;
			a /= 2;
		}
	}
	cout << ans << endl;
	return 0;
}
