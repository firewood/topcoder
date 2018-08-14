// B.

#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[]) {
	int n;
	cin >> n;
	int s = 0;
	for (int x = n; x; x /= 10) {
		s += x % 10;
	}
	string ans = (n % s) ? "No" : "Yes";
	cout << ans << endl;
	return 0;
}
