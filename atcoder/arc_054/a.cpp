// A. 

#include <iostream>
#include <algorithm>
#include <sstream>
#include <cstdio>
#include <cstring>

using namespace std;

int main(int argc, char *argv[])
{
	cout.precision(10);
	double L, X, Y, S, D, ans;
	cin >> L >> X >> Y >> S >> D;
	if (S <= D) {
		ans = (D - S) / (X + Y);
		if (Y > X) {
			ans = min(ans, (L - (D - S)) / (Y - X));
		}
	} else {
		ans = (L - (S - D)) / (X + Y);
		if (Y > X) {
			ans = min(ans, (S - D) / (Y - X));
		}
	}
	cout << ans << endl;
	return 0;
}
