// A.

#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
	int a, b;
	cin >> a >> b;
	int ans = a + b;
	if (ans >= 10) {
		cout << "error" << endl;
	} else {
		cout << ans << endl;
	}
	return 0;
}
