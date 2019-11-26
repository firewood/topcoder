// C.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

typedef long long LL;

int main(int argc, char* argv[]) {
	cout.precision(20);
#ifdef _MSC_VER
	while (true)
#endif
	{
		LL a, b, x = -1;
		cin >> a >> b >> x;
		if (x < 0) return 0;
		LL left = 0, right = 1000000001LL;
		while (right - left > 1) {
			LL mid = (right + left) / 2;
			LL cost = a * mid + b * to_string(mid).length();
			if (cost > x) {
				right = mid;
			} else {
				left = mid;
			}
		}
		cout << left << endl;
	}
	return 0;
}
