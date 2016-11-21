#include <iostream>
#include <sstream>
#include <algorithm>
#include <cstdio>

using namespace std;

int main(int argc, char *argv[]) {
	int A, B;
	cin >> A >> B;
	long double a = 50 * A;
	long double b = 0.8 + 0.2 * B;
	int ans = 50 * A + (int)(a / b + 1e-12);
	cout << ans << endl;
	return 0;
}
