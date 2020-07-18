// B.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>

using namespace std;

int main(int argc, char *argv[]) {
	long long a, b, k, c;
	cin >> a >> b >> k;
	c = min(a, k);
	a -= c;
	b = max(0LL, b - (k - c));
	cout << a << " " << b << endl;
	return 0;
}
