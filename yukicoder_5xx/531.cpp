#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
	int n, m;
	cin >> n >> m;
	int ans = -1;
	if (m >= n) {
		ans = 1;
	} else if ((n % 2) == 0 && m >= n / 2) {
		ans = 2;
	}
	cout << ans << endl;
	return 0;
}
