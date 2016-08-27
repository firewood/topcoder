#include <iostream>
#include <sstream>

using namespace std;

int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }

int main(int argc, char *argv[])
{
	int N, D;
	cin >> N >> D;
	D %= N;
	int ans = D > 0 ? (N / gcd(N, D) - 1) : 0;
	cout << ans << endl;
	return 0;
}
