// D.

#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;
typedef long long LL;

int main(int argc, char* argv[]) {
	LL x;
	cin >> x;
	for (LL a = -500; a <= 500; ++a) {
		for (LL b = -500; b <= 500; ++b) {
			if (a * a * a * a * a - b * b * b * b * b == x) {
				cout << a << " " << b << endl;
				return 0;
			}
		}
	}
	return 0;
}
