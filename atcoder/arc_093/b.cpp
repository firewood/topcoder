// B.

#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[]) {
	int n, d, x;
	cin >> n >> d >> x;
	for (int i = 0; i < n; ++i) {
		int a;
		cin >> a;
		x += (d - 1 + a) / a;
	}
	cout << x << endl;
	return 0;
}
