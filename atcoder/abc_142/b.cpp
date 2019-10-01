// B.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>

using namespace std;

int main(int argc, char *argv[]) {
	int n, k, h, ans = 0;
	cin >> n >> k;
	for (int i = 0; i < n; ++i) {
		cin >> h;
		ans += h >= k;
	}
	cout << ans << endl;
	return 0;
}
