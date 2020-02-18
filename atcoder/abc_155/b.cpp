// B.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>

using namespace std;

int main(int argc, char *argv[]) {
	int n, a;
	cin >> n;
	bool ans = true;
	for (int i = 0; i < n; ++i) {
		cin >> a;
		if ((a % 2) == 0 && ((a % 3) != 0 && (a % 5) != 0)) {
			ans = false;
		}
	}
	cout << (ans ? "APPROVED" : "DENIED") << endl;
	return 0;
}
