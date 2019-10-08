// C.

#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

int main(int argc, char* argv[]) {
	while (true) {
		int n = -1, a;
		cin >> n;
		if (n <= 0) break;
		int cnt[9] = {};
		for (int i = 0; i < n; ++i) {
			cin >> a;
			cnt[min(a / 400, 8)] += 1;
		}
		int cols = 0;
		for (int i = 0; i < 8; ++i) {
			cols += cnt[i] > 0;
		}
		cout << max(1, cols) << " " << (cols + cnt[8]) << endl;
	}
	return 0;
}
