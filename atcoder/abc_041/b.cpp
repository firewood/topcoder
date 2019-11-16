// B.

#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[]) {
	long long a, b, c, ans, MOD = 1e9 + 7;
	cin >> a >> b >> c;
	ans = (a * b) % MOD;
	ans = (ans * c) % MOD;
	cout << ans << endl;
	return 0;
}
