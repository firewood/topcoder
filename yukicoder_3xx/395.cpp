#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
	int X;
	cin >> X;
	int ans = -1;
	X -= 7;
	if (X >= 8) {
		ans = X;
	}
	cout << ans << endl;
	return 0;
}
