// A.

#include <iostream>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[]) {
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	cout << (min(a, b) + min(c, d)) << endl;
	return 0;
}
