// A.

#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[]) {
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	bool ans = abs(a - c) <= d || (abs(a - b) <= d && abs(b - c) <= d);
	cout << (ans ? "Yes" : "No") << endl;
	return 0;
}
