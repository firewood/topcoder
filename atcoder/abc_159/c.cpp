// C.

#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

typedef long double LD;

int main(int argc, char* argv[]) {
	LD l;
	cin >> l;
	LD a = l / 3;
	LD ans = a * a * (l - 2 * a);
	printf("%.9lf\n", (double)ans);
	return 0;
}
