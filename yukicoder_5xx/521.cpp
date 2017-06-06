#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[])
{
	int n, k, ans = 0;
	cin >> n >> k;
	if (k > 0 && k <= n) {
		ans = n - 2 + ((n - k + 1) == k);
	}
	cout << ans << endl;
	return 0;
}
