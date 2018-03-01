// A.

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(int argc, char *argv[]) {
	int n, k;
	cin >> n >> k;
	vector<int> t(n);
	int sum = 0, ans = -1;
	for (int i = 0; i < n; ++i) {
		cin >> t[i];
		sum += t[i];
		if (i >= 2) {
			if (sum < k) {
				ans = i + 1;
				break;
			}
			sum -= t[i - 2];
		}
	}
	cout << ans << endl;
	return 0;
}
