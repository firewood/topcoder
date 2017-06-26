// B.

#include <iostream>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[]) {
	int w, a, b;
	cin >> w >> a >> b;
	int p = min(a, b), q = max(a, b);
	int ans = max(0, q - (p + w));
	cout << ans << endl;
	return 0;
}
