// B.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>

using namespace std;

int main(int argc, char *argv[]) {
	int n;
	cin >> n;
	int ans = -1;
	for (int i = 1; i <= 50000; ++i) {
		int x = (int)(i * 1.08);
		if (x == n) {
			ans = i;
			cout << i << endl;
			break;
		}
	}
	if (ans < 0) {
		cout << ":(" << endl;
	}
	return 0;
}
