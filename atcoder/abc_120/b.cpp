// B.

#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[]) {
	int a, b, k;
	cin >> a >> b >> k;
	for (int i = 100; ; --i) {
		if ((a % i) == 0 && (b % i) == 0) {
			if (--k == 0) {
				cout << i << endl;
				break;
			}
		}
	}
	return 0;
}
