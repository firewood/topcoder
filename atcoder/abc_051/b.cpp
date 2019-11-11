// B.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>

using namespace std;

int main(int argc, char *argv[]) {
	int k, s, ans = 0;
	cin >> k >> s;
	for (int i = 0; i <= k; ++i) {
		for (int j = 0; j <= k; ++j) {
			int r = s - i - j;
			ans += r >= 0 && r <= k;
		}
	}
	cout << ans << endl;
	return 0;
}
