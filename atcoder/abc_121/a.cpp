// A.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>

using namespace std;

int main(int argc, char *argv[]) {
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	int ans = (a - c) * (b - d);
	cout << ans << endl;
	return 0;
}
