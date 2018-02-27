// A.

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[]) {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	sort(a.rbegin(), a.rend());
	int ans = 0;
	for (int i = 0; i < (int)a.size(); i += 2) {
		ans += a[i];
	}
	cout << ans << endl;
	return 0;
}
