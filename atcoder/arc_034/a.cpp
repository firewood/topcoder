// A.

#include <iostream>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[]) {
	cout.precision(10);
	int n, a;
	cin >> n;
	double ans = 0;
	for (int i = 0; i < n; ++i) {
		double sum = 0;
		for (int j = 0; j < 4; ++j) {
			cin >> a;
			sum += a;
		}
		cin >> a;
		sum += (a * 110.0) / 900;
		ans = max(ans, sum);
	}
	cout << ans << endl;
	return 0;
}
