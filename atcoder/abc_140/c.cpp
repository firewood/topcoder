// C.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>

using namespace std;

int main(int argc, char* argv[]) {
	while (true) {
		int n = -1;
		cin >> n;
		if (n <= 0) break;
		int prev = 1 << 30, ans = 0;
		for (int i = 0; i < n - 1; ++i) {
			int b;
			cin >> b;
			ans += min(prev, b);
			prev = b;
		}
		ans += prev;
		cout << ans << endl;
	}
	return 0;
}
