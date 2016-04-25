#include <iostream>
#include <sstream>
#include <algorithm>
#include <cstdio>

using namespace std;

int main(int argc, char *argv[]) {
	int a[7];
	for (int i = 0; i < 7; ++i) {
		cin >> a[i];
	}
	sort(a, a + 7);
	bool ans = false;
	do {
		int i;
		for (i = 2; i < 7; ++i) {
			int p = a[i - 2], q = a[i - 1], r = a[i];
			if (p < r && ((q < p && q < r) || (q > p && q > r))) {
				;
			} else {
				break;
			}
		}
		if (i >= 7) {
			ans = true;
			break;
		}
	} while (next_permutation(a, a + 7));
	cout << (ans ? "YES" : "NO") << endl;
	return 0;
}
