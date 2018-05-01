// B.

#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[]) {
	int a, b, k;
	cin >> a >> b >> k;
	int n;
	for (n = a; n < a + k && n <= b; ++n) {
		cout << n << endl;
	}
	for (n = max(n, b - k + 1); n <= b; ++n) {
		cout << n << endl;
	}
	return 0;
}
