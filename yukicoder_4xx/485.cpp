#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[]) {
	int a, b;
	cin >> a >> b;
	int x = b / a;
	if (a * x == b) {
		cout << x << endl;
	} else {
		cout << "NO" << endl;
	}
	return 0;
}
