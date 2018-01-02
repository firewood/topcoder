// B.

#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[]) {
	int n, a, b, ans = 0;
	cin >> n >> a >> b;
	for (int i = 1; i <= n; ++i) {
		int sum = 0;
		for (int j = i; j > 0; j /= 10) {
			sum += j % 10;
		}
		if (sum >= a && sum <= b) {
			ans += i;
		}
	}
	cout << ans << endl;
	return 0;
}
