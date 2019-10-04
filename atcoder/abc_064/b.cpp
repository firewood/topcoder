// B.

#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[]) {
	int n, a, low = 1 << 30, high = 0;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a;
		low = min(low, a);
		high = max(high, a);
	}
	cout << (high - low) << endl;
	return 0;
}
