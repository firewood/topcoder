// A.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>

using namespace std;

int main(int argc, char *argv[]) {
	int n, a, b;
	cin >> n >> a >> b;
	int c = min(n, 5);
	int ans = a * (n - c) + b * c;
	cout << ans << endl;
	return 0;
}
