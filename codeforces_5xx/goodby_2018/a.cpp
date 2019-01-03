// A.

#include <iostream>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[]) {
	int a, b, c;
	cin >> a >> b >> c;
	int x = min({ a, b - 1, c - 2 });
	int ans = x * 3 + 3;
	cout << ans << endl;
	return 0;
}
