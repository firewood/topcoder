// A.

#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[]) {
	int a, b;
	cin >> a >> b;
	if (a + b == 15) {
		cout << "+" << endl;
	} else if (a * b == 15) {
		cout << "*" << endl;
	} else {
		cout << "x" << endl;
	}
	return 0;
}
