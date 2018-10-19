// B.

#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[])
{
	int n, x, ans = 0, m = 0;
	cin >> n >> x;
	for (int i = 0; i < n; ++i) {
		int a, b;
		cin >> a >> b;
		ans += a * b;
		m = max(m, b);
	}
	ans += m * x;
	cout << ans << endl;
	return 0;
}
