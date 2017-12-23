// C.

#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[]) {
	long long x, y;
	cin >> x >> y;
	int ans = 0;
	while (x <= y) {
		++ans;
		x *= 2;
	}
	cout << ans << endl;
	return 0;
}
