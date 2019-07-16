// B.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <numeric>
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
	for (int i = 1; i < n - 1; ++i) {
		ans += (a[i] < a[i - 1] && a[i] > a[i + 1]) || (a[i] < a[i + 1] && a[i] > a[i - 1]);
	}
	cout << ans << endl;
	return 0;
}
