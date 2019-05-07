// A.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>

using namespace std;

int main(int argc, char *argv[]) {
	int a, b, t;
	cin >> a >> b >> t;
	int ans = t / a * b;
	cout << ans << endl;
	return 0;
}
