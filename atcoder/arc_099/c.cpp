// C.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <set>
#include <vector>

using namespace std;

int main(int argc, char *argv[]) {
	int n, k;
	cin >> n >> k;
	int pos = k, ans = 1;
	while (pos < n) {
		pos += k - 1;
		++ans;
	}
	cout << ans << endl;
	return 0;
}
