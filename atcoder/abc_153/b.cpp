// B.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>

using namespace std;

int main(int argc, char *argv[]) {
	int h, n, a;
	cin >> h >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a;
		h -= a;
	}
	cout << (h <= 0 ? "Yes" : "No") << endl;
	return 0;
}
