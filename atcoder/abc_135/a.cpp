// A.

#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[]) {
	int a, b;
	cin >> a >> b;
	int c = a + b;
	if (c % 2) {
		cout << "IMPOSSIBLE" << endl;
	} else {
		cout << c / 2 << endl;
	}
	return 0;
}
