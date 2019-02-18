// C.

#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }

int main(int argc, char *argv[]) {
	int n, ans = 0;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		int a;
		cin >> a;
		ans = gcd(ans, a);
	}
	cout << ans << endl;
	return 0;
}
