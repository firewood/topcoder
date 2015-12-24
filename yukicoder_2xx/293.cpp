#include <iostream>
#include <sstream>

using namespace std;

int main(int argc, char *argv[]) {
	string a, b;
	cin >> a >> b;
	string ans = a;
	if (a.length() < b.length()) {
		ans = b;
	} else if (a.length() == b.length()) {
		for (int i = 0; i != a.length(); ++i) {
			if (a[i] == '4' && b[i] == '7') {
				break;
			} else if (a[i] == '7' && b[i] == '4') {
				ans = b;
				break;
			} else if (a[i] > b[i]) {
				break;
			} else if (a[i] < b[i]) {
				ans = b;
				break;
			}
		}
	}
	cout << ans << endl;
	return 0;
}
