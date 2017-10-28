// C.

#include <iostream>
#include <vector>

using namespace std;

typedef long long LL;

LL gcd(LL a, LL b) { return b ? gcd(b, a % b) : a; }

int main(int argc, char *argv[])
{
	int n;
	cin >> n;
	LL ans = 1, t;
	for (int i = 0; i < n; ++i) {
		cin >> t;
		ans = (ans / gcd(ans, t)) * t;
	}
	cout << ans << endl;
	return 0;
}
