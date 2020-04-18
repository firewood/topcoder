// B.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <numeric>
#include <vector>

using namespace std;

int main(int argc, char *argv[]) {
	int n;
	cin >> n;
	long long ans = 0;
	for (int i = 0; i <= n; ++i) {
		if ((i % 3) != 0 && (i % 5) != 0) {
			ans += i;
		}
	}
	cout << ans << endl;
	return 0;
}
