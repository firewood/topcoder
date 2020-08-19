// B.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>

using namespace std;

int main(int argc, char *argv[]) {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	int ans = 0;
	sort(a.begin(), a.end());
	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {
			if (a[i] == a[j]) continue;
			for (int k = j + 1; k < n; ++k) {
				if (a[j] == a[k]) continue;
				ans += a[i] + a[j] > a[k];
			}
		}
	}
	cout << ans << endl;
	return 0;
}
