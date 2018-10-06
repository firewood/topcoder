// A.

#include <iostream>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[]) {
	int n;
	cin >> n;
	if (n <= 1) {
		cout << "Hello World" << endl;
	} else {
		int a, b;
		cin >> a >> b;
		cout << (a + b) << endl;
	}
	return 0;
}
