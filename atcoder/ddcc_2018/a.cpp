// A.

#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[]) {
	int n;
	cin >> n;
	long long ans = 1;
	for (int i = 0; i < n; ++i) {
		ans *= 4;
	}
	cout << ans << endl;
	return 0;
}
