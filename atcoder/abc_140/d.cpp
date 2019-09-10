// D.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>

using namespace std;

int main(int argc, char* argv[]) {
	while (true) {
		int n = -1, k = -1;
		cin >> n >> k;
		if (n <= 0 || k <= 0) break;
		string s;
		cin >> s;
		int d = 0;
		for (int i = 1; i < n; ++i) {
			d += s[i - 1] != s[i];
		}
		int ans = n - 1 - max(0, d - 2 * k);
		cout << ans << endl;
	}
	return 0;
}
