// B.

#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main(int argc, char *argv[]) {
	int x, k, b = 1;
	cin >> x >> k;
	for (int i = 0; i < k; ++i) {
		b *= 10;
	}
	int ans = x + b;
	ans -= ans % b;
	cout << ans << endl;
	return 0;
}
