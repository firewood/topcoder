// A.

#include <iostream>
#include <algorithm>

using namespace std;

typedef long long LL;

int main(int argc, char *argv[]) {
	int w[2], h[2];
	cin >> w[0] >> h[0] >> w[1] >> h[1];
	LL ans = 0;
	for (int i = 0; i < 2; ++i) {
		ans += w[i];
		ans += h[i] * 2;
		ans += 2;
	}
	ans += w[0] - w[1];
	cout << ans << endl;
	return 0;
}
