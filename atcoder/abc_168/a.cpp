// A.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
	int n;
	cin >> n;
	string ans;
	switch (n % 10) {
	case 0:
	case 1:
	case 6:
	case 8:
		ans = "pon";
		break;
	case 2:
	case 4:
	case 5:
	case 7:
	case 9:
		ans = "hon";
		break;
	default:
		ans = "bon";
		break;
	}
	cout << ans << endl;
	return 0;
}
