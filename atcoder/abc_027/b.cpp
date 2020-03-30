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
	int sum = accumulate(a.begin(), a.end(), 0);
	int ans, avg = sum / n;
	if (sum % n) {
		ans = -1;
	} else {
		ans = 0, sum = a[0];
		for (int i = 1; i < n; ++i) {
			ans += avg * i != sum;
			sum += a[i];
		}
	}
	cout << ans << endl;
	return 0;
}
