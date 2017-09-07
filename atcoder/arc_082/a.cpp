// A.

#include <iostream>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[]) {
	int x, t, ans;
	cin >> x >> t;
	ans = max(0, x - t);
	cout << ans << endl;
	return 0;
}
