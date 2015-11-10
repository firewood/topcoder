#include <iostream>
#include <algorithm>
#include <sstream>

using namespace std;

int main(int argc, char *argv[]) {
	int D;
	cin >> D;
	string a, b;
	cin >> a >> b;
	string c = string(D, 'x') + a + b + string(D, 'x');
	int ans = 0;
	for (int i = 0; i != c.length(); ++i) {
		int r = D;
		int h = 0;
		for (int j = 0; j != c.length(); ++j) {
			if (c[j] == 'o') {
				++h;
				if (j >= i) {
					r = 0;
				}
			} else if (j >= i && r > 0) {
				--r;
				++h;
			} else {
				h = 0;
			}
			ans = max(ans, h);
		}
	}
	cout << ans << endl;
	return 0;
}
