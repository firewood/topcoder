// C.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>

using namespace std;

int main(int argc, char *argv[]) {
	long long n, a, prev = -1, cnt = 0, ans = 0;
	cin >> n;
	for (long long i = 0; i < n; ++i) {
		cin >> a;
		if (a <= prev) {
			cnt = 0;
		}
		++cnt;
		ans += cnt;
		prev = a;
	}
	cout << ans << endl;
	return 0;
}
