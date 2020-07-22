// B.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

typedef long long LL;

int main() {
	int x, y;
	cin >> x >> y;
	bool ans = false;
	for (int i = 0; i <= 100; ++i) {
		for (int j = 0; j <= 100; ++j) {
			if (i + j == x && i * 2 + j * 4 == y) {
				ans = true;
			}
		}
	}
	cout << (ans ? "Yes" : "No") << endl;
	return 0;
}
