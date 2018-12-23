// D.

#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[]) {
	int n;
	cin >> n;
	bool odd = false;
	for (int i = 0; i < n; ++i) {
		int a;
		cin >> a;
		if (a % 2) {
			odd = true;
		}
	}
	cout << (odd ? "first" : "second") << endl;
	return 0;
}
