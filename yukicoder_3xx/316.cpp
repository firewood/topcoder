#include <iostream>
#include <sstream>

using namespace std;
typedef long long LL;

LL gcd(LL a, LL b) { return b ? gcd(b, a % b) : a; }
LL lcm(LL a, LL b) { return (a / gcd(a, b)) * b; }

int main(int argc, char *argv[])
{
	LL N, a, b, c;
	cin >> N >> a >> b >> c;
	LL ans = (N / a) + (N / b) + (N / c);
	ans -= (N / lcm(a, b) + N / lcm(b, c) + N / lcm(c, a));
	ans += N / lcm(a, lcm(b, c));
	cout << ans << endl;
	return 0;
}
