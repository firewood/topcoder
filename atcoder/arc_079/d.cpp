// D.

#include <iostream>
#include <algorithm>

using namespace std;

typedef long long LL;

int main(int argc, char *argv[]) {
	const LL n = 50;
	LL k;
	cin >> k;

	LL a[n];
	fill(a, a + n, k / n + n - 1);
	for (LL i = 0; i < k % n; ++i) {
		int t = i % n;
		for (int j = 0; j < n; ++j) {
			if (t == j) {
				a[j] += n;
			} else {
				a[j] -= 1;
			}
		}
	}

	cout << n << endl;
	for (int i = 0; i < n; ++i) {
		if (i) {
			cout << " ";
		}
		cout << a[i];
	}
	cout << endl;

	return 0;
}
