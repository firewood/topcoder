// B.

#include <iostream>
#include <sstream>

using namespace std;

int main(int argc, char *argv[]) {
	int n, h, w, a, b, ans = 0;
	cin >> n >> h >> w;
	for (int i = 0; i < n; ++i) {
		cin >> a >> b;
		ans += a >= h && b >= w;
	}
	cout << ans << endl;
	return 0;
}
