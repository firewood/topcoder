// B.

#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[]) {
	cout.precision(6);
	int n;
	cin >> n;
	double ans = 0;
	for (int i = 0; i < n; ++i) {
		double a;
		string t;
		cin >> a >> t;
		if (t == "JPY") {
			ans += a;
		}
		if (t == "BTC") {
			ans += a * 380000;
		}
	}
	cout << ans << endl;
	return 0;
}
