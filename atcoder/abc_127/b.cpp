// B.

#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

typedef long long LL;

int main(int argc, char *argv[]) {
	LL r, d, x;
	cin >> r >> d >> x;
	for (int i = 1; i <= 10; ++i) {
		x = r * x - d;
		cout << x << endl;
	}
	return 0;
}
