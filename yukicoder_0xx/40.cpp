#include <iostream>
#include <algorithm>
#include <sstream>
#include <vector>

using namespace std;

int main(int argc, char *argv[]) {
	string s;
	getline(cin, s);
	stringstream sa(s);
	int D;
	sa >> D;
	getline(cin, s);
	stringstream sb(s);
	int b[10002] = {};
	for (int i = 0; i <= D; ++i) {
		sb >> b[i];
	}
	for (int i = D; i >= 3; --i) {
		b[i - 2] += b[i];
	}
	if (b[2]) {
		cout << 2 << endl;
		cout << b[0] << " " << b[1] << " " << b[2] << endl;
	} else if (b[1]) {
		cout << 1 << endl;
		cout << b[0] << " " << b[1] << endl;
	} else {
		cout << 0 << endl;
		cout << b[0] << " " << endl;
	}
	return 0;
}
