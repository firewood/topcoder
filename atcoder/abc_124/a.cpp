// A.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>

using namespace std;

int main(int argc, char *argv[]) {
	int a[4];
	cin >> a[0] >> a[1];
	a[2] = a[0] - 1, a[3] = a[1] - 1;
	sort(a, a + 4);
	int ans = a[2] + a[3];
	cout << ans << endl;
	return 0;
}
