// D.

#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstdlib>

using namespace std;

typedef long long LL;

int main(int argc, char *argv[]) {
	LL k;
	cin >> k;
	LL a[2] = { k / 4 + 1, k / 4 + 1 };
	k %= 4;
	for (LL i = 0; i < k; ++i) {
		int t = i % 2;
		a[t] += 2;
		a[!t] -= 1;
	}
	cout << 2 << " " << a[0] << " " << a[1] << endl;
	return 0;
}
