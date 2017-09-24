// B.

#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
	int n, m, k, r;
	cin >> n >> m >> k;
	bool ans = false;
	for (int i = 0; i <= n; ++i) {
		r = i * m;
		if (r == k) {
			ans = true;
		}
		for (int j = 0; j < m; ++j) {
			r += (-i + (n - i));
			if (r == k) {
				ans = true;
			}
		}
	}
	cout << (ans ? "Yes" : "No") << endl;
	return 0;
}
