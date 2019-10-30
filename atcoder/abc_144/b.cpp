// B.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>

using namespace std;

int main(int argc, char *argv[]) {
	int n;
	cin >> n;
	string ans = "No";
	for (int a = 1; a <= 9; ++a) {
		for (int b = 1; b <= 9; ++b) {
			if (a * b == n) {
				ans = "Yes";
			}
		}
	}
	cout << ans << endl;
	return 0;
}
