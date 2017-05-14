#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[]) {
	int n;
	cin >> n;
	string s;
	if (!n) {
		s = "0";
	} else {
		while (n) {
			s += ('0' + n % 7);
			n /= 7;
		}
		reverse(s.begin(), s.end());
	}
	cout << s << endl;
	return 0;
}
