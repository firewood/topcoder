// B.

#include <iostream>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[]) {
	int x;
	cin >> x;
	int ans = 1;
	for (int i = 2; i <= x; ++i) {
		for (int j = i * i; j <= x; j *= i) {
			ans = max(ans, j);
		}
	}
	cout << ans << endl;
	return 0;
}
