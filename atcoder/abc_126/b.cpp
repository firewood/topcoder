// B.

#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[]) {
	int d;
	cin >> d;
	int a = d / 100, b = d % 100;
	bool yymm = b >= 1 && b <= 12;
	bool mmyy = a >= 1 && a <= 12;
	string ans = "NA";
	if (yymm && mmyy) {
		ans = "AMBIGUOUS";
	} else if (yymm) {
		ans = "YYMM";
	} else if (mmyy) {
		ans = "MMYY";
	}
	cout << ans << endl;
	return 0;
}
