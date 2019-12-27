// C.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long LL;

LL gcd(LL a, LL b) { return b ? gcd(b, a % b) : a; }
LL lcm(LL a, LL b) { return (a / gcd(a, b)) * b; }

int main(int argc, char* argv[]) {
	LL a, b;
	cin >> a >> b;
	LL ans = lcm(a, b);
	cout << ans << endl;
	return 0;
}
