// A.

#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

typedef long long LL;

int main(int argc, char* argv[]) {
	while (true) {
		LL h = -1, w = -1, a, b;
		cin >> h >> w >> a >> b;
		if (h <= 0 || w <= 0) break;
		for (int i = 0; i < h; ++i) {
			string s;
			if (i < b) {
				s = string(a, '0') + string(w - a, '1');
			} else {
				s = string(a, '1') + string(w - a, '0');

			}
			cout << s << endl;
		}
	}
	return 0;
}
