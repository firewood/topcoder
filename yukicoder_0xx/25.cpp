#include <iostream>
#include <algorithm>
#include <numeric>
#include <sstream>
#include <set>
#include <vector>

using namespace std;
typedef long long LL;

LL gcd(LL a, LL b) { return b ? gcd(b, a % b) : a; }

int main(int argc, char *argv[]) {
	LL N, M;
	string s;
	getline(cin, s);
	stringstream sa(s);
	sa >> N;
	getline(cin, s);
	stringstream sb(s);
	sb >> M;
	LL g = gcd(N, M);
	LL a = N / g, b = M / g;
	while ((a % 10) == 0) {
		a /= 10;
	}
	a = a % 10;
	while ((b % 2) == 0) {
		a = (a * 5) % 10;
		b /= 2;
	}
	while ((b % 5) == 0) {
		a = (a * 2) % 10;
		b /= 5;
	}
	LL ans = b == 1 ? a : -1;
	cout << ans << endl;
	return 0;
}
