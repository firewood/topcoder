// C.

#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[]) {
	int x[3];
	cin >> x[0] >> x[1] >> x[2];
	int ans = 0;
	while (x[0] != x[1] || x[1] != x[2]) {
		++ans;
		sort(x, x + 3);
		if (x[1] - x[0] >= 2) {
			x[0] += 2;
		} else {
			x[0]++;
			x[1]++;
		}
	}
	cout << ans << endl;
	return 0;
}
