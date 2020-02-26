// B.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>

using namespace std;

int main(int argc, char *argv[]) {
	int n, k;
	cin >> n >> k;
	int ans = 0;
	while (n > 0) {
		++ans;
		n /= k;
	}
	cout << ans << endl;
	return 0;
}
