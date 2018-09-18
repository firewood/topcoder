// C.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>

using namespace std;

int main(int argc, char *argv[]) {
	int n;
	cin >> n;
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		int a;
		cin >> a;
		ans += a - 1;
	}
	cout << ans << endl;
	return 0;
}
