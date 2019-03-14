// D.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long LL;

static LL f(LL x) {
	switch (x & 3) {
	case 0:
		return x;
	case 1:
		return 1;
	case 2:
		return x | 1;
	default:
		return 0;
	}
}

int main(int argc, char *argv[]) {
	LL a, b;
	cin >> a >> b;
	LL ans = f(b) ^ f(a - 1);
	cout << ans << endl;
	return 0;
}
