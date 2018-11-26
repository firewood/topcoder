// A.

#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

int main(int argc, char *argv[]) {
	int n, sum = 0, ans = 0;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		sum += a[i];
	}
	for (int i = 0; i < n; ++i) {
		if (abs(sum - a[i] * n) < abs(sum - a[ans] * n)) {
			ans = i;
		}
	}
	cout << ans << endl;
	return 0;
}
