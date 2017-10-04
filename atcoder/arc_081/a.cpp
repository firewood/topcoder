// A.

#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main(int argc, char *argv[]) {
	int x, a, b;
	cin >> x >> a >> b;
	bool ans = abs(x - a) < abs(x - b);
	cout << (ans ? "A" : "B") << endl;
	return 0;
}
