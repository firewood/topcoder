// A.

#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[]) {
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	if (a + b > c + d) {
		cout << "Left" << endl;
	} else if (a + b == c + d) {
		cout << "Balanced" << endl;
	} else {
		cout << "Right" << endl;
	}
	return 0;
}
