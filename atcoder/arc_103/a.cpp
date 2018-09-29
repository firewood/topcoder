// A.

#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[]) {
	string n;
	cin >> n;
	int ans = 0;
	for (char c : n) {
		ans = ans * 10 + (c == '1' ? 9 : 1);
	}
	cout << ans << endl;
	return 0;
}
