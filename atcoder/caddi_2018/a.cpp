// A.

#include <iostream>
#include <sstream>

using namespace std;

int main(int argc, char *argv[]) {
	string n;
	cin >> n;
	int ans = 0;
	for (char c : n) {
		ans += c == '2';
	}
	cout << ans << endl;
	return 0;
}
