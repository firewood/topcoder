// A.

#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[]) {
	int a, b, x;
	cin >> a >> b >> x;
	bool ans = x >= a && x <= (a + b);
	cout << (ans ? "YES" : "NO") << endl;
	return 0;
}
